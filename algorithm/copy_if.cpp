#include <vector>
#include <iostream>
#include <iterator>

template<typename InItr, typename OutItr,typename Pred>
OutItr CopyIf(InItr it_begin, InItr it_end,OutItr output, Pred pred)
{
    while(it_begin != it_end)
    {
        if(pred(*it_begin))
        {
           *output++ = *it_begin;
        }
        it_begin++;
    }
    
    return output;
}

int main()
{
    std::vector<int> from_vector{1,2,4,5,6,7,8,3,4,5,6,7,4};
    std::vector<int> to_vector;
    
    CopyIf(from_vector.begin(),from_vector.end(),std::back_inserter(to_vector),[&](auto var){return var <= 4;});
    
    for(auto& at : to_vector)
    {
        std::cout<<at<<std::endl;
    }
    return 0;
}
