#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template<typename ForwarItr>
ForwarItr Unique(ForwarItr first, ForwarItr last)
{
    if(first == last)
        return last;
    
    ForwarItr result = first;
    while(++first != last)
    {
        cout<<*first<<" : "<<*result<<endl; 
        
        if (!(*result == *first) && ++result != first) {
             cout<<"----"<<endl;          
            *result = std::move(*first);
        }
    }
    return ++result;
}

int main()
{
    string name{"Tapeaaaswar"};
    
    //Unique(name.begin(),name.end());
    auto at = Unique(name.begin(),name.end());
    cout<<name<<endl;
    name.erase(at,name.end());
    cout<<name<<endl;
    return 0;
}
