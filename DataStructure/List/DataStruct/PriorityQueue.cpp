/*
 * PriorityQueue.cpp
 *
 *  Created on: 31-Mar-2018
 *      Author: tapesh
 */
#if 0
#include "BaseFile.h"
//#include <>

class task
{
public:
	task(int p):prio(p){}
	int getPrio(){return prio;}
private:
	int prio;
};

class compaire
{
public:
	bool operator()(task& lh, task& rh)
	{
		return lh.getPrio()<rh.getPrio();
	}
};

template<typename T, class method>
class PrioQueue
{
	priority_queue<T,deque<T>,method> _quwue;
public:
	void push(T& d)
	{
		_quwue.push(d);
	}
	void push(T&& d)
	{
		_quwue.push(move(d));
	}
	void pop()
	{
		_quwue.pop();
	}
	auto top()->decltype(_quwue.top())
	{
		return _quwue.top();
	}
	auto empty()->decltype(_quwue.empty())
	{
		return _quwue.empty();
	}

	/*auto begin()->decltype(_quwue.begin())
	{
		_quwue.begin();
	}
	auto end()->decltype(_quwue.begin())
	{
		_quwue.end();
	}*/
};
int main()
{
	task o1(1),o2(45),o3(56),o4(23);

	PrioQueue<task,compaire> obJ;

	obJ.push(move(o1));
	obJ.push(move(o2));
	obJ.push(move(o3));
	obJ.push(move(o4));

	/*obJ.push(o1);
	obJ.push(o2);
	obJ.push(o3);
	obJ.push(o4);*/


	while(!obJ.empty())
	{
		task a = obJ.top();
		cout<<a.getPrio()<<endl;
		//cout<<obJ.top().getPrio()<<endl;
		obJ.pop();
	}
	return 0;
}
#endif
