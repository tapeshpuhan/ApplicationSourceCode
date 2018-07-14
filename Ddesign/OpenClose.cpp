#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

//A colour specification
enum class Colour
{
	Red,
	Yellow,
	Green,
	Black,
	white
};

// A Size Specification
enum class Size
{
	Large,
	Small,
	Medium
};

// Product Class
struct Product
{
	string Name;
	Colour Colr;
	Size Siz;
};

class FilterManager
{
	public:
	vector<Product*> resFilterBySize(const vector<Product*>& products, Size siz)
	{
		vector<Product*> res;
		
		for(auto &at : products)
		{
			if(at->Siz == siz)
			{
				res.push_back(at);
			}
		}
		return res;
	}
	vector<Product*> resFilterByColor(const vector<Product*>& products, Colour Col)
	{
		vector<Product*> res;
		
		for(auto &at : products)
		{
			if(at->Colr == Col)
			{
				res.push_back(at);
			}
		}
		return res;
	}
};

int main()
{
	Product Apple {"Apple",Colour::Green,Size::Large};
	Product Orrange {"Orange",Colour::Yellow,Size::Medium};
	Product Banana {"Banana",Colour::Yellow,Size::Large};
	Product Mango {"Mango",Colour::Green,Size::Small};
	
	vector<Product*> _Products = {&Apple, &Orrange,&Banana,&Mango};
	
	shared_ptr<FilterManager> _ptr = make_shared<FilterManager>();
	
	auto getSizres = _ptr->resFilterBySize(_Products, Size::Large);
	
	cout<<"Filter By Size"<<endl;
	for(auto &at:getSizres)
	{
		cout<<at->Name<<endl;
	}
	cout<<"Filter By Colour"<<endl;
	auto getColres = _ptr->resFilterByColor(_Products, Colour::Green);
	
	for(auto &at:getColres)
	{
		cout<<at->Name<<endl;
	}
	return 0;
}
