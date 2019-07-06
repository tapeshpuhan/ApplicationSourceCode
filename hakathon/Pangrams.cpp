#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {

if(s.size() >= 26)
{
    set<char> val;
    
    for(auto& at : s)
    {
        if(std::isalpha(at))
        {
            val.insert(toupper(at));
        }
    }
    if(val.size() == 26)
    {
        return "pangram";
    }
}
return "not pangram";

}

int main()
{
    string s="We promptly judged antique ivory buckles for the prize";
    string result = pangrams(s);

    cout << result << "\n";
    
    return 0;
}
