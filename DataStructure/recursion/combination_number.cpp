/*
 * This part of the code deal with finding combination of number of letters from
 * the set of number .
 * 
 * For Example : A B C D E F , total number is 5 
 * Qustion is How many combination of 3 letters can be created from the given set of letter .
 * 
 * N = 5 and R =3 
 * formula to find the combination is (N!) /(R!*(N-R)!);
 * or by recursion using pascales trangel.
 * beclow method is to find the combition to find pascales trangle
 * */
#include <iostream>

int GetNCR(int total_number, int set_number)
{
    if((set_number == 0) || (total_number == set_number))
    {
        return 1;
    }
    else
    {
        return GetNCR(total_number-1 , set_number-1) + GetNCR(total_number-1 , set_number);
    }
}

int main()
{
    std::cout<<"Get combination od sets "<<GetNCR(5,3)<<std::endl;
    return 0;
}
