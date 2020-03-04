//
// Created Tapeswar Puhan
//

#ifndef MP3ENCODER_LAME_ENCODER_H
#define MP3ENCODER_LAME_ENCODER_H

#include <encoder/i_encoder.h>
#include <encoder/wav_header.h>
#include <helper/task_pool.h>
#include <lame/lame.h>
namespace encoder
{
constexpr std::int8_t GoodQuality = 5;
constexpr int PCM_SIZE = 8192;
constexpr int MP3_SIZE = 8192;

class LameEncoder final : public IEncoder
{
  public:
    explicit LameEncoder(const DirectoryName& output_directory_path);
    ~LameEncoder() = default;

  private:
    void EncodeMediaFileImplement(MediaFileName&& media_file_path) noexcept override;
    void RegisterUpdateInformationImplement(UpdateInformation&& information_handler) override;
    IEncoder::Ptr CreateImplement() override;

    void UpdateEncodeStatus(const EncoderStatus& information);
    lame_t InitializeLameEncoder(const std::unique_ptr<WavHeader>& header) const;
    MediaFileName GetMp3FileName(const MediaFileName& wave_file_name);
    bool EncodeToMp3File(const MediaFileName& mp3_file_path,
                         const MediaFileName& wav_file_path,
                         const std::unique_ptr<WavHeader>& header,
                         const lame_t lame_handler);

    DirectoryName output_directory_path_;
    UpdateInformation information_handler_{nullptr};
    const std::uint16_t single_channel{1};
};
}  // namespace encoder
#endif  // MP3ENCODER_LAME_ENCODER_H
