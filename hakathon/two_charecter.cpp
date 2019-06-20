#include <bits/stdc++.h>

using namespace std;

using tCharPair = std::pair<char,char>;

vector<tCharPair> GetPairOfChar(string list)
{
    vector<tCharPair>  list_char;
    
    
    if(list.size() > 1)
    {
        for(int i = 0; i < list.size(); ++i)
        {
            for(int j = i + 1; j < list.size(); j++)
            {
                tCharPair p{list[i],list[j]};
                list_char.push_back(p);
            }
        }
    }
    return list_char;
    
}

int LengthOfAlternate(string s, tCharPair two_char)
{
    int result = 0;
    
    if(s.length() > 1)
    {
        char p;
        
        char his[3];        
        int h_ind = 0;        
        result = 0;
        
        
        std::all_of(begin(s),end(s),[&](char ch)
        {           
                if(ch == two_char.first || ch == two_char.second)
                { 
                    
                    if(result > 0)
                    {
                    
                        if(p == ch)
                        {
                           result = 0;
                           return false; 
                        }                    
                    
                        his[h_ind] = ch;
                        h_ind++; 
                        if(result > 1)
                        {
                            if(his[0] != his[2])
                            {
                                result = 0;
                                return false;  
                            }
                            his[0] = his[1];
                            his[1] = his [2];
                            h_ind = 2;
                        }
                    }
                    else
                    {
                        his[h_ind] = ch;
                        h_ind++; 
                    }
                    
                    p = ch;
                    result++;                    
                }
                return true;
        });
    }
    return result;
}

// Complete the alternate function below.
int alternate(string s) {

    string str = s;
    std::sort(begin(str),end(str));
    auto last = std::unique(begin(str),end(str));
    str.erase(last,str.end());
    vector<tCharPair> list = GetPairOfChar(str);
    int res = 0;
    
        
    for(auto at : list)
    {          
        auto ret  = LengthOfAlternate(s,at);
        if(ret > res)
        {
            res = ret;
        }
    }
    return res;
}

int main()
{


    int result = alternate("beabeefeab");

    cout << result << "\n";


    return 0;
}
