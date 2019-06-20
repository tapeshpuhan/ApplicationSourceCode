#include <bits/stdc++.h>

using namespace std;

string rotate(const string& str, int k)
{
    auto length = str.length();
    auto rotate = (k + length)%length;
    string out;
    
    if(rotate)
    {
        out = str.substr(rotate);
        out += str.substr(0,rotate);        
    }
    else
    {
     out = str;   
    }
    return out;
}

size_t getPos(const char ch, const string& str)
{
    return str.find(ch);        
}

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    
    string letter = "abcdefghijklmnopqrstuvwxyz";
    string letter_out = rotate(letter,k);
    string out;
    
    for(auto& at : s)
    {
        auto value = at;
        
        if(std::isupper(at))
        {
             value = std::tolower(at);   
        }
        auto pos = getPos(value,letter);
        if(pos != string::npos)
        {
            if(std::isupper(at))
            {
              value = std::toupper(letter_out[pos]);   
            }
            else
            {
                value = letter_out[pos];
            }            
        }
        out.push_back(value);
    }
    return out;

}

int main()
{
    string s = "middle-Outz";
    int k = 2;
    string result = caesarCipher(s, k);

    cout << result << "\n";
    //cout << rotate("abcdefghijklmnopqrstuvwxyz",29)<<endl;


    return 0;
}
