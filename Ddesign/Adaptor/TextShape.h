#ifndef TEXT_H_
#define TEXT_H_

#include "IShape.h"
#include <vector>
#include <iostream>
#include <string>
#include <memory>

/*
 * DrawText is adaptor class which is no where related to Ishape , 
 * but provide interface to clint program we can adupt it for Ishape a
 * and use same interface to get text and display in IO 
 * 
 * */


class TextAdape
{
	public:
	std::vector<std::string> getText();
};


class DrawText : public IShape
{
	std::unique_ptr<TextAdape> _Text;
	std::vector<std::string> text;
	
	public:
	explicit DrawText();
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
