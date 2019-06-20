#include <iostream>
#include <string>
#include <vector>

void swap(std::string& input, int start, int end)
{
    if(start!=end)
    {
        auto temp = input[start];
        input[start] = input[end];
        input[end] = temp;
    }
}

std::vector<std::string> GetPermute(std::string& input, const int& start, const int& end)
{
    static std::vector<std::string> output;
    
    if(start == end)
    {
        output.push_back(input);
    }
    else
    {
        for(int i = start; i < end; ++i)
        {
            swap(input, start, i);
            GetPermute(input,start+1, end);
            swap(input, start, i);
        }
        
    }
    return output;
    
}


int main()
{
    std::string input{"abc"};
    int start = 0;
    int end = input.length();
    
    std::vector<std::string>  out = GetPermute(input,start,end);
    for(auto at : out)
    {
        std::cout<<at<<std::endl;
    }
    return 0;
}
