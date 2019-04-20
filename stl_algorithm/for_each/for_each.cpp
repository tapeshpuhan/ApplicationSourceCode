#include <iostream>
#include <algorithm>
#include<vector>


int main()
{
    std::vector<int> dir{1,2,3,4,5,6,7,8};
    
    
    /// using for_each value of the variable can be changed .
    std::for_each(dir.begin(), dir.end(), [&](int& a )
    {
        std::cout<<a<<std::endl;
        a = a+10;
    }
    );
    
    for(auto &at : dir)
    {
        std::cout<<at<<std::endl;
    }
    
    return 0;
}