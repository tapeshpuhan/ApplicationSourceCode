 #include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

/*
 * want to devlop a mechine which will do printing , scaning and fax operation 
 * So How can i create a interface for a client 
 * 
 * */

struct IMechine
{
	virtual void print()=0;
	virtual void Scan()=0;
	virtual void Fax()=0;
};

struct Mechine : public IMechine
{
	 void print()
	 {
		 cout<<"Impliment Print"<<endl;
	 }
	 void Scan()
	 {
		 cout<<"Impliment Scan"<<endl;
	 }
	 void Fax()
	 {
		 cout<<"Impliment Fax"<<endl;
	 }
};

/*
 * If same interface is availabe 
 * and user need s mechine which will only print 
 * or only print and scan what to do
 * 1. e can send one exception for fax , but it is not correct design 
 * and user unnesory have a interface which is not need for him
 * */
 
 struct Iprinter
 {
	 virtual void print()=0;
 };
 struct printer:public Iprinter
 {
	  void print()
	  {
		  cout<<"Impliment print Independent"<<endl;
	  }
 };
 struct Iscaner
 {
	 virtual void Scaner()=0;
 };
 struct scaner:public Iscaner
 {
	  void Scaner()
	  {
		  cout<<"Impliment scan Independent"<<endl;
	  }
 };
struct IFax
{
	virtual void faxer()=0;
};
 struct fax:public IFax
 {
	  void faxer()
	  {
		  cout<<"Impliment faxer Independent"<<endl;
	  }
 };
struct IPrintAndScan:public Iprinter, public Iscaner
{
};

struct PrintAndScan:public IPrintAndScan
{
	Iprinter &print;
	Iscaner &Scan;
	PrintAndScan(Iprinter &p, Iscaner &s):print(p),Scan(s){}
	void printAndScan()
	{
		print.print();
		Scan.Scaner();
	}
};

int main()
{
	
	scaner o1;
	printer o2;
	//unique_ptr<IPrintAndScan> ptr(new PrintAndScan(o2,o1));
	IPrintAndScan *ptr = new PrintAndScan(o2,o1)
	 
	ptr->printAndScan();
	
	return 0;
}
