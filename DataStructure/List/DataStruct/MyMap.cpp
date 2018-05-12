/*
 * MyMap.cpp
 *
 *  Created on: 31-Mar-2018
 *      Author: tapesh
 */

#include "BaseFile.h"
#if 0
template<typename T,typename U>
class MyMap
{
private:
	map<T,U,T> _map;
public:
	MyMap(){}
	MyMap(const initializer_list<T> &list)
{
		for(auto &at:list)
		{
			_map.insert(pair<T,U>(at.first,at.second));
		}
}
	MyMap(MyMap &rh)
	{
		_map = rh._map;
	}
	MyMap(MyMap &&rh):_map {rh._map}
	{

	}
	auto insert(T d1, U d2)->decltype(_map.insert(pair<T,U>(d1,d2)))
	{
		return _map.insert(pair<T,U>(d1,d2));
	}
	auto begin()->decltype(_map.begin())
	{
		return _map.begin();
	}
	auto end()->decltype(_map.begin())
	{
		return _map.end();
	}
};

class test
{
	int roll;
public:
	test(){}
	test(int g):roll(g){}
	int get(){return roll;}
	bool operator()(const test &l, const test &r)
	{
		return l.roll < r.roll;
	}
};

class comp
{
public:

};
int main()
{
	test o1(111),o2(123),o3(100),o4(9);
	MyMap<test,int> var;

	var.insert(o1,23);
	var.insert(o2,230);
	var.insert(o3,234);
	var.insert(o4,89);

	for(auto &at : var)
	{
		cout<<" data "<<at.second<<endl;
	}
	MyMap<int,int> var2;
	var.insert(100,23);
	for(auto &at : var2)
	{
		cout<<" No "<<at.second<<endl;
	}
	return 0;
}
#endif
