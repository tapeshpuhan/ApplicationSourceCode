#include <iostream>
#include <vector>

template<typename Type>
class PrioQueue
{
    public:
    
    PrioQueue()=default;
    void Push(const Type& data)
    {
        Insert(data);
    }
    Type Pop()
    {
        return Delete();
    }
    Type Top()
    {
        Type value;
        if(!prio_queue_.empty())
        {
            value = prio_queue_.at(0);
        }
        return value;
    }
    
    void print()
    {
        for(auto at : prio_queue_)
        {
            std::cout<<at<<" ";
        }
        std::cout<<std::endl;
    }
    
    private:    
    int LeftChildIndex(const int index)
    {
        return index*2+1;
    }
    
    int RightChildIndex(const int index)
    {
        return index*2+2;
    }
    
    int RootIndex(const int index)
    {
        return (index-1)/2;
    }
    
    void SwapInput(std::vector<Type>& input,const int index_1, const int index_2)
    {
        Type value = input[index_1];
        input[index_1] = input[index_2];
        input[index_2] = value;
    } 
    
    int GetGreaterValueChildIndex(const std::vector<Type>& input, const int input_index)
    {
        auto left_child_index = LeftChildIndex(input_index);
        auto right_child_index = RightChildIndex(input_index);
        auto size_input = input.size();
        int result_index = 0;
        auto left_value =  input[left_child_index];
        auto right_value =  input[right_child_index];
                
        if(left_child_index < size_input)
        {
            if(right_child_index < size_input)
            {
                if(left_value > right_value)
                {
                    if(input[input_index] < left_value)
                    {
                        result_index = left_child_index;
                    }
                }
                else
                {
                    if(input[input_index] < right_value)
                    {
                        result_index = right_child_index;
                    }
                }
            }
            else
            {
                if(input[input_index] < left_value)
                {
                   result_index = left_child_index;
                }
            }
        }
        return result_index;
    }
    
    int GetLesserValueRootIndex(const std::vector<Type>& input, const int input_index)
    {
        int parent_index = RootIndex(input_index);
        int result_index = -1;
        
        if(input_index && !input.empty())
        {
            if(input[parent_index] < input[input_index])
            {
                result_index = parent_index;
            }
        }
        return result_index;
    }
    
    void Insert(const Type& value)
    {
        prio_queue_.push_back(value);
        int result_index = prio_queue_.size() -1;
        
        while(1)
        {
            int res = GetLesserValueRootIndex(prio_queue_,result_index);
            if(res == -1)
            {
                break;
            }
            SwapInput(prio_queue_,res,result_index);
            result_index = res;
        }
        
    }
    
    Type Delete()
    {
        Type value;
        
        if(!prio_queue_.empty())
        {
            value = prio_queue_.at(0);
            SwapInput(prio_queue_,0,prio_queue_.size()-1);
            prio_queue_.erase(prio_queue_.begin()+(prio_queue_.size()-1));
            int result_index = 0;
            
            while(1)
            {
                int res = GetGreaterValueChildIndex(prio_queue_,result_index);
                if(!res)
                {
                    break;
                }
                SwapInput(prio_queue_,res,result_index);
                result_index = res;
            }
        }
        return value;
    }
    
    std::vector<Type> prio_queue_;
};
