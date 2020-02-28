//
// Created by gl-273 on 2/13/20.
//

#ifndef MP3ENCODER_ENCODER_TYPE_H
#define MP3ENCODER_ENCODER_TYPE_H

#include <vector>
#include <functional>
#include <memory>
#include <helper/logger.h>
#include <algorithm>
namespace encoder
{
    namespace FileExtensionFilter
    {
        const std::string WavFile {".wav"};
    };

    enum class EndOfFileStatus : std::int8_t
    {
        ScanInProgress,
        EndOfFileReached
    };

    using DirectoryName = std::string;
    using MediaFileName = std::string;
    using MediaFileList = std::vector<MediaFileName>;
    using UpdateMediaFilesHandler = std::function<void(MediaFileList&&,const EndOfFileStatus&)>;
    using UpdateInformation = std::function<void(std::string&&)>;
}
#endif //MP3ENCODER_ENCODER_TYPE_H
