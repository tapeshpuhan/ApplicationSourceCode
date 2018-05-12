/*
 * Auto.cpp
 *
 *  Created on: 17-Mar-2018
 *      Author: tapesh
 */
#include<iostream>
using namespace std;

void testAutoType()
{
	int x=0; //declare x type
	const int &crx=x; //declare const ref type
	auto aCrx = crx;

	x = 42;
	cout<<"Before modification aCrx "<<aCrx<<" crx "<<crx<<" x "<<x<<endl;
}
// test auto as referance
void testAutoType_1()
{
	int x=0; //declare x type
	const int &crx=x; //declare const ref type
	auto &aCrx = crx;

	x = 42;
	cout<<"Before modification aCrx "<<aCrx<<" crx "<<crx<<" x "<<x<<endl;
}
//test auto as const referance
void testAutoType_2()
{
	int x=0; //declare x type
	const int &crx=x; //declare const ref type
	const auto &aCrx = crx;

	x = 42;
	cout<<"Before modification aCrx "<<aCrx<<" crx "<<crx<<" x "<<x<<endl;
}
void testAutoType_3()
{
	cout<<"Test as const vs auto"<<endl;
	const int i = 100;
	auto ain = i;

	cout<<"i "<<i<<" ain "<<ain<<endl;
	ain = 200;
	cout<<"i "<<i<<" ain "<<ain<<endl;
}
void testAutoType_4()
{
	cout<<"Test as const vs auto"<<endl;
	const int i = 100;
	auto &ain = i;

	cout<<"i "<<i<<" ain "<<ain<<endl;
	//ain = 200; /*It Is Not Possible to change constant refrance*/
	cout<<"i "<<i<<" ain "<<ain<<endl;
}
void testAutoRvalue()
{
	int i = 0;
	auto && a_r1 = i;//lvalue;
	auto && a_r2 = 43;//rvalue

	cout<<"testAutoRvalue"<<endl;
	cout<<" i "<<i<<" ar1"<<a_r1<<"  a_r2 "<<a_r2<<endl;
}
void testAutoConstPtr()
{
	int i = 0;
	const int *p = &i;
	auto cp = p;

	/**
	 * Auto for Constanct pointer is differs behaviour for constant referance.
	 */
	//*cp =100;
	cout<<"testAutoConstPtr"<<endl;
	cout<<" i "<<i<<" *p"<<*p<<"  cp "<<*cp<<endl;
}

template<typename T, typename U>
void fun(T var1, U var2)
{
	auto pVar = var1 * var2;
	cout<<"fun :: "<<pVar<<endl;
}

template<typename T, typename U>
auto funReturn(T var1, U var2) ->decltype(var1*var2)
{
	auto pVar = var1 * var2;

	return pVar;
}


int main()
{
	testAutoType();
	testAutoType_1();
	testAutoType_2();
	testAutoType_3();
	testAutoType_4();
	testAutoRvalue();
	testAutoConstPtr();
	fun(2, 5.2);

	cout<<"funReturn :: "<<funReturn(2,5.6)<<endl;
	return 0;
}



