#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

bool IsAnagram(string in1, string in2)
{
   // cout<<in1<<" "<<in2<<endl;
    if(in1.length()!=in2.length())
    {
        return false;
    }
    std::sort(in1.begin(),in1.end());
    std::sort(in2.begin(),in2.end());
    
    if(in1 == in2)
    {
        return true;
    }
    
    return false;
}

int32_t GetNumberSubString(const string& source, const string& dest)
{
    int32_t count = 0;
    size_t s_len = source.length();
    size_t d_len = dest.length();
    
    
    for(int i = 0; i <= (d_len - s_len); ++i )
    {
        if(IsAnagram(source, dest.substr(i,s_len)))
        {
           count++; 
        }
    }
   
    return count;    
}

int sherlockAndAnagrams(string s) {

    int count  = 0;
    
    
    while(s.length() > 1)
    {
        
        for(int i = 0; i < s.length()-1; ++i)
        {
            count += GetNumberSubString(s.substr(0,i+1),s.substr(1));
        
        }
        s = s.substr(1);
    }
    return count;
}

int main()
{
    std::cout<<sherlockAndAnagrams("zjekimenscyiamnwlpxytkndjsygifmqlqibxxqlauxamfviftquntvkwppxrzuncyenacfivtigvfsadtlytzymuwvpntngkyhw")<<std::endl;
    return 0;
}
