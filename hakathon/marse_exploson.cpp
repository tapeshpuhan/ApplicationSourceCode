#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {
    int counter = 0;
    string mars{"SOS"};
    int index = 0;
    
    while(index < s.length())
    {
        string sub_str = s.substr(index,3);
        
        if(mars != sub_str)
        {
            if(mars.length() == sub_str.length())
            {
                for(int i = 0; i < mars.length(); ++i)
                {
                    if(mars[i]!=sub_str[i])
                    {
                       counter++; 
                    }
                }
            }
        }
        index = index+3;
    }
    return counter;
}

int main()
{


    string s = "SOSSOSSOS";

    int result = marsExploration(s);

    cout << result << "\n";


    return 0;
}
