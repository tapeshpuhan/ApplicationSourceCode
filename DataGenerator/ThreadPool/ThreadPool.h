/*
 * ThreadPool.h
 *
 *  Created on: 08-May-2018
 *      Author: tapesh
 */

#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include <map>
#include <vector>
#include <iostream>
#include <functional>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <queue>
#include <memory>
#include <thread>

using namespace std;

void Debug(const std::string &st);

/* Error handling Enums*/
enum class tThreadmsg
{
	th_ok,
	th_error,
	th_maxlimit
};

/** Store task in a message Queue 
 *  to perform task concurrently
 * */
template<typename Msg>
class TaskMsgQueue
{
	mutable mutex _mu;
	condition_variable _condition;
	//Task stored in a Queue
	queue<Msg> _Queue;
	//atomic flag to indicate task completion
	std::atomic<int> _shut;
public:
	//Constructor
	TaskMsgQueue():_shut(0){}
	//Push Message In a Queue
	void Push(const Msg &msg)
	{
		lock_guard<mutex> lk(_mu);
		_Queue.push(std::move(msg));
		_condition.notify_one();
	}
	//Pop messge with out Waiting
	bool popQ(Msg &&data)
	{
		std::unique_lock<mutex> lk(_mu);
		if(!_Queue.empty())
		{
			data = move(_Queue.front());
			_Queue.pop();
			return true;
		}
		return false;
	}
	//Pop message with Waiting
	bool waitpopQ(Msg &data)
	{
		std::unique_lock<mutex> lk(_mu);
		_condition.wait(lk,[&]{return _shut||!_Queue.empty();});
		if(!_Queue.empty())
		{
			data = move(_Queue.front());
			_Queue.pop();
			return true;
		}
		return false;
	}
	//Pop All pending message with user request
	void Shutdown()
	{
		std::lock_guard<std::mutex> lk(_mu);
		_shut = 1;
		_condition.notify_all();
	}
};

/**
 * Joiner Thread class To Join Thread from main thread
 * **/
class JoinThread
{
	vector<thread> &_ThJoin;

public:
	JoinThread(vector<thread> &th):_ThJoin(th){}
	~JoinThread()
	{
		for(auto &Join : _ThJoin)
		{
			if(Join.joinable())
			{
				Join.join();
			}
		}
	}
};
/** Thread Pool Class to perform
 * 	Task operations concurrently
 * */
class ThreadPool
{
private:
	using tFun = std::function<void()>;
	std::atomic<bool> done;
	std::vector<std::thread> _threads;
	JoinThread _join;
	TaskMsgQueue<tFun> _TaskQueue;
	size_t _size;
	std::mutex _mut;
public:

	explicit ThreadPool(size_t pSize);
	tThreadmsg Init();
	void WorkerThread();
	~ThreadPool();
	template<typename fun>
	void submit(fun f)
	{
		_TaskQueue.Push(tFun(f));
	}
};

#endif /* THREADPOOL_H_ */
