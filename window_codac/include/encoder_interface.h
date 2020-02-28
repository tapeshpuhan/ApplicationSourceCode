//
// Created by Tapeswar on 2/13/20.
//

#ifndef MP3ENCODER_ENCODER_INTERFACE_H
#define MP3ENCODER_ENCODER_INTERFACE_H
#include <encoder_core.h>
#include <browser/wav_browser.h>
#include <encoder/mp3_encoder.h>
#include <encoder/lame_encoder.h>

namespace encoder
{

    struct EncoderInterface final
    {
        EncoderInterface() = default;
        ~EncoderInterface() = default;
        EncoderInterface(const EncoderInterface&) = delete;
        EncoderInterface&operator =(const EncoderInterface&) = delete;
        /*
         * This is the interface function to encode wma to mp3 files available in
         * user input directory and place in output directory
         */
        void EncodeWmaToMp3(const DirectoryName &input_directory_path, const DirectoryName &output_directory_path);
    };
}

#endif //MP3ENCODER_ENCODER_INTERFACE_H
