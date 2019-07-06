#include <bits/stdc++.h>

using namespace std;

string GetNextDigit(string s)
{
    auto numb = std::stoul(s);
    numb = numb + 1;
    
    return(std::to_string(numb));
}

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    string input;
    string x;
    bool result = true;
    
    if(!s.empty())
    {
        input.push_back(s[0]);
        for(int index= 0; index < s.size(); )
        {        
            string next = GetNextDigit(input);
            cout<<next<<endl;
            if(index+next.length() < s.size())
            {                
                string next_input = s.substr(index+1,next.length());
                cout<<next_input<<endl;
                if(!next_input.empty() )
                {
                    if(next == next_input)
                    {
                        if(x.empty())
                        {
                            x = input;
                        }
                        input.clear();
                        input = next_input;
                        index = (index + next.length());
                    }
                    else
                    {
                        if(x.empty())
                        {
                            input.push_back(s[index+1]);   
                            index++;
                        }
                        else
                        {
                         result = false;
                         break;   
                        }
                    }            
                    
                }            
            }
            else
            {
                if(index != (s.size()-1) || x.empty())
                {
                    result = false;
                }
                break;
            }            
        }
    }
    if(result)
    {
        cout<<"YES "<<x<<std::endl;
    }
    else
    {
        cout<<"NO"<<std::endl;
    }
}

int main()
{
separateNumbers("101102");

    return 0;
}
