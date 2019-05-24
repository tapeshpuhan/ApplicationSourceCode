#include <iostream>
#include <vector>

void print(std::vector<std::vector<int>>& matrix)
{
    for(auto& at : matrix)
    {
        for(auto& bt : at)
        {
            std::cout<<bt <<" ";
        }
        std::cout<<std::endl;
    }
}
void RoatateClockWise(std::vector<std::vector<int>>& matrix)
{
    auto row_num = matrix.size();
    if(row_num)
    {
        auto col_num = matrix[0].size();
        
        for(int i = 0; i < row_num/2; ++ i)
        {
            for(int j = i ; j < col_num-1-i; ++j)
            {
                auto t = matrix[i][j];
                matrix[i][j] = matrix[row_num-1-j][i];
                matrix[row_num-1-j][i] = matrix[j][row_num-1-i];
                
                matrix[j][row_num-1-i] = t;
            }
        }
    }
}
void rotate90Clockwise(std::vector<std::vector<int>>& a) 
{ 
  int N = a.size();
    // Traverse each cycle 
    for (int i = 0; i < N / 2; i++) { 
        for (int j = i; j < N - i - 1; j++) { 
  
            // Swap elements of each cycle 
            // in clockwise direction 
            int temp = a[i][j]; 
            a[i][j] = a[N - 1 - j][i]; 
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j]; 
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i]; 
            a[j][N - 1 - i] = temp; 
        } 
    } 
} 
int main()
{
   std::vector<std::vector<int>> op = {{1,2,3},{4,5,6},{7,8,9}};
   rotate90Clockwise(op);
    print(op);
return 0;
}
