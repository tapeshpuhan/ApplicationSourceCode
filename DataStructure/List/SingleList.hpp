/*
 * SingleList.h
 *
 *  Created on: 27-Feb-2018
 *      Author: tapesh
 */

#ifndef SINGLELIST_H_
#define SINGLELIST_H_
#include "ListBase.h"
#include "initializer_list"

template<typename T>
class SingleList : public ListBase<T>
{
public:
	struct Node
	{
		T data;
		Node *next;
	};
	SingleList():size(0)
	{
		f = nullptr;
		l = nullptr;

		list = new Node;
		f = list;
		l = list;
	}
	SingleList(initializer_list<T> t):size(0)
	{
		for(auto at : t)
		{
			Insert(at);
		}
	}
	void Insert(T data);
	void Display()
	{
		Node *fast = f;
		cout<<"Display List of Size -> "<<size<<endl;
		while(fast!=nullptr)
		{
			cout<<"value :: "<<fast->data<<endl;
			fast = fast->next;
		}
	}
	~SingleList()
	{
		Node *fast = f;

		while(fast!=nullptr)
		{
			Node *temp = fast;
			fast = fast->next;
			cout<<"delete "<<temp->data<<endl;
			delete temp;
		}
	}
protected:
	Node *f;
	Node *l;
	Node *list;
	int size;
};


template<typename T>
	void SingleList<T>::Insert(T data)
	{

		list = new Node;
		list->data = data;
		list->next = nullptr;
		if(l!=nullptr)
		{
			l->next=list;
			l = list;
		}
		else
		{
			f = list;
			l = list;
		}
		size++;
	}

#endif /* SINGLELIST_H_ */
