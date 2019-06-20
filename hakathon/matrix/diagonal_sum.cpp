#include <bits/stdc++.h>

using namespace std;

// Complete the diagonalDifference function below.
int diagonalDifference(vector<vector<int>> arr) {
    
    size_t l_r = arr.size();
    int sum_l = 0;
    int sum_r = 0;
    if(l_r)
    {
        size_t l_c = arr.at(0).size();
        l_c = l_c - 1;
        
        
        for(auto i = 0 ; i < l_r; ++i)
        {
            auto j = i;
            sum_l += arr[i][j];
            sum_r += arr[i][l_c - j];            
        }
    }
    return std::abs(sum_l - sum_r);

}

int main()
{

    vector<vector<int>> arr = {{1,2,3},{4,5,6},{9,8,9}};
    int result = diagonalDifference(arr);
    cout << result << "\n";
    return 0;
}
