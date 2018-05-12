/*
 * ListBase.h
 *
 *  Created on: 27-Feb-2018
 *      Author: tapesh
 */

#ifndef LISTBASE_H_
#define LISTBASE_H_
#include<memory>
#include<iostream>
using namespace std;

template<typename T>
class ListBase
{
public:

	virtual void Insert(T data) = 0;
	virtual void Display()=0;
virtual ~ListBase(){}
};


#endif /* LISTBASE_H_ */
