/*
 * List.cpp
 *
 *  Created on: 18-Mar-2018
 *      Author: tapesh
 */

#include "List.h"

template<typename T>
void List<T>::Insert(T data)
{
	tList *ptr = new tList;
	if(ptr!=nullptr)
	{
		ptr->data = data;
		ptr->next = nullptr;		

		if(nullptr == first)
		{
			first = ptr;
			last = ptr;
		}
		else
		{

			last->next=ptr;			
			last=ptr;

		}
	}
}

template<typename T>
void List<T>::Display()
{
	tList *temp = first;

	cout<<"Elemets are"<<endl;
	while(temp!=nullptr)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

template<typename T>
void List<T>::DisplayRec()
{
    Display(first);
}

template<typename T>
void List<T>::Display(tList *first)
{
    if(first == nullptr)
    {
        return ;
    }
    else
    {
        std::cout<<first->data<<std::endl;
        Display(first->next);
    }
}

template<typename T>
void List<T>::Reverse()
{
    tList *t1 = first;
    tList *t2 = nullptr;
    tList *t3 = nullptr;
    
    while(t1 != nullptr)
    {
        t2 = t1->next;
        t1->next = t3;
        t3 = t1;
        t1 = t2;
    }
    first = t3;
}

int main()
{
	List<int> list = {2,5,67,84,2,5,74,67};
	List<int> list2 = {200,500,670,840,200,500,740,670};
	list.DisplayRec();
    list.Reverse();
    std::cout<<"Reversed "<<std::endl;
    list.DisplayRec();
	/*list +=  list2;
	list.DisplayRec();*/
	return 0;
}
