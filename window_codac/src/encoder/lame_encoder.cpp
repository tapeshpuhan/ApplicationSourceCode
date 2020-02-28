//
// Created by gl-273 on 2/15/20.
//

#include <encoder/lame_encoder.h>
#include <helper/logger.h>
namespace encoder
{

    LameEncoder::LameEncoder(const DirectoryName& output_directory_path):output_directory_path_{output_directory_path}
    {

    }

    void LameEncoder::EncodeMediaFile(MediaFileName&& media_file_path)
    {
        Logger::LogInfo("Encode File By Lame Encoder", media_file_path);
    }

    void LameEncoder::RegisterUpdateInformation(UpdateInformation&& information_handler)noexcept
    {
        information_handler_ = std::move(information_handler);
    }

    void LameEncoder::UpdateEncodeStatus(std::string&& information)
    {
        if(information_handler_)
        {
            information_handler_(std::forward<std::string>(information));
        }
    }

    IEncoder::Ptr LameEncoder::Clone()
    {
        return std::make_shared<LameEncoder>(*this);
    }

    IEncoder::Ptr LameEncoder::Create()
    {
        return std::make_shared<LameEncoder>(output_directory_path_);
    }
}