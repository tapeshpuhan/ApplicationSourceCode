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

void Mammal::Display()
{
	for(auto &at : _Elements)
	{
		cout<<at->Info()<<endl;
	}
}
void Animal::Display()
{
	for(auto &at : _Elements)
	{
		cout<<at->Info()<<endl;
	}
}
void Bird::Display()
{
	for(auto &at : _Elements)
	{
		cout<<at->Info()<<endl;
	}
}
