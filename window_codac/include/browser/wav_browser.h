//
// Created by gl-273 on 2/13/20.
//

#ifndef MP3ENCODER_WAV_BROWSER_H
#define MP3ENCODER_WAV_BROWSER_H

#include <browser/directory_browser.h>
#include <thread>
namespace encoder
{

    constexpr std::int32_t MAX_FILE_LIST=5;

    class WavBrowser final
    {
        public:

        explicit WavBrowser(const DirectoryName& input_directory);
        WavBrowser(WavBrowser&)= delete;
        WavBrowser& operator=(WavBrowser&&)=delete;
        ~WavBrowser()= default;

        void InitializeBrowser();
        void RegisterForMediaFileUpdates(UpdateMediaFilesHandler&& media_files_update_handler);

        using ConstPtr = const std::shared_ptr<WavBrowser>;
        using Ptr = std::shared_ptr<WavBrowser>;

        private:

        void UpdateListOfFiles(MediaFileList&& media_file_liast, const EndOfFileStatus& eof_status);
        void HandelFileName(const std::string& file_name);

        UpdateMediaFilesHandler media_files_update_handler_{nullptr};
        DirectoryName input_directory_;
        std::unique_ptr<DirectoryBrowser> browser_;
        MediaFileList file_list_;
    };

}
#endif //MP3ENCODER_WAV_BROWSER_H
