#include "TextShape.h"
#include <iterator>
#include <algorithm>
using namespace std;

vector<string> TextAdape::getText()
{
	vector<string> output;
	//copy(output.begin(), output.end(), istream_iterator<string>(cin));
	for(int i =0; i < 5;i++)
	{
	string data;
	cin>>data;
	output.push_back(data);
	}
	return output;
}


DrawText::DrawText()
{
	_Text.reset(new TextAdape());
}
void DrawText::createShape()
{
	text = _Text->getText();
}
void DrawText::displayShape()
{
	for(auto at : text)
	{

		cout<<at<<endl;
	}
}
