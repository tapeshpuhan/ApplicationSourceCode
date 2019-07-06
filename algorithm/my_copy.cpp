#include <iostream>
#include <vector>
#include <string>

template<typename FastItr>
FastItr UniQue(FastItr first, FastItr last)
{
    if(first == last)
    {
        return last;
    }
    FastItr result = first;
    
    while(first++ != last)
    {
        if(!(*first == *result))
        {
            result++;
            if(result != first)
            {
                *result = *first;
            }
            
        }
    }
    return result++;
}

template<typename FastItr, typename Pred>
FastItr UniQue(FastItr first, FastItr last, Pred p)
{
    if(first == last)
    {
        return last;
    }
    FastItr result = first;
    
    while(first++ != last)
    {
        if(!p(*first ,*result))
        {
            result++;
            if(result != first)
            {
                *result = *first;
            }
            
        }
    }
    return result++;
}

template<class ForwardIt, class BinaryPredicate>
ForwardIt unique(ForwardIt first, ForwardIt last, BinaryPredicate p)
{
    if (first == last)
        return last;
 
    ForwardIt result = first;
    while (++first != last) {
        if (!p(*result, *first) && ++result != first) {
            *result = std::move(*first);
        }
    }
    return ++result;
}

int main()
{
    std::string name {"Tapeaaaswar"};
    
    name.erase(unique(name.begin(),name.end(),[](char a, char b){return a != b;}),name.end());
    
    std::cout<<name<<std::endl;
    
    return 0;
}
