#include "Circle.h"
using namespace std;


DrawCirlce::DrawCirlce(size_t size):_size(size)
{
	
}
void DrawCirlce::createShape()
{
	vector<string> dots;
	auto mid  = _size/2;
	auto d = 1;
	
	for(int i = 0;  i < _size; i++)
	{
		dots.reserve(_size);
		if(i<mid)
		{
			
			for(auto j = 0; j < d ; j++)
			{
				dots.push_back("*");
			}
			d = (i+1) *2;
		}
		else
		{
			d = (_size-i) *2;
			for(auto j = 0; j < d ; j++)
			{
				dots.push_back("*");
			}
		}
		_Shape.push_back(dots);
		dots.clear();
	}
}
void DrawCirlce::displayShape()
{
	for(auto at : _Shape)
	{
		for(auto bt : at)
		{
			cout<<bt;
		}
		cout<<endl;
	}
}
