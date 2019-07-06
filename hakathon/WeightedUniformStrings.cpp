#include <bits/stdc++.h>

using namespace std;

vector<int> GeTWaight(string s)
{
        vector<int> out;
        int prev_waight = 0;
        char prev_char = 0;
        
        for(auto& at : s)
        {
            if(islower(at))
            {
                auto waight = at-96;
                if(prev_char == at)
                {
                    waight = prev_waight + waight;                                        
                }
                prev_waight = waight;

                out.push_back(waight);                
            }
            prev_char = at;
        }
        return out;
        
}

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<int> wait = GeTWaight(s);
    vector<string> out;
        
    for(auto& at : queries)
    {
        if(std::find(begin(wait),end(wait),at) != end(wait))
        {
            out.push_back("YE");
        }
        else
        {
            out.push_back("NO");
        }
    }
    return out;
}

int main()
{
   vector<string> result = weightedUniformStrings("aaabbbbcccddd", {9,7,8,12,5});
    for(auto& at : result)
    {
        cout<<at<<endl;
    }
    return 0;
}
