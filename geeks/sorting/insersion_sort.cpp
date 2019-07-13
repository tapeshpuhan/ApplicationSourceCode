#include <vector>
#include <iostream>
#include <string>

// sort the element by its proper position
template<typename Type>
void Sort(std::vector<Type>& list)
{
    for(int i=1; i< list.size(); ++i)
    {        
        int pos = i;
        for(int j = i-1;j >=0; --j)
        {
            if(list[j] > list[pos])
            {
                    Type val = list[pos];
                    list[pos] = list[j];
                    list[j] = val;    
                    pos = j;
            }
        }
    }
}

int main()
{
    std::vector<int> list{65,25,12,22,11,12};
    Sort(list);
    for(auto&at : list)
    {
        std::cout<<at<<std::endl;
    }
    return 0;
}
