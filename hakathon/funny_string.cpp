#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {

    string result;
    bool funny = true;
    int i =0;
    int j = (s.size()-1);

    for(; i < j; ++i,--j)
    {
        auto x = abs(s[i] - s[i+1]);
        auto y = abs(s[j] - s[j-1]);
        
        if(x != y)
        {
         funny = false;
         break;   
        }
    }

    if(funny)
    {
        result = "Funny";
    }
    else
    {
        result = "Not Funny";
    }
    return result;
}

int main()
{
        string result = funnyString("bcxz");

        cout << result << "\n";

    return 0;
}
