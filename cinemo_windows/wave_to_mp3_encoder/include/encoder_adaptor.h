//
// Created Tapeswar Puhan
//

#ifndef MP3ENCODER_ENCODER_ADAPTOR_H
#define MP3ENCODER_ENCODER_ADAPTOR_H
#include <browser/wav_browser.h>
#include <encoder/mp3_encoder.h>
#include <encoder_core.h>
namespace encoder
{
template class EncoderCore<WavBrowser, Mp3Encoder>;
}

#endif  // MP3ENCODER_ENCODER_ADAPTOR_H
