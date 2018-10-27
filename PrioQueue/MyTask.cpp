#include "PrioQueue.cpp"
#include <string>
#include <iostream>
using namespace std;

class MyTask
{
	private:
	int id;
	string name;
	
	public:
	MyTask(){}
	MyTask(int id, const string& name):id(id),name(name){}
	bool operator < (const MyTask &ob) const
	{
		return (this->id < ob.id);
	}
	string GetName()
	{
		return name;
	}
};

int main()
{
	PrioQueue<MyTask> MyQ;
	
	MyTask o1(5,"Mytask1");
	MyTask o2(2,"Mytask2");
	
	MyQ.SetObject(o1);
	MyQ.SetObject(o2);
	
	auto getObj = MyQ.GetObject();
	if(getObj.second == true)
	{
		cout<<"Get Task "<<getObj.first.GetName()<<endl;
	}
	else
	{
		cout<<"Is empty"<<endl;
	}
	return 0;
} 
