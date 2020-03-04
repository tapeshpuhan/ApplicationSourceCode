//
// Created Tapeswar Puhan
//

#ifndef MP3ENCODER_I_ENCODER_H
#define MP3ENCODER_I_ENCODER_H
#include <memory>
#include <helper/encoder_type.h>

namespace encoder
{
struct IEncoder
{
    using Ptr = std::shared_ptr<IEncoder>;

    IEncoder() = default;
    void EncodeMediaFile(MediaFileName&& file_name) noexcept
    {
        EncodeMediaFileImplement(std::forward<MediaFileName>(file_name));
    }
    void RegisterUpdateInformation(UpdateInformation&& update_info) noexcept
    {
        RegisterUpdateInformationImplement(std::forward<UpdateInformation>(update_info));
    }
    virtual IEncoder::Ptr Create() { return CreateImplement(); }
    virtual ~IEncoder() = default;

  private:
    virtual void EncodeMediaFileImplement(MediaFileName&&) noexcept = 0;
    virtual void RegisterUpdateInformationImplement(UpdateInformation&&) = 0;

    virtual IEncoder::Ptr CreateImplement() = 0;
};
}  // namespace encoder
#endif  // MP3ENCODER_I_ENCODER_H
