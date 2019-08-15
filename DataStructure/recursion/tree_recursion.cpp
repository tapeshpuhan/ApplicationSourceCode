#include <iostream>
#include <deque>
using namespace std;

int fun(int m , int n)
{
    if(n > 1)
    {
        return m * fun(m, n-1);
    }
}

int e(int x, int n)
{
    static int pow =0;
    static int fact =0;
    int res = 1;
    
    if(n > 0)
    {
        res =  e(x,n-1);
        pow = pow * x;
        fact = fact * n;
        
        return res+pow/fact;;
    }
}

int main()
{

    cout<<e(5,5)<<endl;

}
