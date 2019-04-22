#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

template<typename T>
void print(T&& var)
{
    for(auto& at : var)
    {
        std::cout<<at<<std::endl;
    }
}

int main()
{
    std::set<int> v_ = {1,2,3,4,5,7,8,9,3,7,8,};
    std::vector<int> s_;
    
    std::move(v_.begin(),v_.end(),std::back_inserter(s_));
    //std::copy(v_.cbegin(),v_.cend(),s_.begin());
    print(s_);
    print(v_);
    return 0;
}
