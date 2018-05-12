/*
 * ThreadPool.cpp
 *
 *  Created on: 08-May-2018
 *      Author: tapesh
 */

#include "ThreadPool.h"
#define th_Dbug 0

/** th_Dbug is used for debuging threadpool 
 * Should be disable for release Product
 * */
void Debug(const std::string &st)
{
#if th_Dbug
	cout<<st.c_str()<<" :: TH ID ::-  "<<std::this_thread::get_id()<<endl;
#endif
}

/** Threadpool Constructor 
 * */
ThreadPool::ThreadPool(size_t pSize):_size(pSize),done(false),_join(_threads)
{
	Init();
}
tThreadmsg ThreadPool::Init()
{
	Debug("Init Start");

	try
	{
		for(unsigned i=0;i<_size;++i)
		{
			_threads.push_back(
					std::thread(&ThreadPool::WorkerThread,this));
		}
	}
	catch(...)
	{

		Debug(" Error in thread creation");
		done=true;
		return tThreadmsg::th_error;
	}
	Debug("Init End");
}

/**
 * Worker thread to perform operations
 * for client software
 * */
void ThreadPool::WorkerThread()
{
	std::unique_lock<std::mutex> lk(_mut);
	Debug(" WorkerThread Start");
	if(!done.load())
	{
		/** 
		 *  Wait for task queu event 
		 * */
		tFun task;
		if(_TaskQueue.waitpopQ(task))
		{
			task();
			lk.unlock();
		}
		else
		{
			std::this_thread::yield();
		}
	}
	else
	{
		_TaskQueue.Shutdown();
	}
	Debug(" WorkerThread End");
}
ThreadPool::~ThreadPool()
{
	std::unique_lock<std::mutex> lk(_mut);
	Debug("~ThreadPool");
	done.store(true);
	_TaskQueue.Shutdown();
	Debug("~ThreadPool End");
}



