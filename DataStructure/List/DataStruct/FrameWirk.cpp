/*
 * FrameWirk.cpp
 *
 *  Created on: 04-Apr-2018
 *      Author: tapesh
 */
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

class HmiCommand
{
public:
	virtual void operator()(string str) =0;
	virtual ~HmiCommand(){}
};

class HmiPlay:public HmiCommand
{
public:
	void operator()(string str)
	{
		cout<<"play"<<str.c_str()<<endl;;
	}
};
class HmiPause:public HmiCommand
{
public:
	void operator()(string str)
	{
		cout<<"pause"<<str.c_str()<<endl;;
	}
};
class HmiStop:public HmiCommand
{
public:
	void operator()(string str)
	{
		cout<<"stop : "<<str.c_str()<<endl;
	}
};
#if 0
int main()
{
	Command<string,shared_ptr<HmiCommand>> _play;

	_play.regCallback(string("PLAY"),make_shared<HmiPlay>());
	_play.regCallback(string("PAUSE"),make_shared<HmiPause>());
	_play.regCallback(string("STOP"),make_shared<HmiStop>());
	_play.exicute("PLAY",string("fiel.mp3"));
	_play.exicute("PAUSE",string("fiel.mp3"));

	return 0;
}
#endif