#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    int sum_ld = s[0][0] + s[1][1] + s[2][2];
    int sum_rd = s[0][2] + s[1][1] + s[2][0];
    vector<int> read_track(9,0);
    int sum = 0;
    
    int max_sum = 15;
    
    if(max_sum == sum_ld)
    {
        max_sum = sum_rd;
        read_track[0*3+2] =1; // index = i *n+j
        read_track[1*3+1] =1;
        read_track[2*3+0] =1;
    }
    if(max_sum == sum_rd) 
    {
        read_track[0*3+0] =1;
        read_track[1*3+1] =1;
        read_track[2*3+2] =1;
    }
        
    
    for(int index= 0; index < 9; ++index)
    {
        if(read_track[index] != 1)
        {
            int row = index/3;
            int col = index%3;
            cout<<row<<" "<<col <<endl;
            int sum_r =0;
            int sum_c =0;
            
            for(int i =0; i < 3; ++i)
            {
                sum_c += s[row][i];
                sum_r += s[i][col];
            }
            if((sum_r != max_sum) && (sum_r == sum_c))
            {                
                sum = sum + (max_sum - sum_r);
                for(int i =0; i < 3; ++i)
                {
                  read_track[row*3+i] = 1;
                  read_track[i*3+col] = 1;
                }                
            }
        }
    }

return sum;    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

  vector<vector<int>> s = {{5, 3, 4},
    {1, 5 ,8},      
    {6, 4, 2}};
    
    //vector<vector<int>> s = {{4 ,9 ,2},
//{3, 5, 7},
//{8, 1, 5}};

   /*vector<vector<int>> s = {{4 ,8 ,2},
    {4, 5, 7},
    {6, 1, 6 }};*/


    int result = formingMagicSquare(s);

    cout << result << "\n";

    fout.close();

    return 0;
}
