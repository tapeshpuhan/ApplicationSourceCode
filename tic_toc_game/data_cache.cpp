#include "data_cache.h"

DataCache::DataCache(const int32_t row_size, const int32_t colmn_size):
row_size_{row_size},colmn_size_{colmn_size}
{
    InitializeRoomWithNone();
}
void DataCache::InitializeRoomWithNone()
{
    room_type_.resize(row_size_);
    for(int32_t row_index = 0; row_index<row_size_; ++row_index)
    {
        room_type_.at(row_index).resize(colmn_size_);
        for(int32_t coulmn_index = 0; coulmn_index < colmn_size_; ++coulmn_index)
        {
            room_type_.at(row_index).at(coulmn_index) = RoomStatus::FilledWithNone;
        }
    }
}

ReturnStatus DataCache::UpdateRoomInformation(const Index& index, const RoomStatus& status)
{
    ReturnStatus return_value{ReturnStatus::IndexError};
    
    if(IsValidIndex(index))
    {
        if(room_type_.at(index.row).at(index.coulmn) == RoomStatus::FilledWithNone)
        {
            room_type_.at(index.row).at(index.coulmn) = status;
            return_value = ReturnStatus::Sucess;
        }
        else
        {
            return_value = ReturnStatus::AllreadyFilled;
        }
    }
    return return_value;
}

bool DataCache::IsValidIndex(const Index& index)
{
    bool return_value{false};
    if(row_size_ == colmn_size_)
    {
        if((index.row < row_size_) && (index.coulmn < colmn_size_))
        {
            return_value = true;
        }
    }
    return return_value;    
}

RoomStatus DataCache::GetRoomInformation(const Index& index)
{
   RoomStatus room_status{RoomStatus::FilledWithNone};
   
   if(IsValidIndex(index))
   {
       room_status = room_type_.at(index.row).at(index.coulmn);
   }
   return room_status;
}

tRoomType DataCache::GetRoomInfo() const
{
    return room_type_;
}

int32_t DataCache::GetRowSize()const
{
    return row_size_;
}

int32_t DataCache::GetCoulmnSize()const
{
    return colmn_size_;
}
