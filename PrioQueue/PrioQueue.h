#include <iostream>
#include <set>
#include <utility>
template<class T>
class DefPrio
{
	public:
	bool operator ()(const T& o1, const T& o2) const
	{
		return o1 < o2;
	}
};

template<class PrioObj, class PrioFun = DefPrio<PrioObj>>
class PrioQueue
{
	private:
	std::set<PrioObj,PrioFun> _PrioQueue;
	
	public:
	PrioQueue();
	bool SetObject(PrioObj& Obj);
	std::pair<PrioObj,bool> GetObject();
	bool IsEmpty()const;
};


