#include <iostream>
#include <algorithm>
#include<vector>


int main()
{
    std::vector<double> dir{1,2,3,4,45,5,6,7,8};
    
    auto at = std::max_element(dir.cbegin(), dir.cend(),[&](const double& elemt1, const double& elemt2)
    {
        return elemt1 > elemt2;
    });
    
     auto at1 = std::minmax_element(dir.cbegin(), dir.cend(),[&](const double& elemt1, const double& elemt2)
    {
        return elemt1 > elemt2;
    });
    
        std::cout<<*at1.first<<"  "<<*at1.second<<std::endl;
        return 0;
}