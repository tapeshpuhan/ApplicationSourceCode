//
// Created by Tapeswar Puhan
//
#include <encoder/mp3_encoder.h>
#include <helper/logger.h>

namespace encoder
{
Mp3Encoder::Mp3Encoder(const std::shared_ptr<IEncoder> encoder) : encoder_{encoder} {}

Mp3Encoder::~Mp3Encoder() {}
void Mp3Encoder::InitializeEncoder()
{
    auto LoggingInformationCallback = [this](const auto& information) { ReceivedEncoderInformation(information); };
    encoder_->RegisterUpdateInformation(LoggingInformationCallback);
}

void Mp3Encoder::EncodeMediaFiles(MediaFileName&& media_file_list) noexcept
{
    auto new_encoder = encoder_->Create();
    new_encoder->EncodeMediaFile(std::forward<MediaFileName>(media_file_list));
}

void Mp3Encoder::ReceivedEncoderInformation(const EncoderStatus& information)
{
    Logger::LogInfo("Recived Encoder Status: ", static_cast<int32_t>(information));
}
}  // namespace encoder
