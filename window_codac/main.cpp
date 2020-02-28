
#include <helper/logger.h>
#include <encoder_interface.h>
#include <memory>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

int main(int argc, char** argv)
{

    Logger::LogError("Start of encodeing");
    if(argc == 2)
    {
        Logger::LogInfo("Input Directory is : ",argv[1]);
        std::unique_ptr<encoder::EncoderInterface> encode_mp3 = std::make_unique<encoder::EncoderInterface>();
        encode_mp3->EncodeWmaToMp3(argv[1],argv[1]);
    }
    else
    {
        Logger::LogError("HELP: mp3encoder folder_path");
        std::unique_ptr<encoder::EncoderInterface> encode_mp3 = std::make_unique<encoder::EncoderInterface>();
        encode_mp3->EncodeWmaToMp3(fs::current_path(),fs::current_path());
    }
    return 0;
}
