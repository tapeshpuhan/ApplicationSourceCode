/*
 * Task.cpp
 *
 *  Created on: 11-Apr-2018
 *      Author: tapesh
 */

#include"Task.h"

bool isDuplicate(const vector<int> &v)
{
	std::map<int,int> m;

	for(auto &at:v)
	{
		m[at]++;
		if(m[at]>1)
		{
			return false;
		}
	}
	return true;
}

class stack
{
	double y;
	int x;
public:
	stack(){}
	stack(int y):x(y){
	cout<<x<<endl;
	cout<<y<<endl;
	}
};
class A
{};
/*
int main()
{
	A b;
	stack a;
	a =1100;
	return 0;
}
*/