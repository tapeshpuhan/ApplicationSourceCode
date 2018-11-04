 #include "BiologicalInfo.h"
 #include <sstream>
 
 using namespace std;
 
 string Human::Info()
 {
		stringstream ss;
		ss<<"Human Name :: Homo Sapiens"<<endl;
		return ss.str();
 }
 string Monkey::Info()
 {
		stringstream ss;
		ss<<"Monkey Name :: Monkey (disambiguation)."<<endl;
		return ss.str();
 }
 string Tiger::Info()
 {
		stringstream ss;
		ss<<"Tiger Name :: Panthera tigris."<<endl;
		return ss.str();
 }
 string dog::Info()
 {
		stringstream ss;
		ss<<"Dog Name :: Canis lupus familiaris."<<endl;
		return ss.str();
 }
 string pigeon::Info()
 {
		stringstream ss;
		ss<<"Pigion Name :: Columbidae"<<endl;
		return ss.str();
 }
  string duck::Info()
 {
		stringstream ss;
		ss<<"duck Name :: Anas Platyrhynchos."<<endl;
		return ss.str();
 }

string Mammal::Info()
{
	for(auto &at : _Elements)
	{
		cout<<at->Info()<<endl;
	}
	return "";
}
string Animal::Info()
{
	for(auto &at : _Elements)
	{
		cout<<at->Info()<<endl;
	}
	return "";
}
string Bird::Info()
{
	for(auto &at : _Elements)
	{
		cout<<at->Info()<<endl;
	}
	return "";
}
