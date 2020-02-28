//
// Created by gl-273 on 2/14/20.
//

#include <browser/wav_browser.h>


namespace encoder
{
    WavBrowser::WavBrowser(const DirectoryName& input_directory):input_directory_{input_directory},
                                                                 browser_{std::make_unique<DirectoryBrowser>()}
    {

    }

    void WavBrowser::InitializeBrowser()
    {
        auto UpdateFileNameCallback = [this](const auto& file_name)
        {
            this->HandelFileName(file_name);
        };
        browser_->RegisterTOUpdateFileName(UpdateFileNameCallback);

        auto BrowseDirectoryCallback = [this]()
                                            {
                                                browser_->BrowseDirectory(input_directory_,FileExtensionFilter::WavFile);
                                            };
        std::thread th{BrowseDirectoryCallback};
        if(th.joinable())
        {
            th.join();
        }
    }

    void WavBrowser::RegisterForMediaFileUpdates(UpdateMediaFilesHandler&& media_files_update_handler)
    {
        media_files_update_handler_ = std::move(media_files_update_handler);
    }

    void WavBrowser::UpdateListOfFiles(MediaFileList&& media_file_liast,const EndOfFileStatus& eof_status)
    {
        if(media_files_update_handler_)
        {
            media_files_update_handler_(std::forward<MediaFileList>(media_file_liast),eof_status);
        }
    }

    void WavBrowser::HandelFileName(const std::string& file_name)
    {
        if(END_OF_FILE == file_name)
        {
            UpdateListOfFiles(std::move(file_list_),EndOfFileStatus::EndOfFileReached);
            file_list_.clear();
        }
        else
        {
            file_list_.emplace_back(file_name);

            if(file_list_.size() >= MAX_FILE_LIST)
            {
                UpdateListOfFiles(std::move(file_list_),EndOfFileStatus::ScanInProgress);
                file_list_.clear();
            }
        }
    }

}
