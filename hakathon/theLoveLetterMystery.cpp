#include <bits/stdc++.h>

using namespace std;

// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(string s) {

int result = 0;
size_t length = s.length();

for(size_t index = 0; index < (length/2); ++index)
{
    
    if(s[index] != s[(length-1)-index])
    {
        result += std::abs(s[(length-1)-index]- s[index]);
    }
}
return result;

}

int main()
{
        int result = theLoveLetterMystery("abc");

        cout << result << "\n";

        result = theLoveLetterMystery("abcba");

        cout << result << "\n";
        
        result = theLoveLetterMystery("abcd");

        cout << result << "\n";
        
        result = theLoveLetterMystery("cba");

        cout << result << "\n";
        
    return 0;
}
