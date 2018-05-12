/*
 * BinarySearchTree.cpp
 *
 *  Created on: 14-Mar-2018
 *      Author: tapesh
 */
#include "BinarySearchTree.h"

template<typename T>
void BsTree<T>::Insert(const T &Data)
{
	if(nullptr == root)
	{
		Node *Bt= new Node();
		if(Bt!=nullptr)
		{
			Bt->Data = Data;
			Bt->Left = nullptr;
			Bt->Right = nullptr;
		}
		root = Bt;
	}
	else
	{
		Node *Bt= new Node();
		if(Bt!=nullptr)
		{
			Bt->Data = Data;
			Bt->Left = nullptr;
			Bt->Right = nullptr;
		}

		Node* temp = root; // Create a temp ponter to traverse traa
		Node* pos; // get the position of root node

		while(temp != nullptr)
		{
			pos = temp;// store the postion
			if(Data <= temp->Data)
			{// if value is less equal go left
				temp = temp->Left;
			}
			else
			{// or go right
				temp = temp->Right;
			}
		}
		if(nullptr != pos)
		{
			if(Data <= pos->Data)
			{
				pos->Left = Bt; // if value is less insert in left
			}
			else
			{// insert in right
				pos->Right = Bt;
			}
		}
	}
}


template<typename T>
bool BsTree<T>::Search(const T &info)
{
	Node *temp = root;
	bool found = false;

	while(temp!=nullptr)
	{
		if(temp->Data == info)
		{
			found  = true;
			break;
		}
		if(info <= temp->Data)
		{
			temp = temp->Left; // if value is less insert in left
		}
		else
		{// insert in right
			temp = temp->Right;
		}
	}
	return found;
}

template<typename T>
T & BsTree<T>::  FindMax()
{
	Node *temp = root;
	Node *pos;
	static T a;

	while(temp!=nullptr)
	{
		pos = temp;
		temp = temp->Right;
	}
	if(nullptr!=pos)
		return pos->Data;
	else
		return a;

}
template<typename T>
T & BsTree<T>::  FindMin()
{
	Node *temp = root;
	Node *pos;
	static T a;

	while(temp!=nullptr)
	{
		pos = temp;
		temp = temp->Left;
	}
	if(nullptr!=pos)
		return pos->Data;
	else
		return a;
}
template<typename T>
void BsTree<T>::LabelTraverse()
{
 queue<Node*> que;

 if(root==nullptr)
 {
	 return;
 }
 que.push(root);
 while(!que.empty())
 {
	 Node *cNode = que.front();
	 cout<<cNode->Data<<endl;

	 if(cNode->Left!=nullptr)
	 {
		 que.push(cNode->Left);
	 }
	 if(cNode->Right!=nullptr)
	 {
		 que.push(cNode->Right);
	 }
	 que.pop();
 }
}

int main()
{
	BsTree<int> tree = {50,34,2,345,200,1234,343,345,6};
	tree.Insert(246);

	if(tree.Search(20))
	{
		cout<<"found"<<endl;
	}
	else
	{
		cout<<"Not found"<<endl;
	}
	cout<<"Max "<<tree.FindMax()<<endl;
	cout<<"Min "<<tree.FindMin()<<endl;
	tree.LabelTraverse();
	return 0;
}
