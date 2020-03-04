//
// Created Tapeswar Puhan
//

#include <encoder_interface.h>

namespace encoder
{
void EncoderInterface::EncodeWaveToMp3(const DirectoryName& input_directory_path,
                                       const DirectoryName& output_directory_path)
{
    std::unique_ptr<EncoderCore<WavBrowser, Mp3Encoder>> wave_to_mp3_encoder =
        std::make_unique<EncoderCore<WavBrowser, Mp3Encoder>>(input_directory_path,
                                                              std::make_shared<LameEncoder>(output_directory_path));
    wave_to_mp3_encoder->InitializeCore();
}
}  // namespace encoder