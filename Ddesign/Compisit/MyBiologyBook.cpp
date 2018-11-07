#include "MyBiologyBook.h"

void InfoToBioName::init()
{
<<<<<<< HEAD
	_mammal = std::make_shared<Mammal>();
	_animal = std::make_shared<Animal>();
	_bird = std::make_shared<Bird>();
	
	_mammal->addChild(make_shared <Human>());
	_mammal->addChild(make_shared<Monkey>());
	
		
	_animal->addChild(make_shared <Tiger>());
	_animal->addChild(make_shared <dog>());
	
	_bird->addChild(make_shared<pigeon>());
	_bird->addChild(make_shared<duck>());
=======
	//_mammal = std::make_shared<Mammal>();
	//_animal = std::make_shared<Animal>();
	//_bird = std::make_shared<Bird>();
	
	//_mammal->addChild(make_shared <Human>());
	//_mammal->addChild(make_shared<Monkey>());
	
		
	//_animal->addChild(make_shared <Tiger>());
	//_animal->addChild(make_shared <dog>());
	
	//_bird->addChild(make_shared<pigeon>());
	//_bird->addChild(make_shared<duck>());
>>>>>>> 03b8acc44b09133398ec5ef1b47bfcffb9424118
}

void InfoToBioName::gitInfo(const tTypeOfSpeci &type)
{
	switch(type)
	{
		case tTypeOfSpeci::MAMMAL:
<<<<<<< HEAD
		_mammal->Info();
		break;
		case tTypeOfSpeci::BIRD:
		_bird->Info();
		break;
		case tTypeOfSpeci::ANIMAL:
		_animal->Info();
=======
		//_mammal->Display();
		break;
		case tTypeOfSpeci::BIRD:
		//_bird->Display();
		break;
		case tTypeOfSpeci::ANIMAL:
		//_animal->Display();
>>>>>>> 03b8acc44b09133398ec5ef1b47bfcffb9424118
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
