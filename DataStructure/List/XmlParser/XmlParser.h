/*
 * XmlParser.h
 *
 *  Created on: 08-Apr-2018
 *      Author: tapesh
 */
#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<map>
using namespace std;

using tBook = struct BookInfo
		{
	string id;
	string author;
	string titel;
	string genre;
	string price;
	string Date;
	string note;
		};

class XmlPars
{
	map<string,tBook> _parse;
public:
	void ParseXml(const string &path);
	void getBookInfo(map<string,tBook> &op, ifstream &file,const string &end);
};

template<typename T>
class myPtr
{
	T *ptr;
public:
	myPtr():ptr(new T)
	{

	}
	explicit myPtr(T *p):ptr(p){}
	myPtr(myPtr &op)
	{
		if(this!=op)
		{
			if(ptr!=nullptr)
			{
				delete ptr;
			}
			ptr = op.ptr;
		}
	}
	myPtr &operator=(T &op)
	{
		if(this!=op)
		{
			if(ptr!=nullptr)
			{
				delete ptr;
			}
			ptr = op.ptr;
		}
		return *this;
	}
	myPtr(myPtr &&op):ptr{op.ptr}
	{
		if(nullptr !=op.ptr)
		delete op.ptr;
	}
	myPtr &operator=(T &&op)
	{
		if(nullptr !=op.ptr)
		{
		ptr = op.ptr;
		delete op.ptr;
		}
		return *this;
	}
	T* operator->()
	{
		return ptr;
	}
	T& operator*()
	{
		return *ptr;
	}
	~myPtr()
	{
		delete ptr;
	}
};
