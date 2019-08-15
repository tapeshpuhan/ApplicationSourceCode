#include <iostream>


int febonacy(int n)
{
    if(n <= 1)
    {
        return n;
    }
    else
    {
        return febonacy(n-2) + febonacy(n-1);
    }
}

int Combination(int n, int r)
{
    if(r == 0 || r==n)
    {
        return 1;
    }
    else
    {
        return Combination(n-1,r) + Combination(n-1,r-1);
    }
}

int main()
{
 
 std::cout<<  Combination(5,1)<<std::endl; 
    return 0;
}
