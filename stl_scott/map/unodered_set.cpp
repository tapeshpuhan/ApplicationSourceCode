#include <iostream>
#include <unordered_set>
#include <algorithm>

int main()
{
    std::unordered_set<int> coll{1,2,3,4,5,3,5,7,3};
    
    auto ret = coll.emplace_hint(coll.begin(), 100);
    for(const auto& at : coll)
    {
        std::cout<<at<<std::endl;
    }
    //std::cout<<"return "<<*ret.first<<" : "<<ret.second<<std::endl;
   /* for(auto at = coll.rbegin(); at != coll.rend(); ++at)
    {        
        std::cout<<*at<<std::endl;
    }*/
    //std::remove(coll.begin(),coll.end());
    return 0;
}
