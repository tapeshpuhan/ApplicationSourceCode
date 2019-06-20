#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using tWords = std::vector<std::string>;

tWords FindWords(const std::string& input, const tWords& dist)
{
    std::string sub_str;
    static tWords words;
    int index = 0;
    
    if(input.length())
    {
        for(index = 0; index <input.length(); ++index)
        {
            sub_str.push_back(input[index]);
            if(std::find(begin(dist),end(dist),sub_str) != end(dist))
            {
                words.push_back(sub_str);                
                FindWords(input.substr(sub_str.length()),dist);
                break;
            }            
        }
        
    }
    return words;
}


int main()
{
    
    //auto words = FindWords("themanrun",{"the","run","man"});
    //auto words = FindWords("ilovedogsJohn",{"i","am","dogs","lover","love","John"});
    auto words = FindWords("themanran",{"clown","run","man"});
    for(auto& word : words)
    {
        std::cout<<word<<std::endl;
    }
    
    return 0;
}
