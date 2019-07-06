#include <bits/stdc++.h>

using namespace std;

// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string b) {

int number = 0;
size_t pos = 0;

    while(true)
    {
        pos = b.find("010",pos);
        if(pos == string::npos)
        {
            break;
        }
        number++;
        pos= pos+3;
    }
    return number;
}

int main()
{



    string b = "01100";


    int result = beautifulBinaryString(b);

    cout << result << "\n";



    return 0;
}
