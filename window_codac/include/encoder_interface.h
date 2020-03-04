//
// Created Tapeswar Puhan
//

#ifndef MP3ENCODER_ENCODER_INTERFACE_H
#define MP3ENCODER_ENCODER_INTERFACE_H
#include <browser/wav_browser.h>
#include <encoder/lame_encoder.h>
#include <encoder/mp3_encoder.h>
#include <encoder_core.h>

namespace encoder
{

struct EncoderInterface final
{
    EncoderInterface() = default;
    ~EncoderInterface() = default;
    EncoderInterface(const EncoderInterface&) = delete;
    EncoderInterface& operator=(const EncoderInterface&) = delete;
    /*
     * This is the interface function to encode wave to mp3 files available in
     * user input directory and place in output directory
     */
    void EncodeWaveToMp3(const DirectoryName& input_directory_path, const DirectoryName& output_directory_path);
};
}  // namespace encoder

#endif  // MP3ENCODER_ENCODER_INTERFACE_H
