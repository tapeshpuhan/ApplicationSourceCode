//
// Created Tapeswar Puhan
//

#include <browser/directory_browser.h>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
namespace encoder
{

void DirectoryBrowser::RegisterTOUpdateFileName(UpdateFileNameHandler&& file_name_handler)
{
    file_name_handler_ = std::move(file_name_handler);
}

void DirectoryBrowser::BrowseDirectory(const DirectoryName& input_directory, const std::string& file_extension)
{
    std::int32_t number_of_file{0};

    for (const auto& file_name : fs::recursive_directory_iterator(input_directory))
    {

        if (IsIEqual(GetFileExtension(file_name.path()), file_extension))
        {
            UpdateFileName(file_name.path());
            number_of_file++;
        }
    }
    if (number_of_file)
    {
        UpdateFileName(END_OF_FILE);
    }
    else
    {
        UpdateFileName(NO_FILE_AVAILABLE);
    }
}

std::string DirectoryBrowser::GetFileExtension(const std::string& file_name)
{
    std::string extension_result{""};
    auto position_of_extension = file_name.find_last_of('.');

    if (position_of_extension != std::string::npos)
    {
        extension_result = file_name.substr(position_of_extension);
    }
    return extension_result;
}

void DirectoryBrowser::UpdateFileName(const std::string& file_name)
{
    if (file_name_handler_ != nullptr)
    {
        file_name_handler_(file_name);
    }
}

bool DirectoryBrowser::IsIEqual(const std::string& source, const std::string& destination)
{
    return std::equal(
        begin(source), end(source), begin(destination), end(destination), [](const auto& entry_1, const auto& entry_2) {
            return std::tolower(entry_1) == std::tolower(entry_2);
        });
}
}  // namespace encoder