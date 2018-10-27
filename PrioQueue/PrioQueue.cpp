#include "PrioQueue.h"

template<class PrioObj,class PrioFun>
PrioQueue<PrioObj,PrioFun>::PrioQueue()
{
	std::cout<<"Constructor of PrioQueue"<<std::endl;
}

template<class PrioObj,class PrioFun>
bool PrioQueue<PrioObj,PrioFun>::SetObject(PrioObj& Obj)
{
	std::cout<<"Constructor of SetObject"<<std::endl;
	_PrioQueue.insert(Obj);
	return true;
}

template<class PrioObj,class PrioFun>
std::pair<PrioObj,bool> PrioQueue<PrioObj,PrioFun>::GetObject()
{
	std::cout<<"Constructor of GetObject"<<std::endl;
	PrioObj obj;
	
	if(_PrioQueue.empty())
	{
		
		return std::make_pair(obj,false);
	}
	else
	{
		obj = *(_PrioQueue.begin());
		_PrioQueue.erase(_PrioQueue.begin());		
	}
	return std::make_pair(obj,true);
}
template<class PrioObj, class PrioFun>
bool PrioQueue<PrioObj,PrioFun>::IsEmpty()const
{
	return _PrioQueue.empty();
}

