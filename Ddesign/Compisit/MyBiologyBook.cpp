#include "MyBiologyBook.h"

void InfoToBioName::init()
{
	_mammal = std::make_shared<Mammal>();
	_animal = std::make_shared<Animal>();
	_bird = std::make_shared<Bird>();
	
	_mammal->addChild(make_shared <Human>());
	_mammal->addChild(make_shared<Monkey>());
	
		
	_animal->addChild(make_shared <Tiger>());
	_animal->addChild(make_shared <dog>());
	
	_bird->addChild(make_shared<pigeon>());
	_bird->addChild(make_shared<duck>());
}

void InfoToBioName::gitInfo(const tTypeOfSpeci &type)
{
	switch(type)
	{
		case tTypeOfSpeci::MAMMAL:
		_mammal->Info();
		break;
		case tTypeOfSpeci::BIRD:
		_bird->Info();
		break;
		case tTypeOfSpeci::ANIMAL:
		_animal->Info();
		break;
		default:
		break;
	}
}


int main()
{
	std::unique_ptr<InfoToBioName> _info(new InfoToBioName());
	_info->init();
	_info->gitInfo(tTypeOfSpeci::MAMMAL);
	return 0;
}
