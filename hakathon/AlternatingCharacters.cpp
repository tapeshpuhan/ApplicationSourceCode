#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) 
{

    int number = 0;
    
    if(s.find("A") == string::npos || s.find("B") == string::npos)
    {
        number = s.length()-1;
    }
    else
    {
        if(s.length())
        {
            char first = s[0];
            string::size_type pos = 0;
            string::size_type prev_pos = 0;
            char alt = 'A';
            if(first == 'A')
            {                
                alt = 'B';                
            }
            while(pos!=string::npos)
            {
                pos = s.find(alt,pos+1);
                if(alt == 'B')
                {
                    alt = 'A';
                }
                else
                {
                    alt = 'B';
                }
               // cout<<pos<<" "<<prev_pos<<endl;
                if(pos != string::npos)
                {
                
                    number += (pos-1 - prev_pos);
                    
                }
                else
                {
                    number+=s.length()-1-prev_pos;
                }
                prev_pos = pos;
                //cout<<number<<endl;
            }
        }
    }
    return number;
}

int main()
{
 
        int result = alternatingCharacters("AAABBB");

        cout << result << "\n";

    return 0;
}
