/*
 * Stack.cpp

 *
 *  Created on: 24-Mar-2018
 *      Author: tapesh
 */
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
class Stack
{
public:

	typedef T* iterator;
	typedef const T* const_iterator;

	void display()
	{
		for_each(_stack.begin(),_stack.end(),[&](const T &a){cout<<a<<endl;});
	}
	bool Push(const T& data);
	void Pop();
	T& Top();
	bool isEmpty();
	Stack():_size(0){}
	Stack(Stack &obj):_size(0)
	{
		copy(obj.begin(),obj.end(),begin());
	}
	const_iterator begin()const{
		return _stack;
	}
	const_iterator end()const{
		return _stack+_stack.size();
	}

private:

	vector<T> _stack;
	size_t _size;

};
template<typename T>
bool Stack<T>::Push(const T& data)
{

	_stack.push_back(data);
	_size = _stack.size();
	return true;
}
template<typename T>
void Stack<T>::Pop()
{
	if(!isEmpty())
	{
		_stack.pop_back();
		_size = _stack.size();
	}
}
template<typename T>
bool Stack<T>::isEmpty()
{
	return(_size == 0);
}
template<typename T>
T& Stack<T>::Top()
{
	return _stack[_size-1];
}
int main()
{
	Stack<int> s;
	s.Push(100);
	s.Push(200);
	s.Push(300);
	s.Push(400);
	s.display();

	int top = s.Top();
	cout<<"Top "<<top<<endl;

	return 0;
}
#endif
