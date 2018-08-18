#include "Squire.h"
#include "Circle.h"
#include "TextShape.h"
#include <memory>

using namespace std;

int main()
{
	unique_ptr<IShape> ptr(new DrawText());
	ptr->createShape();
	ptr->displayShape();
return 0;
}
