#include "StratData.h"

template<typename T>
void MyArray<T>::push_back(const T &value)
{
	if(_size == _reSize)
	{
		resize(_size+ARRAY_SIZE);
	}
	_array[_size] = value;
	_size++;
}

template<typename T>	
void MyArray<T>::resize(const int n)
{
	if(n > _reSize)
	{
		T *newArray = new T[n];
		for(int i = 0 ; i < _size; i++)
		{
			newArray[i] = _array[i];
		}
		delete []_array;
		_array = newArray;
		_reSize = n;
	}
}
template<typename T>
void MyArray<T>::pup_back()
{
if(_size>0)
{
	//T &sp = _array[_size-1];
	_size--;
	
}
  
}

int main()
{
cout<<"MyFirst Data Structure"<<endl;
MyArray<int> Array;

Array.push_back(10);
Array.push_back(20);
Array.push_back(30);
Array.push_back(10);
Array.push_back(20);
Array.push_back(30);
Array.push_back(10);
Array.push_back(20);
Array.push_back(30);
Array.push_back(10);
Array.push_back(20);
Array.push_back(30);
for(int i = 0; i< Array.size();i++)
{
  cout<<Array[i]<<endl;
}
Array.pup_back();
Array.pup_back();
Array.pup_back();
Array.pup_back();
Array.pup_back();
Array.pup_back();
Array.pup_back();

cout<<"MyFirst Data Structure"<<endl;
for(int i = 0; i< Array.size();i++)
{
  cout<<Array[i]<<endl;
}
return 0;
}
