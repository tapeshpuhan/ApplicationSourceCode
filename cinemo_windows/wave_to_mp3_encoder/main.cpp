
#include <memory>
#include <encoder_interface.h>
#include <helper/logger.h>
#include <filesystem>
namespace fs = std::filesystem;

int main(int argc, char** argv)
{

    Logger::LogError("Start of encoding");
    if (argc == 2)
    {
        std::unique_ptr<encoder::EncoderInterface> encode_mp3 = std::make_unique<encoder::EncoderInterface>();
        encode_mp3->EncodeWaveToMp3(argv[1], argv[1]);
        Logger::LogError("mp3encoder works on : ", argv[1]);
    }
    else
    {
        std::unique_ptr<encoder::EncoderInterface> encode_mp3 = std::make_unique<encoder::EncoderInterface>();
        encode_mp3->EncodeWaveToMp3(fs::current_path().string(), fs::current_path().string());
        Logger::LogError(" mp3encoder works on current folder path : ", fs::current_path().string());
    }
    return 0;
}
