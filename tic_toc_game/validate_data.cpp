#include "validate_data.h"

ValidateData::ValidateData(const DataCache& data_catche):data_catche_{data_catche}
{
    
}

ValadateStatus ValidateData::GetValidateDataStatus()
{
    auto row_size = data_catche_.GetRowSize();
    auto coulmn_size = data_catche_.GetRowSize();
    ValadateStatus status{ValadateStatus::GameOver};
    
    auto status_diagonaly = DiagonalyFilled(row_size,coulmn_size);
    auto status_verticaly = VerticalyFilled(row_size,coulmn_size);
    auto status_horizontal = HorizontalFilled(row_size,coulmn_size);
    if(status_diagonaly || status_verticaly || status_horizontal)
    {
        status = ValadateStatus::GameInProgress;
    }
    return status;
}
bool ValidateData::FilledWithNone(const RoomStatus& value)
{
    return value == RoomStatus::FilledWithNone;
}

bool ValidateData::DiagonalyFilled(const int32_t row_size, const int32_t colmn_size)
{
    bool found{true};
    Index index{0,0};
    auto value = data_catche_.GetRoomInformation(index); 
    auto value1 = data_catche_.GetRoomInformation(index); 
    
    if(!FilledWithNone(value) && !FilledWithNone(value1))
    {
        while(found && (index.row < row_size))
        {
            index.row++;
            index.coulmn++;
            auto value2 = data_catche_.GetRoomInformation(index);
            if(FilledWithNone(value2))
            {
                break;
            }
            if(value != value2)
            {
               found = false;                 
            }            
        }
        if(found)
        {
            index={0,colmn_size-1};            
            while(found && (index.row < row_size))
            {
                index.row++;
                index.coulmn--;
                auto value2 = data_catche_.GetRoomInformation(index);
                if(FilledWithNone(value2))
                {
                    break;
                }
                if(value1 != value2)
                {
                   found = false;                 
                }            
            }
        }
    }
    return found;
}
 
bool ValidateData::VerticalyFilled(const int32_t row_size, const int32_t colmn_size)
{
    bool found{true};
    Index index{0,0};
    auto value = data_catche_.GetRoomInformation(index); 
    
    if(!FilledWithNone(value))
    {
        for(int32_t coulmn_index = 0; coulmn_index < colmn_size ; ++coulmn_index)
        {            
            for(int32_t row_index = 0; row_index < row_size ; ++row_index)
            {
                index.row = row_index;  
                index.coulmn = coulmn_index;              
                auto value1 = data_catche_.GetRoomInformation(index); 
                if(FilledWithNone(value1))
                {
                    return true;
                }
                if(value1 != value)
                {
                   return false;                 
                }  
            }
        }
    }
    return found;
}

bool ValidateData::HorizontalFilled(const int32_t row_size, const int32_t colmn_size)
{
    bool found{true};
    Index index{0,0};
    auto value = data_catche_.GetRoomInformation(index); 
    
    if(!FilledWithNone(value))
    {
        for(int32_t row_index = 0; row_index < row_size ; ++row_index)
        {
            for(int32_t coulmn_index = 0; coulmn_index < colmn_size ; ++coulmn_index)
            {
                index.row = row_index;  
                index.coulmn = coulmn_index;  
                auto value1 = data_catche_.GetRoomInformation(index); 
                if(FilledWithNone(value1))
                {
                    return true;
                }
                if(value1 != value)
                {
                   return false;                 
                }  
            }
        }
    }
    return found;
}
