/*
 * Move.cpp
 *
 *  Created on: 22-Mar-2018
 *      Author: tapesh
 */
#if 0
#include<iostream>
#include<vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Widget
{
	//int *ptr;
	const int value = 10;
	int c;

public:
	Widget(int p):/*ptr(new int[value]),*/c(p){
		cout<<"constructor"<<endl;
	}

	Widget(const Widget &rhs)/*:ptr(new int[value])*/
	{
		cout<<"Copy Constructer"<<endl;
		//memcpy(ptr,rhs.ptr,sizeof(int)*value);
		c = rhs.c;
	}
	Widget& operator=(const Widget &rhs)
	{
		cout<<"Copy Assignment operator"<<endl;
		//memcpy(ptr,rhs.ptr,sizeof(int)*value);
		c = rhs.c;
		return *this;
	}
	Widget(Widget &&rhs)/*:ptr(new int[value])*/
	{
		cout<<"Move Copy Constructer"<<endl;
		//memcpy(ptr,rhs.ptr,sizeof(int)*value);
		c = rhs.c;
	}
	Widget& operator=(Widget &&rhs)
	{
		cout<<"Move Copy Assignment operator"<<endl;
		//memcpy(ptr,rhs.ptr,sizeof(int)*value);
		c = rhs.c;
		return *this;
	}
	bool operator<(Widget &rhs)
	{
		return c < rhs.c;
	}
	~Widget()
	{
		//delete[] ptr;
	}
};

int main()
{
	Widget v1(10);
	Widget v2(100);
	Widget v3(10000);
	Widget v4(1000);
	Widget v5(100000);
	//vector<Widget> l = {move(v1),move(v2),move(v3),move(v4),move(v5)};
	vector<Widget> l;
	l.push_back(move(v1));
	l.push_back(v2);
	sort(std::begin(l),std::end(l));
	return 0;
}
#endif
