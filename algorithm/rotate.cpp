#include <iostream>
#include <algorithm>
#include <vector>


template<typename Itr>
Itr Rotate(Itr First, Itr n_loc, Itr last)
{
    Itr tFirst = First;
    
    while(tFirst != n_loc)
    {
        Itr res = First; 
        Itr temp = First;
        Itr prev;
        auto temp_value = *First;
        while(res++ != last)
        {
            *temp = *res;
            prev = temp;
            temp++;                       
        }
        *prev = temp_value;
        
        tFirst++;
    }
    return First + (last-n_loc);
}

int main()
{
    std::vector<int> v{1,2,3,5,7,8,9};
    
    Rotate(begin(v),begin(v)+8,end(v));
    for(auto&at : v)
    {
        std::cout<<at<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
