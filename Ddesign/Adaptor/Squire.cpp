#include "Squire.h"
using namespace std;


DrawSqire::DrawSqire(size_t size):_size(size)
{
	
}
void DrawSqire::createShape()
{
	vector<string> dots;
	auto mid  = _size/2;
	auto d = 1;
	
	for(int i = 0;  i < _size; i++)
	{
		dots.reserve(_size);
		for(int j =0; j < _size;j++)
		{
			dots.push_back("*");
		}
		_Shape.push_back(dots);
		dots.clear();
	}
}
void DrawSqire::displayShape()
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
