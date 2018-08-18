#ifndef SQUIRE_H_
#define SQUIRE_H_

#include "IShape.h"
#include <vector>
#include <iostream>
#include <string>
class DrawSqire : public IShape
{
	std::vector<std::vector<std::string>>  _Shape;
	size_t _size;
	
	public:
	explicit DrawSqire(size_t size);
	/*
	 * A interface to create a Geometrical 
	 * Shape provide to widgets
	*/
	 void createShape();
	/* the interface to display the shape in console IO 
	 * */
	 void displayShape();
};

#endif
