//
// Created Tapeswar Puhan
//

#ifndef MP3ENCODER_WAV_HEADER_H
#define MP3ENCODER_WAV_HEADER_H
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
namespace encoder
{

constexpr std::int8_t NO_OF_BIT_PER_BYTE{8};
enum class WavByteNumber : std::int32_t
{
    StartRiff = 0,
    EndRiff = 3,
    StartFilesize = 4,
    EndFilesize = 7,
    StartWave = 8,
    EndWave = 11,
    StartFormat = 12,
    EndFormat = 15,
    StartLengthOfFormat = 16,
    EndLengthOfFormat = 19,
    StartTypeOfFormat = 20,
    EndTypeOfFormat = 21,
    StartNumberOfChannels = 22,
    EndNumberOfChannels = 23,
    StartSampleRate = 24,
    EndSampleRate = 27,
    StartByteRate = 28,
    EndByteRate = 31,
    StartBlockAlign = 32,
    EndBlockAlign = 33,
    StartBitsPerSample = 34,
    EndBitsPerSample = 35,
    StartDataChunkHeader = 36,
    EndDataChunkHeader = 39,
    StartDataSize = 40,
    EndDataSize = 43,
    EndOfHeader = 44,
};

struct WavHeader
{
    std::string riff;              /*Position 1-4*/
    std::int32_t file_size;        /*Position 5-8*/
    std::string wave_name;         /*Position 9-12*/
    std::string format;            /*Position 13-16*/
    std::int32_t length_of_format; /*Position 17-20*/
    std::int16_t type_of_format;   /*Position 21-22*/
    std::uint16_t num_channels;    /*Position 23-24*/
    std::uint32_t sample_rate;     /*Position 25-28*/
    std::uint32_t byterate;        /*Position 29-32*/
    std::int16_t block_align;      /*Block Assigned 33-34*/
    std::int16_t bits_per_sample;  /*35-36*/
    std::string data_chunk_header; /*37 - 40*/
    std::int32_t data_size;        /* 41 - 44*/
    bool is_valid_header;

    WavHeader(const std::string& file_path);
    std::string GetHeaderString();

  private:
    void Init(const std::string& file_path);
    std::vector<char> GetHeaderBuffer(const std::string& file_path);
    std::string GetRiff(const std::vector<char>& buffer);
    std::int32_t GetFileSize(const std::vector<char>& buffer);
    std::string GetWav(const std::vector<char>& buffer);
    std::string GetFormat(const std::vector<char>& buffer);
    std::int32_t GetLengthOfFormat(const std::vector<char>& buffer);
    std::int16_t GetTypeOfFormat(const std::vector<char>& buffer);
    std::uint16_t GetNumberOfChannel(const std::vector<char>& buffer);
    std::uint32_t GetSampleRate(const std::vector<char>& buffer);
    std::uint32_t GetByteRate(const std::vector<char>& buffer);
    std::int16_t BlockAlign(const std::vector<char>& buffer);
    std::int16_t BitsPerSample(const std::vector<char>& buffer);
    std::string GetDataChunkHeader(const std::vector<char>& buffer);
    std::int32_t GetDataSize(const std::vector<char>& buffer);
    bool IsValidHeader(const std::string& riff, const std::string& wave);
    auto GetByteInfo(const std::vector<char>& buffer, const WavByteNumber start, const WavByteNumber end);
};
}  // namespace encoder
#endif  // MP3ENCODER_WAV_HEADER_H
