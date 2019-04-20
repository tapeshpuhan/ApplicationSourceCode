#include <iostream>
#include <algorithm>
#include<vector>


int main()
{
    std::vector<double> dir{1,2,3,4,5,6,7,8};
    
    doublec  count = std::count(dir.cbegin(), dir.cend(), 2);
    
        std::cout<<count<<std::endl;
        return 0;
}