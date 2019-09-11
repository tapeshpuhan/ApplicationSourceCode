#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
int Convert(char ch)
{
    return (int)ch - 48;
}

std::vector<int> GetEncoded(const std::string& str)
{
    std::vector<int> out(26,0);
    std::stack<int> store;
    
    size_t size = str.size();

    for(int i = 0;  i< size; ++i)
    {
        //std::cout<<str[i]<<std::endl;
        if(str[i] == '#' && !store.empty())
        {
            auto top = store.top();
            store.pop();
            if(!store.empty())
            {
                auto res = store.top();
                res = res *10 +  top;
                store.pop();
                store.push(res);
            }
        }
        else if(str[i] == ')' && !store.empty())
        {
            int p = 0;
            int result = 0;
            
            while(!store.empty() && store.top()!=Convert('('))
            {
                if(p == 0)
                    result =  result + store.top();
                else
                    result =  result + store.top()*std::pow(10,p);
                p++;
                store.pop();
            }
            if(store.top()==Convert('('))
            store.pop();
            if(!store.empty())
            {
                auto top = store.top();
                
                for(int z = 0; z < result-1; ++z)
                {
                    store.push(top);
                }
            }
        }
        else
        {
            store.push(Convert(str[i]));
        }
    }
    
    while(!store.empty())
    {
        out[store.top()-1]++;
        store.pop();
    }
    return out;        
}

int main()
{
    auto res = GetEncoded("123#(23)4567");
    for(auto a : res)
    {
        std::cout<<a<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
