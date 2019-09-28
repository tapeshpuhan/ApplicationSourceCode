#ifndef DATA_CACHE_H_
#define DATA_CACHE_H_
#include <vector>
#include <algorithm>

enum class RoomStatus
{
    FilledWithNone,
    FilledWithZero,
    FilledWithCross
};
enum class ReturnStatus
{
    Sucess,
    AllreadyFilled,
    IndexError,
};

struct Index
{
    size_t row;
    size_t coulmn;
};
using tRoomType = std::vector<std::vector<RoomStatus>>;

class DataCache
{
    public:
    explicit DataCache(const int32_t row_size, const int32_t colmn_size);
    ReturnStatus UpdateRoomInformation(const Index& index, const RoomStatus& status);
    RoomStatus GetRoomInformation(const Index& index);
    tRoomType GetRoomInfo() const;
    int32_t GetRowSize()const;
    int32_t GetCoulmnSize()const;
    
    private:
    
    void InitializeRoomWithNone();
    bool IsValidIndex(const Index& index);
    tRoomType room_type_;
    int32_t row_size_;
    int32_t colmn_size_;
};


#endif //DATA_CACHE_H_
