/*
 * ActiveObject.cpp
 *
 *  Created on: 08-Apr-2018
 *      Author: tapesh
 */

#include "BaseFile.h"
#include<atomic>
using namespace std;
#if 0

class Task
{
public:
	int getPrio()
	{
		return _prio;
	}
	void setPrio(int prio)
	{
		//std::lock_guard<mutex> lk(mu);
		_prio = prio;
	}
	Task():_prio(50){}
	virtual ~Task(){}
private:
	//std::mutex mu;
	int _prio;
};

class comp
{
public:
	bool operator()(shared_ptr<Task> &l, shared_ptr<Task> &r)
	{
		return l->getPrio() < r->getPrio();
	}
};

template<typename T>
class PrioQueue
{
	std::priority_queue<T,deque<T>,comp> _Queue;
	std::condition_variable _cond;
	std::mutex mut;
	std::atomic<int> _shutDown;
public:
	PrioQueue():_shutDown(0){

	}
	void push_task(T &&task)
	{
		std::unique_lock<mutex> lk(mut);
		_Queue.push_back(move(task));
		lk.unlock();
		_cond.notify_one();
	}
	void push_task(const T &task)
	{
cout<<"push_task "<<endl;
		std::unique_lock<mutex> lk(mut);
		cout<<"push_task a"<<endl;
		_Queue.push(task);
		cout<<"push_task e"<<endl;
		lk.unlock();
		_cond.notify_one();
	}
	T waitPop()
	{
		T task;
		std::unique_lock<mutex> lk(mut);
		//_cond.wait(lk,[=](){return _shutDown.load();});
		cout<<"waitPop s"<<endl;
		_cond.wait(lk);
		cout<<"waitPop e"<<endl;
		if(!_Queue.empty())
		{
			task = _Queue.top();
			_Queue.pop();
		}
		// Manual unlocking is done before notifying, to avoid waking up
		// the waiting thread only to block again (see notify_one for details
		lk.unlock();
		_cond.notify_one();
		return task;
	}
	void ShutDown()
	{
		_shutDown = 1;
	}
	auto empty()->decltype(_Queue.empty())
	{
		return _Queue.empty();
	}
};

class ActiveObj
{

	PrioQueue<std::shared_ptr<Task>> Q_;
public:

	ActiveObj(){

	}
	virtual ~ActiveObj(){
	}
	void start();
	void methdpush(const shared_ptr<Task> t);
	void callback();
	void shutdown();
	virtual void call(shared_ptr<Task> &t)=0;
	virtual void update()=0;
};

void ActiveObj::start()
{
	cout<<"start"<<endl;
	std::thread th(&ActiveObj::callback, this);
	if(th.joinable())
	{
		th.join();
	}
}

void ActiveObj::methdpush(const std::shared_ptr<Task> t)
{
	//if(Q_.empty())
		//start();
	cout<<"methdpush"<<endl;
	Q_.push_task(t);
	start();

}
void ActiveObj::callback()
{
	cout<<"callback"<<endl;
	std::shared_ptr<Task> t = Q_.waitPop();
	cout<<"callback waitPop"<<endl;
	call(t);
}
void ActiveObj::shutdown()
{
	Q_.ShutDown();
}
/****************
 * CLIENT CODE TO USE ABOVE FRAMEWORK
 *
 */
class playinfo:public Task
{
	int min;
	int sec;
public:
	playinfo():min(0),sec(0){
		setPrio(1);
	}
	void setPaytime(const int m, const int s)
	{
		min = m;
		sec = s;
	}
	void getPaytime(int &m, int &s)
	{
		m = min;
		s = sec;
	}

};
class playMeta:public Task
{
	string album;
public:
	playMeta():album(""){
		setPrio(2);
	}
	void setmeta(const string& s)
	{
		album = s;
	}
	string getmeta()
	{
		return album;
	}

};
class player:public ActiveObj
{
public:
	player(){}
	void update();
	void call(shared_ptr<Task> &t);
};
void player::update()
{
	std::shared_ptr<Task> task = std::make_shared<playMeta>();
	methdpush(task);
}
void player::call(shared_ptr<Task> &t)
{
cout<<"player::call"<<endl;

}


int main()
{
	std::shared_ptr<ActiveObj> obj =std::make_shared<player>();

	obj->update();
	return 0;
}
#endif
