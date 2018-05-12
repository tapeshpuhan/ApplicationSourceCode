/*
 * BinarySearchTree.h
 *
 *  Created on: 14-Mar-2018
 *      Author: tapesh
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include<iostream>
#include<string>
#include<initializer_list>
#include<queue>
using namespace std;

template<typename T>
class BsTree
{
	struct Node
	{
		T Data;
		Node *Left;
		Node *Right;
		Node():Left(nullptr),Right(nullptr){}
		Node(T data):Data(data),Left(nullptr),Right(nullptr){}
	};
	Node *root;
public:
	BsTree(const initializer_list<T> &list):root(nullptr)
	{
		for(const auto at : list)
		{
			Insert(at);
		}
	}
	BsTree():root(nullptr){}
	void Insert(const T &info);
	bool Search(const T &info);
	T &  FindMax();
	T &  FindMin();
	void LabelTraverse();
};



#endif /* BINARYSEARCHTREE_H_ */