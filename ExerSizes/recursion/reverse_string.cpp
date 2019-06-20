#include <iostream>
#include <string>

std::string reverse_string(const std::string& input)
{
    static std::string output;
    
    if(input.length())
    {
        output.push_back(input.at(input.length()-1));
        reverse_string(input.substr(0,input.length()-1));
    }
    return output;
}

int main()
{
    std::cout<<reverse_string("123456789")<<std::endl;
    return 0;
}
