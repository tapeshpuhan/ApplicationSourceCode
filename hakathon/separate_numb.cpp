#include <bits/stdc++.h>

using namespace std;

// Complete the separateNumbers function below.
string GetNextDigit(string s)
{
    auto numb = std::stoul(s);
    numb = numb + 1;
    
    return(std::to_string(numb));
}

string Find_x(string s)
{
    string  x;
    
    for(size_t index = 0; index < (s.length()/2);++index)
    {
        string sub = s.substr(0,index+1);
        string res = GetNextDigit(sub);
        string res_sub = s.substr(index+1,res.length());
        if(res_sub == res)
        {
            x = sub;
        }        
    }
    return x;
}

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    bool status = true;
    
    string res_str;
    
    if(s.length())
    {
        string x = Find_x(s);
        res_str = x;
        
        if(x.length())
        {
            for(size_t index = x.length(); index < s.length();)
            {                
                string res = GetNextDigit(x);                
                string sub = s.substr(index,res.length());
                
                if(res != sub)
                {
                   status = false;
                   break;
                }
                x = sub;
                index = index +  sub.length();  
            }
        }
        else
        {
         status = false;   
        }
    }
    else
    {
        status = false;
    }
    if(status)
    {
        cout<<"YES "<<res_str<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
}

int main()
{
    separateNumbers("9899100");

//separateNumbers(s);

    return 0;
}
