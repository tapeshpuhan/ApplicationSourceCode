/*
 * Task2.h
 *
 *  Created on: 10-Apr-2018
 *      Author: tapesh
 */
#if 0
#ifndef TASK2_H_
#define TASK2_H_

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stack>
#include<unordered_map>
#include<memory>
#include<thread>
#include<initializer_list>
using namespace std;

template<typename T, typename Method>
class Command
{
	std::map<T,Method> callback_;
	std::thread thread_;
public:
	template<typename ...Arg>
	void exicute(const T &type, Arg ...arg)
	{
		auto at = callback_[type];
		(*at)(arg...);
	}
	Method Instance(const T &type)
	{
		return callback_[type];
	}
	void regCallback(T data, Method fun)
	{
		callback_[data] = fun;
	}
	void UnregCallback(T data)
	{
		auto at = callback_.find(data);

		if(at != callback_.end())
		{
			callback_.erase(at);
		}
	}
};

#endif

#endif /* TASK2_H_ */