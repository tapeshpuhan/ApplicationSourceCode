//
// Created by gl-273 on 2/14/20.
//
#include <encoder_core.h>
#include <encoder_adaptor.h>
namespace encoder
{
    template<typename MediaBrowser, typename MediaEncoder>
    EncoderCore<MediaBrowser,MediaEncoder>::EncoderCore(const DirectoryName &input_directory_path,
                                                        const std::shared_ptr<IEncoder> encoder):media_browser_{std::make_shared<MediaBrowser>(input_directory_path)},
                                                                                                 media_encoder_{std::make_shared<MediaEncoder>(encoder)}
    {

    }


    template<typename MediaBrowser, typename MediaEncoder>
    void EncoderCore<MediaBrowser,MediaEncoder>::InitializeCore()
    {
        auto MediaFileListAndEndOfFileInfoCallback = [this](auto&& media_file_list, const EndOfFileStatus& eof_status)
        {
            this->EncodeMediaFiles(std::forward<MediaFileList>(media_file_list),eof_status);
        };
        media_browser_->RegisterForMediaFileUpdates(MediaFileListAndEndOfFileInfoCallback);
        media_browser_->InitializeBrowser();
        media_encoder_->InitializeEncoder();
    }

    template<typename MediaBrowser, typename MediaEncoder>
    void EncoderCore<MediaBrowser,MediaEncoder>::EncodeMediaFiles(MediaFileList&& media_file_list, const EndOfFileStatus& eof_status)
    {
        media_encoder_->EncodeMediaFiles(std::forward<MediaFileList>(media_file_list),eof_status);
    }
}
