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
//Create A generic interface to Satisfy the filter



template<typename T>
class Specification
{
	public:
	virtual bool isSatisfy(const T &spec)=0;

};
// Create Colour Specification
class ColoerSpec: public Specification<Product>
{
	Colour clr;
	public:
	explicit ColoerSpec(const Colour &c):clr(c)
	{
		
	}
	bool isSatisfy(const Product &spec)
	{
		return (spec.Colr == clr);
	}
};
// Create Size Specification
class SizeSpec: public Specification<Product>
{
	Size size;
	public:
	explicit SizeSpec(const Size &s):size(s)
	{
		
	}
	bool isSatisfy(const Product &spec)
	{
		return (spec.Siz == size);
	}
};

// Create And Specification
template<typename T> 
struct  AndSpecification: public Specification<T>
{
	Specification<T> &fast;
	Specification<T> &Second;
	AndSpecification( Specification<T>& sp1,  Specification<T>& sp2):fast(sp1),Second(sp2){}
	AndSpecification<T> operator &&(const Specification<T>& spec)
	{
		return AndSpecification<T>(*this, spec);
	}
	bool isSatisfy(const T &type)
	{
		return (fast.isSatisfy(type)&&(Second.isSatisfy(type)));
	}
	 
};

// Filter the object as per user requairments
// cretate a interface to filter

template<typename T>
class FilterManager{
	public:
	
	virtual vector<T*> getList(const vector<T*> &prod, Specification<T> &spec) = 0;
};

class BeterFilter : public FilterManager<Product>
{
	public:
	BeterFilter(){}
	vector<Product*> getList(const vector<Product*> &prod, Specification<Product> &spec) override
	{
		//cout<<"Filter By Size 4"<<endl;
		vector<Product*> Res;
		for(auto &at:prod)
		{
			//cout<<"Filter By Size 5"<<endl;
			if(spec.isSatisfy(*at))
			{
				Res.push_back(at);
			}
		}
		return Res;
	}
};

int main()
{
	Product Apple {"Apple",Colour::Green,Size::Large};
	Product Orrange {"Orange",Colour::Yellow,Size::Medium};
	Product Banana {"Banana",Colour::Yellow,Size::Large};
	Product Mango {"Mango",Colour::Green,Size::Small};
	
	vector<Product*> _Products = {&Apple, &Orrange,&Banana,&Mango};
	
	ColoerSpec green(Colour::Green);
	SizeSpec large(Size::Large);
	
	auto filt = unique_ptr<BeterFilter>(new BeterFilter());
	//BeterFilter filt;
	auto getSizres = filt->getList(_Products,large);
	
	cout<<"Filter By Size"<<endl;
	for(auto &at:getSizres)
	{
		cout<<at->Name<<endl;
	}
	auto getColres = filt->getList(_Products,green);
	cout<<"Filter By Colour"<<endl;
	for(auto &at:getColres)
	{
		cout<<at->Name<<endl;
	}
	AndSpecification<Product> AndSpec(green, large);
	auto getAnd = filt->getList(_Products,AndSpec);
	cout<<"Filter By And green and large"<<endl;
	for(auto &at:getAnd)
	{
		cout<<at->Name<<endl;
	}
	return 0;
}
