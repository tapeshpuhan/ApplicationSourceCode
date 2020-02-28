//
// Created by gl-273 on 2/15/20.
//
#include <encoder/mp3_encoder.h>
#include <helper/logger.h>

namespace encoder
{
    Mp3Encoder::Mp3Encoder(const std::shared_ptr<IEncoder> encoder):encoder_{encoder},
                    media_file_safe_queue_{std::make_unique<SafeQueueFormediaFile>()},
                    task_pool_{std::make_unique<TaskPoolForMediaFile>(MAX_NUMBER_TASK)}
    {

    }

    void Mp3Encoder::InitializeEncoder()
    {
        auto LoggingInformationCallback = [this](auto&& information)
                                            {
                                                this->ReceivedEncoderInformation(std::forward<std::string>(information));
                                            };
        encoder_->RegisterUpdateInformation(LoggingInformationCallback);
        CreatePollingThread();
    }

    void Mp3Encoder::EncodeMediaFiles(MediaFileList&& media_file_list, const EndOfFileStatus& eof_status)
    {
        //std::for_each(begin(media_file_list),end(media_file_list),[](const auto& file_name){Logger::LogInfo(file_name);});
        Logger::LogInfo(static_cast<std::int32_t>(eof_status));
        media_file_safe_queue_->Push(media_file_list);
        eof_file_status_.store(eof_status);
    }

    void Mp3Encoder::ReceivedEncoderInformation(std::string&& information)
    {
        Logger::LogInfo(information);
    }

    void Mp3Encoder::CreatePollingThread()
    {
        std::thread polling_thread{[this](){
            HandelPollingThread();
        }};

        if(polling_thread.joinable())
        {
            polling_thread.detach();
        }
    }
    
    void Mp3Encoder::HandelPollingThread()
    {
        while(eof_file_status_.load() != EndOfFileStatus::EndOfFileReached)
        {
            auto encode_to_mp3_file_callback = [this](MediaFileName&& media_file_name,
                                                      const size_t /*thread_id*/)
                                           {
                                               EncodeMp3File(std::forward<MediaFileName>(media_file_name));
                                           };
            task_pool_->AddTask(std::move(media_file_safe_queue_->Pop()),
                                encode_to_mp3_file_callback);
        }
        ShutDownTaskPool();
    }

    void Mp3Encoder::EncodeMp3File(MediaFileName&& media_file_name)
    {
        Logger::LogInfo(media_file_name);
        auto new_encoder = encoder_->Clone();
        new_encoder->EncodeMediaFile(std::forward<MediaFileName>(media_file_name));
    }

    void Mp3Encoder::ShutDownTaskPool()
    {
        task_pool_->ShutDown();
    }
}
