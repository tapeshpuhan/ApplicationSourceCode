#include "BiologicalInfo.h"
#include <memory>
enum class  tTypeOfSpeci
{
MAMMAL,
ANIMAL,
BIRD
};

class InfoToBioName
{
<<<<<<< HEAD
	std::shared_ptr<Mammal> _mammal;
	std::shared_ptr<Animal> _animal;
	std::shared_ptr<Bird> _bird;	
=======
	//std::shared_ptr<Mammal> _mammal;
	//std::shared_ptr<Animal> _animal;
	//std::shared_ptr<Bird> _bird;
	Mammal _mammal;
>>>>>>> 03b8acc44b09133398ec5ef1b47bfcffb9424118
	public:
	InfoToBioName(){}
	void init();
	void gitInfo(const tTypeOfSpeci &type);
};
