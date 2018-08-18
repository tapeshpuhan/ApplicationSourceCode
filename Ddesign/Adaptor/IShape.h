#ifndef SHAPE_H_
#define SHAPE_H_

class IShape
{
	public:
	/*
	 * A interface to create a Geometrical 
	 * Shape provide to widgets
	*/
	virtual void createShape()=0;
	/* the interface to display the shape in console IO 
	 * */
	virtual void displayShape()=0;
};

#endif
