#include <iostream>
#include <vector>
#include <algorithm>

template<typename Type>
std::pair<size_t,bool> BinarySearch(const std::vector<Type>& output, const Type& value) 
{   
    std::pair<size_t,bool> result{false,0};
    size_t first = 0;
    size_t last = output.size();
    size_t mid = 0;
    
    
    while(first <= last)
    {        
        mid = (first+last)/2;
        if(output.at(mid) == value)
        {
            result = std::make_pair(mid,true);
            break;
        }
        else if(output.at(mid) < value)
        {
            first = mid+1;
        }
        else
        {
            last = mid-1;
        }
    }
    
    return result;
}

int main()
{
    std::vector<int> list{0,1,3,5,34,78,100,123};
    int value = 123;
    auto res = BinarySearch(list,value);
    std::cout<<res.first<<" :: "<<res.second<<std::endl;
    return 0;
}
