//
// Created by Tapeswar Puhan
//

#include <encoder/wav_header.h>
namespace encoder
{

auto WavHeader::GetByteInfo(const std::vector<char>& buffer, const WavByteNumber start, const WavByteNumber end)
{
    size_t start_local = static_cast<size_t>(start);
    size_t end_local = static_cast<size_t>(end);
    size_t diffrence = end_local - start_local + 1;
    constexpr std::int8_t UINT_8{2};
    constexpr std::int8_t UINT_16{4};

    switch (diffrence)
    {
        case UINT_8:
        {
            std::int32_t byte_data_16{0};
            size_t count_to_shift{0};

            std::for_each(begin(buffer) + start_local, begin(buffer) + end_local + 1, [&](const auto& element) {
                auto shift_value = (0xFF & element);
                byte_data_16 |= static_cast<std::int32_t>(shift_value << (NO_OF_BIT_PER_BYTE * count_to_shift));
                count_to_shift++;
            });
            return byte_data_16;
        }
        case UINT_16:
        {
            std::int32_t byte_data_32{0};
            size_t count_to_shift{0};

            std::for_each(begin(buffer) + start_local, begin(buffer) + end_local + 1, [&](const auto& element) {
                auto shift_value = (0xFF & element);
                byte_data_32 |= static_cast<std::int32_t>(shift_value << (NO_OF_BIT_PER_BYTE * count_to_shift));
                count_to_shift++;
            });
            return byte_data_32;
        }
        default:
            break;
    }
    return 0;
}

WavHeader::WavHeader(const std::string& file_path)
{
    Init(file_path);
}

void WavHeader::Init(const std::string& file_path)
{
    const auto& buffer = GetHeaderBuffer(file_path);

    riff = GetRiff(buffer);
    wave_name = GetWav(buffer);
    is_valid_header = IsValidHeader(riff, wave_name);
    if (is_valid_header)
    {
        file_size = GetFileSize(buffer);
        format = GetFormat(buffer);
        length_of_format = GetLengthOfFormat(buffer);
        type_of_format = GetTypeOfFormat(buffer);
        num_channels = GetNumberOfChannel(buffer);
        sample_rate = GetSampleRate(buffer);
        byterate = GetByteRate(buffer);
        block_align = BlockAlign(buffer);
        bits_per_sample = BitsPerSample(buffer);
        data_chunk_header = GetDataChunkHeader(buffer);
        data_size = GetDataSize(buffer);
    }
}
std::vector<char> WavHeader::GetHeaderBuffer(const std::string& file_path)
{
    std::ifstream in_file(file_path, std::ifstream::in);
    std::vector<char> contents(static_cast<size_t>(WavByteNumber::EndOfHeader));

    std::copy_n(
        std::istreambuf_iterator<char>(in_file), static_cast<size_t>(WavByteNumber::EndOfHeader), contents.begin());
    return contents;
}

std::string WavHeader::GetRiff(const std::vector<char>& buffer)
{
    std::string riff;

    std::copy(begin(buffer) + static_cast<size_t>(WavByteNumber::StartRiff),
              begin(buffer) + static_cast<size_t>(WavByteNumber::EndRiff) + 1,
              std::back_inserter(riff));
    return riff;
}

std::int32_t WavHeader::GetFileSize(const std::vector<char>& buffer)
{
    return GetByteInfo(buffer, WavByteNumber::StartFilesize, WavByteNumber::EndFilesize);
}

std::string WavHeader::GetWav(const std::vector<char>& buffer)
{
    std::string wave;

    std::copy(begin(buffer) + static_cast<size_t>(WavByteNumber::StartWave),
              begin(buffer) + static_cast<size_t>(WavByteNumber::EndWave) + 1,
              std::back_inserter(wave));
    return wave;
}

std::string WavHeader::GetFormat(const std::vector<char>& buffer)
{
    std::string format;

    std::copy(begin(buffer) + static_cast<size_t>(WavByteNumber::StartFormat),
              begin(buffer) + static_cast<size_t>(WavByteNumber::EndFormat) + 1,
              std::back_inserter(format));
    return format;
}

std::int32_t WavHeader::GetLengthOfFormat(const std::vector<char>& buffer)
{
    return GetByteInfo(buffer, WavByteNumber::StartLengthOfFormat, WavByteNumber::EndLengthOfFormat);
}
std::int16_t WavHeader::GetTypeOfFormat(const std::vector<char>& buffer)
{
    return GetByteInfo(buffer, WavByteNumber::StartTypeOfFormat, WavByteNumber::EndTypeOfFormat);
}

std::uint16_t WavHeader::GetNumberOfChannel(const std::vector<char>& buffer)
{
    return GetByteInfo(buffer, WavByteNumber::StartNumberOfChannels, WavByteNumber::EndNumberOfChannels);
}

std::uint32_t WavHeader::GetSampleRate(const std::vector<char>& buffer)
{
    return GetByteInfo(buffer, WavByteNumber::StartSampleRate, WavByteNumber::EndSampleRate);
}

std::uint32_t WavHeader::GetByteRate(const std::vector<char>& buffer)
{
    return GetByteInfo(buffer, WavByteNumber::StartByteRate, WavByteNumber::EndByteRate);
}

std::int16_t WavHeader::BlockAlign(const std::vector<char>& buffer)
{
    return GetByteInfo(buffer, WavByteNumber::StartBlockAlign, WavByteNumber::EndBlockAlign);
}

std::int16_t WavHeader::BitsPerSample(const std::vector<char>& buffer)
{
    return GetByteInfo(buffer, WavByteNumber::StartBitsPerSample, WavByteNumber::EndBitsPerSample);
}

std::string WavHeader::GetDataChunkHeader(const std::vector<char>& buffer)
{
    std::string data_chunk_header;

    std::copy(begin(buffer) + static_cast<size_t>(WavByteNumber::StartDataChunkHeader),
              begin(buffer) + static_cast<size_t>(WavByteNumber::EndDataChunkHeader) + 1,
              std::back_inserter(data_chunk_header));
    return data_chunk_header;
}

std::int32_t WavHeader::GetDataSize(const std::vector<char>& buffer)
{
    return GetByteInfo(buffer, WavByteNumber::StartDataSize, WavByteNumber::EndDataSize);
}

bool WavHeader::IsValidHeader(const std::string& riff, const std::string& wave)
{
    bool is_valid{false};

    if (riff == "RIFF" && wave == "WAVE")
    {
        is_valid = true;
    }
    return is_valid;
}

std::string WavHeader::GetHeaderString()
{
    std::stringstream wav_header;
    wav_header << "validity  : " << is_valid_header << "\n";
    wav_header << "riff : " << riff << "\n";
    wav_header << "file_size : " << file_size << "\n";
    wav_header << "wave_name : " << wave_name << "\n";
    wav_header << "format : " << format << "\n";
    wav_header << "length_of_format : " << length_of_format << "\n";
    wav_header << "type_of_format : " << type_of_format << "\n";
    wav_header << "num_channels : " << num_channels << "\n";
    wav_header << "sample_rate : " << sample_rate << "\n";
    wav_header << "byterate : " << byterate << "\n";
    wav_header << "block_align : " << block_align << "\n";
    wav_header << "bits_per_sample : " << bits_per_sample << "\n";
    wav_header << "data_chunk_header : " << data_chunk_header << "\n";
    wav_header << "data_size : " << data_size << "\n";
    return wav_header.str();
}
}  // namespace encoder
