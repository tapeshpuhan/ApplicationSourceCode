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
	//std::shared_ptr<Mammal> _mammal;
	//std::shared_ptr<Animal> _animal;
	//std::shared_ptr<Bird> _bird;
	Mammal _mammal;
	public:
	InfoToBioName(){}
	void init();
	void gitInfo(const tTypeOfSpeci &type);
};
