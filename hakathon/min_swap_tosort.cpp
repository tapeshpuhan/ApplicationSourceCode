#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int GetPos(std::vector<int>::iterator input,std::vector<int>::iterator out,int value)
{
    int pos = 0;
    while(input != out)
    {
        if(*input == value)
        return pos;
        
        pos++;
        input++;
    }
}

void swap_int(std::vector<int>& input, int in, int out)
{
    auto temp = input[in];
    input[in] = input[out];
    input[out] = temp;
}

int MinSwap(std::vector<int>& input)
{
    int digit = 1;
    int size = input.size();
    int swap = 0;
    
    while(digit != size)
    {
        if(input[digit-1] != digit)
        {
            auto pos = GetPos(input.begin()+digit, input.end(),digit);
            swap_int(input,digit-1,pos+digit);
            swap++;
        }
      digit++;  
    }
    return swap;
}


int main()
{
    std::vector<int> in =  {7, 1, 3, 2, 4, 5, 6};
    std::cout<<MinSwap(in)<<std::endl;
    
    return 0;
}
