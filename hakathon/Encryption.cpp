#include <bits/stdc++.h>

using namespace std;

std::pair<int,int> GetRowAndCoulomn(size_t length)
{
    std::pair<int,int>  len;
    auto var = sqrt(length);
    
    int var2 = static_cast<int>(var);
    if(var2 < static_cast<double>(var))
    {
        if((var2 * (var2+1)) >= length)
        {
            len = make_pair(var2,var2+1);
        }
        else
        {
           len = make_pair(var2+1,var2+1);
        }
    }
    else
    {
        len = make_pair(var2,var2);
    }
    
    return len;
}

// Complete the encryption function below.
string encryption(string s) {

    size_t length = s.size();
    
    auto len = GetRowAndCoulomn(length);
    
    size_t row = static_cast<size_t>(len.first);
    size_t colomn = static_cast<size_t>(len.second);
    
    string out;
    out.resize(length+row);
    int k = 0;
    for(int i =0; i < colomn; ++i)
    {
        for(int j = 0; j< row; ++j)
        {
            int index =  i + (colomn * j);
            if(index < length)
            {
               out[k] = s[index];
               k++; 
            }
        }
        out[k] = ' ';        
        k++; 
    }
    cout<<out<<std::endl;
    
    return out;

}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    //string s;
    //getline(cin, s);

    string result = encryption("haveaniceday");

    //fout << result << "\n";

    //fout.close();

    return 0;
}
