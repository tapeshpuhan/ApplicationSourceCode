#include <bits/stdc++.h>

using namespace std;

long Update(vector<long>& out, int from, int to, int value)
{
    long count = 0;
    for(auto i = from-1; i < to-1; ++i)
    {
        out[i]+=value;
        
        if(count < out[i])
        {
            count = out[i];
        }
    }
    return count;
}

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> out(n,0);
    long res = 0;
    
    for(auto& at : queries)
    {
        if(at.size() == 3)
        {
           auto temp_res =  Update(out,at[0],at[1],at[2]);
           if(temp_res > res)
           {
               res = temp_res;
           }
        }
    }
    return res;

}


int main()
{
    vector<vector<int>> queries = {{1,5,3},{4,8,7},{6,9,1}};
    cout<<arrayManipulation(10,queries)<<endl;
}
