#ifndef VALIDATE_DATA_H_
#define VALIDATE_DATA_H_
#include "data_cache.h"


enum class ValadateStatus
{
    GameOver,
    GameInProgress
};
class ValidateData
{
    public:
    explicit ValidateData(const DataCache& data_catche);
    ValadateStatus GetValidateDataStatus();
    private:
    bool DiagonalyFilled(const int32_t row_size, const int32_t colmn_size);
    bool VerticalyFilled(const int32_t row_size, const int32_t colmn_size);
    bool HorizontalFilled(const int32_t row_size, const int32_t colmn_size);
    bool FilledWithNone(const RoomStatus& value);
    DataCache data_catche_;
};


#endif //VALIDATE_DATA_H_
