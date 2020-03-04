//
// Created Tapeswar Puhan
//

#ifndef MP3ENCODER_MP3_ENCODER_H
#define MP3ENCODER_MP3_ENCODER_H

#include <encoder/i_encoder.h>

namespace encoder
{
class Mp3Encoder final
{
  public:
    explicit Mp3Encoder(const std::shared_ptr<IEncoder> encoder);
    Mp3Encoder(Mp3Encoder&) = delete;
    Mp3Encoder& operator=(Mp3Encoder&) = delete;
    ~Mp3Encoder();

    void InitializeEncoder();
    void EncodeMediaFiles(MediaFileName&& media_file_list) noexcept;

    using ConstPtr = const std::shared_ptr<Mp3Encoder>;
    using Ptr = std::shared_ptr<Mp3Encoder>;

  private:
    void ReceivedEncoderInformation(const EncoderStatus& information);
    std::shared_ptr<IEncoder> encoder_;
};
}  // namespace encoder
#endif  // MP3ENCODER_MP3_ENCODER_H
