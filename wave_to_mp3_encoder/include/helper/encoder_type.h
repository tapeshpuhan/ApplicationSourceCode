//
// Created by gl-273 on 2/13/20.
//

#ifndef MP3ENCODER_ENCODER_TYPE_H
#define MP3ENCODER_ENCODER_TYPE_H

#include <algorithm>
#include <functional>
#include <memory>
#include <vector>
#include <helper/logger.h>
namespace encoder
{
namespace FileExtensionFilter
{
const std::string WavFile{".wav"};
};

enum class EndOfFileStatus : std::int8_t
{
    ScanInProgress,
    NoFileAvailable,
    EndOfFileReached
};

enum class EncoderStatus : std::int8_t
{
    EncodeInProgress,
    EncodeFinished,
    InvalidHeader,
    EncodeFailed,
};

using DirectoryName = std::string;
using MediaFileName = std::string;
using MediaFileList = std::vector<MediaFileName>;
using UpdateMediaFilesHandler = std::function<void(MediaFileList&&, const EndOfFileStatus&)>;
using UpdateInformation = std::function<void(const EncoderStatus&)>;
}  // namespace encoder
#endif  // MP3ENCODER_ENCODER_TYPE_H
