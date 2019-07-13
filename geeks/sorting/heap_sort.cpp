#include <iostream>
#include <vector>

int LeftChildIndex(const int index)
{
    return index*2+1;
}

int RightChildIndex(const int index)
{
    return index*2+2;
}

void SwapInput(std::vector<int>& input,const int index_1, const int index_2)
{
    auto value = input[index_1];
    input[index_1] = input[index_2];
    input[index_2] = value;
}

int GetGreaterValueChildIndex(const std::vector<int>& input, const int input_index)
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

void HippyFy(std::vector<int>& input)
{
    auto n = input.size();
    for(int index = n-1; index >= 0 ; --index)
    {
        int result_index = index;
        while(1)
        {
            int swap_index = GetGreaterValueChildIndex(input,result_index);
            if(swap_index)
            {
                SwapInput(input,result_index,swap_index);
                result_index = swap_index;
            }
            else
            {
                break;
            }
        }
    }
}

std::vector<int> HeapSort(std::vector<int>& input)
{
    std::vector<int> result;
    auto n = input.size();
    for(int index = 0; index < n;++index)
    {
        HippyFy(input);
        result.push_back(input.at(0));
        input.erase(input.begin());

    }
    return result;
}

int main()
{
    std::vector<int> input{4,10,3,5,1,100,25,67,23,5};
    auto result = HeapSort(input);
    //HippyFy(input);
    for(auto& at : result)
    {
        std::cout<<at<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
