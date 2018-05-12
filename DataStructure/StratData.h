#include<iostream>

#include <iostream>
#include <memory>
using namespace std;

#define ARRAY_SIZE 4

template<typename T>
class MyArray
{
private:
	T *_array;
	size_t _size;
	size_t _reSize; 
	void resize(const int n);
public:
	MyArray():_array(new T[ARRAY_SIZE]),_size(0),_reSize(ARRAY_SIZE){}
	MyArray(int n):_array(new T[n]),_size(0),_reSize(n){}
	~MyArray(){
		delete []_array;
	}
	T& operator[](int n)
	{
		return _array[n];
	}
	void push_back(const T &value);
	void pup_back();
	size_t size(){
		return _size;
	}

};




