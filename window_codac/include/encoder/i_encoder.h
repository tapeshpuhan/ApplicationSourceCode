//
// Created by gl-273 on 2/13/20.
//

#ifndef MP3ENCODER_I_ENCODER_H
#define MP3ENCODER_I_ENCODER_H
#include <helper/encoder_type.h>
#include <memory>

namespace encoder
{
    struct IEncoder
    {
        using Ptr = std::shared_ptr<IEncoder>;

        IEncoder()= default;
        virtual ~IEncoder()= default;

        virtual void EncodeMediaFile(MediaFileName&&)=0;
        virtual void RegisterUpdateInformation(UpdateInformation&&)noexcept=0 ;

        virtual IEncoder::Ptr Clone()=0;
        virtual IEncoder::Ptr Create()=0;
    };
}
#endif //MP3ENCODER_I_ENCODER_H
