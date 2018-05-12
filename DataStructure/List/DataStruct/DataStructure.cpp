/*
 * DataStructure.cpp
 *
 *  Created on: 31-Mar-2018
 *      Author: tapesh
 */
#include "BaseFile.h"


int dec_bin(size_t d)
{
	for(size_t i = 0; i < sizeof(size_t)*8;i++)
	{
		int c =(d>>i)&1;
		cout<<c<<" ";
		if((i+1)%4 == 0)
		{
			cout<<"    ";
		}
	}
	return 0;
}

int fun_xn(int x,int n)
{
if(n<1)
	return 1;
return x * fun_xn(x,n-1);
}

template<class T>
class BinarySearch
{
public:
	size_t search(T data, const vector<T> &array);
};

template<class T>
size_t BinarySearch<T>::search(T data, const vector<T> &array)
{
	size_t mid = 0;
	size_t min = 0;
	size_t max = array.size();

	while(min<max)
	{
		mid = (min+max)/2;
		if(data == array[mid])
		{
			return mid;
		}
		if(data<array[mid])
		{
			max = mid-1;
		}
		else
		{
			min = mid+1;
		}
	}
	return -1;
}
#if 0
int main()
{
	//dec_bin(2000);
	//cout<<fun_xn(5,3)<<endl;
	BinarySearch<int> search;
	vector<int> v = {23,56,67,78,89};
	cout<<"position "<<search.search(678,v)<<endl;
	return 0;
}
#endif




