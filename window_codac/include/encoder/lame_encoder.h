//
// Created by gl-273 on 2/15/20.
//

#ifndef MP3ENCODER_LAME_ENCODER_H
#define MP3ENCODER_LAME_ENCODER_H

#include <helper/task_pool.h>
#include <encoder/i_encoder.h>
namespace encoder
{
    class LameEncoder final : public IEncoder
    {
    public:
        explicit LameEncoder(const DirectoryName& output_directory_path);
        ~LameEncoder()= default;

    private:
        void EncodeMediaFile(MediaFileName&& media_file_path) override;
        void RegisterUpdateInformation(UpdateInformation&& information_handler)noexcept override ;
        IEncoder::Ptr Clone() override ;
        IEncoder::Ptr Create() override ;

        void UpdateEncodeStatus(std::string&& information);
        DirectoryName output_directory_path_;
        UpdateInformation information_handler_{nullptr};
    };
}
#endif //MP3ENCODER_LAME_ENCODER_H
