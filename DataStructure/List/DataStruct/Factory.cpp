/*
 * Factory.cpp
 *
 *  Created on: 30-Mar-2018
 *      Author: tapesh
 */
#if 0
#include "BaseFile.h"

template<typename T, class C>
class Factory
{
	map<T,C> fac;
public:
	void regFact(T type, C ptr)
	{
		fac.insert(pair<T,C>(type,ptr));
	}
	C getFactory(T type)
	{
		return fac[type];
	}
};
class base
{
public:
	virtual void f()=0;
	virtual ~base(){}
};

class dir1:public base
{
public:
	void f()
	{
		cout<<"f() : dir1"<<endl;
	}
};
class dir2:public base
{
public:
	void f()
	{
		cout<<"f() : dir2"<<endl;
	}
};

int main()
{

	Factory<int,shared_ptr<base>> factory;
	shared_ptr<base> d = make_shared<dir1>();
	shared_ptr<base> d1 = make_shared<dir2>();
	string s1 = "dir1";

	//factory.regFact(s1,d);

	factory.regFact(1,d);
	factory.regFact(2,make_shared<dir2>());

	factory.getFactory(1)->f();
	factory.getFactory(2)->f();
	return 0;
}
#endif
