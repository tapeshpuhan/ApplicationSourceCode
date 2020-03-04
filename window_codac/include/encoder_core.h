//
// Created Tapeswar Puhan
//

#ifndef MP3ENCODER_ENCODER_CORE_H
#define MP3ENCODER_ENCODER_CORE_H
#include <string>
#include <encoder/i_encoder.h>
#include <helper/encoder_type.h>
#include <helper/task_pool.h>
namespace encoder
{

constexpr std::int8_t MAX_NUMBER_TASK{10};
constexpr std::int64_t MAX_BUFFER_SIZE{100};
constexpr std::int64_t THRESHOLD_BUFFER_SIZE{90};

template <typename MediaBrowser, typename MediaEncoder>
class EncoderCore final
{
  public:
    explicit EncoderCore(const DirectoryName& input_directory_path, const std::shared_ptr<IEncoder> encoder);
    ~EncoderCore();
    EncoderCore(EncoderCore&) = delete;
    EncoderCore& operator=(EncoderCore&) = delete;

    void InitializeCore();

  private:
    using SafeQueueFormediaFile = SafeQueue<MediaFileName>;
    using SafeQueueFormediaFilePtr = std::unique_ptr<SafeQueueFormediaFile>;
    using TaskPoolForMediaFile = TaskPool<MediaFileName>;
    using TaskPoolForMediaFilePtr = std::unique_ptr<TaskPoolForMediaFile>;

    void EncodeMediaFiles(MediaFileList&& media_file_list, const EndOfFileStatus& eof_status);
    void CreatePollingThread();
    void HandelPollingThread();
    void EncodeMediaFile(MediaFileName&& media_file_name);
    void ShutDownTaskPool();
    void ValidateAllFilesEncoded();
    void ValidateBufferSize();
    EncoderStatus GetEncoderStatusDone();
    void SetFinishedStatus();

    typename MediaBrowser::ConstPtr media_browser_;
    typename MediaEncoder::ConstPtr media_encoder_;
    SafeQueueFormediaFilePtr media_file_safe_queue_;
    TaskPoolForMediaFilePtr task_pool_;
    std::atomic<EndOfFileStatus> eof_file_status_{EndOfFileStatus::ScanInProgress};
    std::promise<EncoderStatus> get_encoder_status_{};
    std::atomic<size_t> number_of_files_to_encode_{0};
    std::atomic<size_t> number_of_files_encode_finished_{0};
    std::condition_variable condition_to_push_;
    std::mutex lock_buffer_;
    std::atomic_bool shut_down_{true};
};

}  // namespace encoder
#endif  // MP3ENCODER_ENCODER_CORE_H
