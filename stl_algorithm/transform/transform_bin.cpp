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
    std::vector<int> v_i2={10,50,70,230,50,80,30,80,10};
    std::vector<int> v_o;
    
    
    std::transform(std::cbegin(v_i),std::cend(v_i),std::cbegin(v_i2),std::back_inserter(v_o),[&](const int a, const int b){
            return a+b;
        });
    
    print(v_o);
    return 0;
}
