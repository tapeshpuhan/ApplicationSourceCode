/*
 * framework.h
 *
 *  Created on: 04-Apr-2018
 *      Author: tapesh
 */

#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#include "basetype.h"
/**
 *
 *
 * */

template<typename T, typename Method>
class Command
{
	std::map<T,Method> callback_;
public:
	template<typename ...Arg>
	void exicute(T type, Arg ...arg)
	{
		auto at = callback_[type];
		(*at)(arg...);
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




#endif /* FRAMEWORK_H_ */
