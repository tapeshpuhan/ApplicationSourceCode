/*
 * List.cpp
 *
 *  Created on: 26-Mar-2018
 *      Author: tapesh
 */

#if 0
#include<iostream>
#include<string>
#include<memory>
#include<initializer_list>
using namespace std;

template<typename T>
class sList
{
	using tList = struct Node
			{
				shared_ptr<Node> Next;
				T data;
				Node():Next(nullptr){}
			};
	shared_ptr<tList> head;
	shared_ptr<tList> tail;
public:
	sList(const initializer_list<T> &list):head(nullptr),tail(nullptr)
	{
		for(const auto& at : list)
		{
			Insert(at);
		}
	}
	void Insert(T data);
	void sReverse();
	void iReverse();
	void Display();
};

template<typename T>
void sList<T>::Insert(T data)
{
	shared_ptr<tList> ptr = make_shared<tList>();
	if(ptr!=nullptr)
	{
		ptr->data = data;

		if(nullptr == head)
		{
			head = ptr;
			tail = ptr;
		}
		else
		{
			tail->Next=ptr;
			tail=ptr;
		}
	}
}

template<typename T>
void sList<T>::Display()
{
	shared_ptr<tList> temp = head;

	cout<<"Elemets are"<<endl;
	while(temp!=nullptr)
	{
		cout<<temp->data<<" ";
		temp = temp->Next;
	}
	cout<<endl;
}
template<typename T>
void sList<T>::sReverse()
{

}
template<typename T>
void sList<T>::iReverse()
{
	shared_ptr<tList> temp = head;
	tail = head;

	while(temp!=nullptr)
	{
		if(temp == head)
		{
			temp = temp->Next;
			tail->Next = nullptr;
		}
		else
		{
			shared_ptr<tList> x = temp;
			temp = temp->Next;
			x->Next = tail;
			tail = x;
		}
	}
	head = tail;
}
int main()
{
	sList<int> list = {2,5,67,84,2,5,74,67};

	list.Display();
	list.iReverse();
	list.Display();
	return 0;
}
#endif
