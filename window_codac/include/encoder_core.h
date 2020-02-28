//
// Created by gl-273 on 2/13/20.
//

#ifndef MP3ENCODER_ENCODER_CORE_H
#define MP3ENCODER_ENCODER_CORE_H
#include <string>
#include <encoder/i_encoder.h>
#include <helper/encoder_type.h>

namespace encoder
{

    template<typename MediaBrowser, typename MediaEncoder>
    class EncoderCore final {
        public:
            explicit EncoderCore(const DirectoryName &input_directory_path,
                                 const std::shared_ptr<IEncoder> encoder);
            ~EncoderCore()=default;
            EncoderCore(EncoderCore&)=delete;
            EncoderCore& operator=(EncoderCore&)=delete;

            void InitializeCore();

        private:

            void EncodeMediaFiles(MediaFileList&& media_file_list,const EndOfFileStatus& eof_status);

            typename MediaBrowser::ConstPtr media_browser_;
            typename MediaEncoder::ConstPtr media_encoder_;
    };

}
#endif //MP3ENCODER_ENCODER_CORE_H
