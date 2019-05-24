#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string GetReverse(const string& input)
{
    if(input.length()>1)
    {        
        return {input.crbegin(),input.crend()};
    }
    return input;
}

int32_t GetNumberSubString(const string& source, const string& dest)
{
    int32_t count = 0;
    size_t s_len = source.length();
    size_t d_len = dest.length();
    int i = 0;
    
    for(int j = 0; j <= d_len-s_len; ++j)
    {
        if(source[i] == dest[j])
        {
            for(auto s : source)
            {
               if(s != dest[j+i])
               {
                   break;
               }
               
               i++; 
            }
            if( i == s_len)
            {
             count++;   
            }
            i = 0;
        }
    }
    return count;    
}

int sherlockAndAnagrams(string s) {

    int count  = 0;
    
    
    while(s.length() > 1)
    {
        string dest(s.begin()+1,s.end());
        string source;
        for(int i = 0; i < dest.length(); ++i)
        {
            source.push_back(s[i]);
            cout<<source<<" :: "<<dest<<std::endl;
            count += GetNumberSubString(GetReverse(source),dest);
            cout<<count<<std::endl;
        }
        s = dest;
    }
    return count;
}

int main()
{
    std::cout<<sherlockAndAnagrams("ifailuhkqq")<<std::endl;
    return 0;
}
