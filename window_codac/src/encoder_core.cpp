//
// Created Tapeswar Puhan
//

#include <encoder_adaptor.h>
#include <encoder_core.h>
namespace encoder
{
template <typename MediaBrowser, typename MediaEncoder>
EncoderCore<MediaBrowser, MediaEncoder>::EncoderCore(const DirectoryName& input_directory_path,
                                                     const std::shared_ptr<IEncoder> encoder)
    : media_browser_{std::make_shared<MediaBrowser>(input_directory_path)},
      media_encoder_{std::make_shared<MediaEncoder>(encoder)},
      media_file_safe_queue_{std::make_unique<SafeQueueFormediaFile>()},
      task_pool_{std::make_unique<TaskPoolForMediaFile>(MAX_NUMBER_TASK)}
{
    CreatePollingThread();
}

template <typename MediaBrowser, typename MediaEncoder>
EncoderCore<MediaBrowser, MediaEncoder>::~EncoderCore()
{
    ShutDownTaskPool();
}

template <typename MediaBrowser, typename MediaEncoder>
void EncoderCore<MediaBrowser, MediaEncoder>::InitializeCore()
{
    auto MediaFileListAndEndOfFileInfoCallback = [this](auto&& media_file_list, const EndOfFileStatus& eof_status) {
        this->EncodeMediaFiles(std::forward<MediaFileList>(media_file_list), eof_status);
    };
    media_browser_->RegisterForMediaFileUpdates(MediaFileListAndEndOfFileInfoCallback);
    media_encoder_->InitializeEncoder();
    media_browser_->InitializeBrowser();
    auto status = GetEncoderStatusDone();
    Logger::LogInfo(" Encoding Status is : ", static_cast<std::int32_t>(status));
}

template <typename MediaBrowser, typename MediaEncoder>
void EncoderCore<MediaBrowser, MediaEncoder>::EncodeMediaFiles(MediaFileList&& media_file_list,
                                                               const EndOfFileStatus& eof_status)
{
    if (eof_status != EndOfFileStatus::NoFileAvailable)
    {
        std::unique_lock<std::mutex> lock(lock_buffer_);
        condition_to_push_.wait(lock, [this] { return media_file_safe_queue_->Size() < MAX_BUFFER_SIZE; });
        number_of_files_to_encode_ += media_file_list.size();
        media_file_safe_queue_->Push(media_file_list);
        eof_file_status_.store(eof_status);
    }
    else
    {
        SetFinishedStatus();
    }
}

template <typename MediaBrowser, typename MediaEncoder>
void EncoderCore<MediaBrowser, MediaEncoder>::CreatePollingThread()
{
    std::thread polling_thread{[this]() { HandelPollingThread(); }};

    if (polling_thread.joinable())
    {
        polling_thread.detach();
    }
}

template <typename MediaBrowser, typename MediaEncoder>
void EncoderCore<MediaBrowser, MediaEncoder>::HandelPollingThread()
{
    while(shut_down_.load())
    {
        auto encode_to_mp3_file_callback = [this](MediaFileName&& media_file_name, const size_t /*thread_id*/) {
            EncodeMediaFile(std::forward<MediaFileName>(media_file_name));
            number_of_files_encode_finished_++;
            ValidateAllFilesEncoded();
            Logger::LogInfo("thread id  ::",
                            std::this_thread::get_id(),
                            " : ",
                            static_cast<size_t>(number_of_files_encode_finished_.load()));
        };
        if (media_file_safe_queue_->IsEmpty() == false)
        {
            auto message = media_file_safe_queue_->Pop();
            if (message.second)
            {
                task_pool_->AddTask(std::move(message.first), encode_to_mp3_file_callback);
            }
        }
        ValidateBufferSize();
    }
}

template <typename MediaBrowser, typename MediaEncoder>
void EncoderCore<MediaBrowser, MediaEncoder>::EncodeMediaFile(MediaFileName&& media_file_name)
{
    media_encoder_->EncodeMediaFiles(std::forward<MediaFileName>(media_file_name));
}

template <typename MediaBrowser, typename MediaEncoder>
void EncoderCore<MediaBrowser, MediaEncoder>::ShutDownTaskPool()
{
    task_pool_->ShutDown();
}

template <typename MediaBrowser, typename MediaEncoder>
EncoderStatus EncoderCore<MediaBrowser, MediaEncoder>::GetEncoderStatusDone()
{
    return get_encoder_status_.get_future().get();
}

template <typename MediaBrowser, typename MediaEncoder>
void EncoderCore<MediaBrowser, MediaEncoder>::ValidateAllFilesEncoded()
{
    if ((number_of_files_to_encode_ == number_of_files_encode_finished_) &&
        (eof_file_status_ == EndOfFileStatus::EndOfFileReached))
    {
		shut_down_.store(false);
		std::this_thread::yield();
        try
        {
            SetFinishedStatus();
        }
        catch (const std::future_error& exception)
        {
            Logger::LogError(" Exception in future", exception.what());
        }
        
    }
}

template <typename MediaBrowser, typename MediaEncoder>
void EncoderCore<MediaBrowser, MediaEncoder>::SetFinishedStatus()
{
    get_encoder_status_.set_value(EncoderStatus::EncodeFinished);
}

template <typename MediaBrowser, typename MediaEncoder>
void EncoderCore<MediaBrowser, MediaEncoder>::ValidateBufferSize()
{
    if ((media_file_safe_queue_->Size() > THRESHOLD_BUFFER_SIZE) && (media_file_safe_queue_->Size() < MAX_BUFFER_SIZE))
    {
        std::unique_lock<std::mutex> lock(lock_buffer_);
        lock.unlock();
        condition_to_push_.notify_one();
    }
}

}  // namespace encoder
