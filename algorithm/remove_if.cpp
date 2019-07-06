#include <vector>
#include <iostream>
#include <algorithm>

template<typename InItr, typename Pred>
InItr RemoveIf(InItr it_begin, InItr it_end, Pred pred)
{
   InItr return_value = it_end;
   InItr end = it_end;
   
   while(it_begin != it_end)
   {
       if(pred(*it_begin))
       {
           InItr i = it_begin;
           for( ; i != end; ++i)
           {
               *i = *(i+1);               
           }
           return_value = i;
           end = i;
       }
     
        ++it_begin;
     
   }

   return return_value;
}


int main()
{
    std::vector<int> vec{1,2,3,4,4,4,6,4};
    //std::vector<int> vec{1,2,3,4,4,5};
    //RemoveIf(vec.begin(),vec.end(),[&](auto& var){return var == 4;});
    vec.erase(RemoveIf(vec.begin(),vec.end(),[&](auto& var){return var == 4;}),vec.end());
    //vec.erase(std::remove_if(vec.begin(),vec.end(),[&](auto& var){return var == 4;}),vec.end());
    
    for(auto&at : vec)
    {
        std::cout<<at<<std::endl;
    }
    
    return 0;
}
