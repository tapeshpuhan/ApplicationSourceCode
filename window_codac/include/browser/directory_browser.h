//
// Created by gl-273 on 2/14/20.
//

#ifndef MP3ENCODER_DIRECTORY_BROWSER_H
#define MP3ENCODER_DIRECTORY_BROWSER_H
#include <helper/encoder_type.h>

namespace encoder
{
    using UpdateFileNameHandler = std::function<void(const std::string&)>;

    const  std::string END_OF_FILE{"END_OF_FILE"};

    class DirectoryBrowser final
    {
    public:
        DirectoryBrowser()= default;
        ~DirectoryBrowser()= default;
        DirectoryBrowser(DirectoryBrowser&)= delete;
        DirectoryBrowser& operator=(DirectoryBrowser&&)=delete;
        void RegisterTOUpdateFileName(UpdateFileNameHandler&& file_name_handler);
        void BrowseDirectory(const DirectoryName& input_directory, const std::string& file_extension);

    private:

        std::string GetFileExtension(const std::string& file_name);
        void UpdateFileName(const std::string& file_name);
        bool IsIEqual(const std::string& source, const std::string& destination);

        UpdateFileNameHandler file_name_handler_{nullptr};
    };
}
#endif //MP3ENCODER_DIRECTORY_BROWSER_H
