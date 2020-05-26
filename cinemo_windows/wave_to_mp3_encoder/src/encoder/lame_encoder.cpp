//
// Created by Tapeswar Puhan
//

#include <encoder/lame_encoder.h>
#include <helper/logger.h>
namespace encoder
{

LameEncoder::LameEncoder(const DirectoryName& output_directory_path) : output_directory_path_{output_directory_path} {}

void LameEncoder::EncodeMediaFileImplement(MediaFileName&& media_file_path) noexcept
{
    Logger::LogInfo("File to decode", media_file_path);

    std::unique_ptr<WavHeader> get_header = std::make_unique<WavHeader>(media_file_path);
    Logger::LogInfo(get_header->GetHeaderString());

    if (true == get_header->is_valid_header)
    {
        auto lame_handler = InitializeLameEncoder(get_header);
        if (false == EncodeToMp3File(GetMp3FileName(media_file_path), media_file_path, get_header, lame_handler))
        {
            UpdateEncodeStatus(EncoderStatus::EncodeFailed);
        }
    }
    else
    {
        UpdateEncodeStatus(EncoderStatus::InvalidHeader);
    }

    Logger::LogInfo("File to decode finished");
}

void LameEncoder::RegisterUpdateInformationImplement(UpdateInformation&& information_handler)
{
    information_handler_ = std::move(information_handler);
}

void LameEncoder::UpdateEncodeStatus(const EncoderStatus& information)
{
    if (information_handler_)
    {
        information_handler_(information);
    }
}

IEncoder::Ptr LameEncoder::CreateImplement()
{
    return std::make_shared<LameEncoder>(output_directory_path_);
}

lame_t LameEncoder::InitializeLameEncoder(const std::unique_ptr<WavHeader>& header) const
{
    auto lame_handler = lame_init();

    lame_set_in_samplerate(lame_handler, header->sample_rate);
    lame_set_quality(lame_handler, GoodQuality);
    lame_set_brate(lame_handler, header->bits_per_sample / NO_OF_BIT_PER_BYTE);
    lame_set_num_channels(lame_handler, header->num_channels);

    if (single_channel == header->num_channels)
    {
        lame_set_mode(lame_handler, MONO);
    }
    lame_set_VBR(lame_handler, vbr_default);
    lame_init_params(lame_handler);
    return lame_handler;
}

MediaFileName LameEncoder::GetMp3FileName(const MediaFileName& wave_file_name)
{
    auto mp3_file_name{wave_file_name};
    return mp3_file_name.replace(mp3_file_name.size() - 3, 3, "mp3");
}

bool LameEncoder::EncodeToMp3File(const MediaFileName& mp3_file_path,
                                  const MediaFileName& wav_file_path,
                                  const std::unique_ptr<WavHeader>& header,
                                  const lame_t lame_handler)
{
    bool encode_status{false};
    std::ofstream mp3_file_handler{mp3_file_path, std::ios::binary};
    std::ifstream wav_file_handler{wav_file_path, std::ios::binary};

    if (mp3_file_handler.is_open() && wav_file_handler.is_open())
    {
        char pcm_buffer[sizeof(std::uint16_t) * PCM_SIZE * 2];
        unsigned char mp3_buffer[MP3_SIZE];
        auto wave_data_to_read{PCM_SIZE * header->num_channels * sizeof(std::uint8_t)};
        size_t position_to_read{static_cast<size_t>(WavByteNumber::EndOfHeader)};
        size_t number_of_mp3_stream{0};

        wav_file_handler.read(pcm_buffer, position_to_read);
        auto stream_size = wav_file_handler.gcount();

        while (stream_size != 0)
        {
            wav_file_handler.read(pcm_buffer, wave_data_to_read);
            stream_size = wav_file_handler.gcount();
            if (stream_size == wave_data_to_read)
            {
                int number_of_samples_per_channel{static_cast<int>(wave_data_to_read / 2)};
                if (header->num_channels == single_channel)
                {
                    number_of_mp3_stream = lame_encode_buffer(lame_handler,
                                                              reinterpret_cast<short int*>(&pcm_buffer[0]),
                                                              NULL,
                                                              number_of_samples_per_channel,
                                                              mp3_buffer,
                                                              MP3_SIZE);
                }
                else
                {
                    number_of_mp3_stream = lame_encode_buffer_interleaved(lame_handler,
                                                                          reinterpret_cast<short int*>(&pcm_buffer[0]),
                                                                          number_of_samples_per_channel,
                                                                          mp3_buffer,
                                                                          MP3_SIZE);
                }
            }
            else if(stream_size)
            {
                number_of_mp3_stream = lame_encode_flush(lame_handler, mp3_buffer, MP3_SIZE);
            }
            mp3_file_handler.write(reinterpret_cast<char*>(mp3_buffer), number_of_mp3_stream);
        }
        mp3_file_handler.close();
        wav_file_handler.close();
        encode_status = true;
    }
    return encode_status;
}

}  // namespace encoder
