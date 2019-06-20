#include <bits/stdc++.h>

using namespace std;

bool isUnique(string s)
{
   for(int i = 0; i < s.length()-1;++i)
   {
       if(s[i]==s[i+1])
       {
           return false;
       }
   } 
   
   return true;
}

// Complete the superReducedString function below.
string superReducedString(string s) {
string s_out;

    for(int index = 0; index < s.length();)
    {
        if(s[index] == s[index+1])
        {
            index = index+2;
        }
        else
        {
           s_out.push_back(s[index]);
           ++index;
        }
    }
if(!s_out.length())
{
    s_out = "Empty String";
}
return s_out;
}

string superReducedString_1(string s)
{
    string out;
    
while(1)
{
        out = superReducedString(s);
        if(out == s)
        {
            break; 
        }
        s = out;
}
        
    return out;
}

int main()
{
cout<<superReducedString_1("aaabccddd")<<endl;

//cout<<isUnique("bb")<<endl;

    return 0;
}
