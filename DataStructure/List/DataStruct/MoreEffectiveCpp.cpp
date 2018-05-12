/*
 * MoreEffectiveCpp.cpp
 *
 *  Created on: 30-Mar-2018
 *      Author: tapesh
 */

/**
 * What will happen if derive object is filled to base container with base object
 see below example :
 */
#include "BaseFile.h"

class base{
	int i;
public:
	base():i(10)
{
		cout<<"Base"<<endl;
}
	base(base &c)
	{
		cout<<"Base Copy"<<endl;
		i = c.i;
	}
	base & operator =(base &ob)
	{
		cout<<"Base asssignment"<<endl;
		i = ob.i;
		return *this;
	}
	~base()
	{
		cout<<"Base destroctor"<<endl;
	}
	virtual void display()
	{
		cout<<"Display Base"<<i<<endl;
	}
};

class dir:public base
{
	int j;
	public:
	dir():j(10)
	{
			cout<<"dir"<<endl;
	}
	dir(dir &c)
		{
			cout<<"dir Copy"<<endl;
			j = c.j;
		}
	dir & operator =(dir &ob)
		{
			cout<<"dir asssignment"<<endl;
			j = ob.j;
			return *this;
		}
		~dir()
		{
			cout<<"dir destroctor"<<endl;
		}
		void display()
		{
			cout<<"Display Dir"<<j<<endl;
		}
};

void Test1()
{
	dir o1;//,o2,o3,o4,o5;
	vector<base*> v;// = {o1,o2,o3,o4,o5};

	v.push_back(&o1);
	for(auto &at:v)
	{
		at->display();
	}
}
void test2()
{
	vector<int> v1= {2,4,6,2,4,6,4,8,0};
	vector<int> v2={10,45,34,2,4,22,45,232,135,452,345};

	//v1.assign(v2.begin()+(v2.size()/2),v2.end());
	//v1.insert(v1.end(),v2.begin()+v2.size()/2,v2.end());
	//v1.insert(v1.begin()+1,v2.begin()+v2.size()/2,v2.end());
	v1.insert(v1.begin(),7);
	for(auto &at:v1)
	{
		cout<<at<<endl;
	}
}

//string
void test3()
{
	string str = "MYMYMYM NAME IS TAPESWAR PUHAN";

	string::size_type po;

	//po = str.find("IS");
	//po = str.rfind("HA");//pos is from 0 - n but search is from end to begin
	po = str.find_first_of("HA");//ans - , A is in 4th
	po = str.find_first_not_of("MY");//ans - , A is in 4th
	po = str.find_last_of("HA");//ans - , A is in 4th
	//po = str.find_last_not_of("MY");//ans - , A is in 4th
	cout<<"Position  "<<po<<endl;


}

void test4()
{
	//remove charecter from the string
	string str = "MYMYMYM NAME IS TAPESWAR PUHAN";
	//string str = "TAPESWAR";
	string tstr = "N";
	string newStr;

	string::size_type po = str.find(tstr);
	string::size_type cpo = 0;
	string::size_type last = 0;

	while(last != string::npos)
	{
		last = str.find_first_not_of('\0',po);
		newStr += str.substr(cpo, po-cpo);
		cpo = po+1;
		po = str.find(tstr,po+1);

	}
	cout<<newStr.c_str()<<endl;
}
#if 0
int main()
{
	//test2();
	test4();
	return 0;
}
#endif