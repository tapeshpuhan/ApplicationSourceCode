/*
 * MapUse.cpp
 *
 *  Created on: 14-Mar-2018
 *      Author: tapesh
 */
#include"MapUse.h"

template<typename T>
void MapUse<T>::SortList(list<T> &value, const vector<T> &ref)
{
	for(const auto &at : value)
	{
		uMap[at]++;
	}
	value.clear();
	for(const auto &at : ref)
	{
		int fre = uMap[at];
		while(fre!=0)
		{
			value.push_back(at);
			fre--;
		}
	}
}

int main()
{
	vector<int> ref = {2,6,8,3,9,5};
	list<int> arry= {6,3,1,4,2,6,9,8,2};

	for(auto &at : ref)
	{
		cout<<at<<"  ";
	}
	cout<<endl;
	cout<<"Before sorting"<<endl;
	for(auto &at : arry)
	{
		cout<<at<<endl;
	}
	MapUse<int> bj;
	bj.SortList(arry,ref);
	cout<<"After sorting"<<endl;
	for(auto &at : arry)
	{
		cout<<at<<endl;
	}
}
