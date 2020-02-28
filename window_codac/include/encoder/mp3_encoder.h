//
// Created by gl-273 on 2/15/20.
//

#ifndef MP3ENCODER_MP3_ENCODER_H
#define MP3ENCODER_MP3_ENCODER_H

#include <encoder/i_encoder.h>
#include <helper/task_pool.h>

namespace encoder
{
    constexpr std::int8_t MAX_NUMBER_TASK{10};

    class Mp3Encoder final
    {
        public:
        explicit Mp3Encoder(const std::shared_ptr<IEncoder> encoder);
        Mp3Encoder(Mp3Encoder&)= delete;
        Mp3Encoder&operator = (Mp3Encoder&)= delete;
        ~Mp3Encoder()= default;

        void InitializeEncoder();
        void EncodeMediaFiles(MediaFileList&& media_file_list,const EndOfFileStatus& eof_status);

        using ConstPtr = const std::shared_ptr<Mp3Encoder>;
        using Ptr = std::shared_ptr<Mp3Encoder>;

    private:
        using SafeQueueFormediaFile = SafeQueue<MediaFileName>;
        using SafeQueueFormediaFilePtr = std::unique_ptr<SafeQueueFormediaFile>;
        using TaskPoolForMediaFile = TaskPool<MediaFileName>;
        using TaskPoolForMediaFilePtr = std::unique_ptr<TaskPoolForMediaFile>; 

        void ReceivedEncoderInformation(std::string&& information);
        void CreatePollingThread();
        void HandelPollingThread();
        void EncodeMp3File(MediaFileName&& media_file_name);
        void ShutDownTaskPool();

        std::shared_ptr<IEncoder> encoder_;
        SafeQueueFormediaFilePtr media_file_safe_queue_;
        TaskPoolForMediaFilePtr task_pool_;
        std::atomic<EndOfFileStatus> eof_file_status_{EndOfFileStatus::ScanInProgress};
    };
}
#endif //MP3ENCODER_MP3_ENCODER_H
