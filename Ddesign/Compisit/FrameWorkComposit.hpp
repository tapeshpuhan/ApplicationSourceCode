#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
template<typename Component, int num=10>
class CompositeFrame: public Component
{
	protected:
	std::vector<std::shared_ptr<Component>> _Elements;
	int _limit = num;
	public:
	CompositeFrame();
	
	void addChild(const std::shared_ptr<Component> baseObj);
	void removeChild(const std::shared_ptr<Component> baseObj);
	void clearInfo();
};

using namespace std;

template<typename Component, int num>
CompositeFrame<Component,num>::CompositeFrame()
{
	_Elements.reserve(_limit);
}

template<typename Component, int num>	
void CompositeFrame<Component,num>::addChild(const std::shared_ptr<Component> baseObj)
{
    std::cout<<" CompositeFrame add child"<<std::endl;
    auto at = find(_Elements.begin(),_Elements.end(),baseObj);
    
    if(at==_Elements.end())
    {
        _Elements.push_back(baseObj);
    }
}
template<typename Component, int num>	
void CompositeFrame<Component,num>::removeChild(const std::shared_ptr<Component> baseObj)
{
    std::cout<<" CompositeFrame remove child"<<std::endl;
    auto at = find(_Elements.begin(),_Elements.end(),baseObj);
    if(at!=_Elements.end())
    {
        _Elements.erase(baseObj);
    }
}
template<typename Component, int num>	
void CompositeFrame<Component,num>::clearInfo()
{
    std::cout<<" CompositeFrame clearInfo "<<std::endl;
    _Elements.clear();
} 
