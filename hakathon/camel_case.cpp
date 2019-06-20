#include <bits/stdc++.h>

using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {
    int count = 0;
    if(s.length())
    {
        
        count = std::count_if(s.begin()+1,s.end(),[&](const auto& ch){ return std::isupper(ch);});
        count++;
    }
    return count;            
}

int main()
{


    int result = camelcase("saveChangesInTheEditor");

    cout << result << "\n";


    return 0;
}
