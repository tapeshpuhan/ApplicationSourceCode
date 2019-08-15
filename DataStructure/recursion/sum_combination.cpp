#include <iostream>
#include <math.h>
using namespace std;

int powerSum(int X, int P, int N=1) {
    int i_pow = pow(N,P);
    if (i_pow > X)
        return 0;
    else if (i_pow == X)
        return 1;
      // subproblem
    int x =  powerSum(X,P,N+1);
    int y =  powerSum(X-i_pow,P,N+1);
    cout<<x<<" : "<<y<<endl;
    return x+y;
}

int main()
{
    std::cout<<powerSum(100,2)<<std::endl;
    return 0;
}
