#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <functional>

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
    std::vector<int> v_i={1,5,7,23,5,8,3,8,0};
    std::vector<int> v_o;
    
    
    std::transform(std::cbegin(v_i),std::cend(v_i),std::back_inserter(v_o),[&](const int a){
            return 1;
        });
    
    print(v_o);
    return 0;
}
