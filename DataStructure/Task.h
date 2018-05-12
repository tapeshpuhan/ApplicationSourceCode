/*
 * Task.h
 *
 *  Created on: 11-Apr-2018
 *      Author: tapesh
 */



#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<set>
#include <limits>
#include<memory>
#include<set>
#include <algorithm>
#include<queue>
#include <mutex>
#include <condition_variable>
#include<thread>
#include <deque>
#include<unordered_map>
#include <functional>
#include<atomic>

using namespace std;

template<typename T>
class comp
{
public:
	bool operator()(T &l, T &r)
	{
		return l>r;
	}
};
template<typename T>
class MesgQ
{
	priority_queue<T,deque<T>,comp<T>> Q_;
public:
	void push(T & p)
	{
		Q_.push(p);
	}
	auto top()->decltype(Q_.top())
	{
		 return Q_.top();
	}
	auto empty()->decltype(Q_.empty())
	{
		 return Q_.empty();
	}
	void pop(){
		Q_.pop();
	}
};
/**************
 *
 */
