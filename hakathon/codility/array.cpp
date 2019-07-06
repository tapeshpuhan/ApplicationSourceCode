#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    set<int> availabe_elements{A.begin(),A.end()};
    
    for(const auto& at : availabe_elements)
    {
        auto count = std::count(A.begin(),A.end(),at);
        
        if(count%2 == 1)
        {
            return at;
        }
    }
    return 0;
}

int main()
{
    vector<int>  A{9,3,9,3,9,7,9};
    cout<<solution(A)<<endl;
    return 0;
}
