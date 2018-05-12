/*
 * Task.cpp
 *
 *  Created on: 10-Apr-2018
 *      Author: tapesh
 */
#include"Task1.h"


void readInputSearch(const string &path, const string &input)
{
	std::shared_ptr<readDist> ptr = make_shared<readDist>();
	ptr->StoreDist(path,input);
	ptr->printInfo(input);
}


tErrorMsg readDist::StoreDist(const string &path,const string input)
{
	tErrorMsg result = ErrorMsg::msg_ok;
	//cout<<input.c_str()<<endl;

	ifstream file(path);
	if(!file.is_open())
	{
		cout<<"ERROR: Error in File opening"<<path.c_str();
		result = ErrorMsg::msg_read_error;
	}
	//if open file successful
	if(ErrorMsg::msg_ok == result)
	{
		try	{

			while(file.good())
			{
				string line;

				if(ErrorMsg::msg_ok == result)
				{
					getline(file,line);
					//cout<<line.c_str()<<endl;
					saveIntoMap(line,input);

				}
			}
		}
		catch(const ifstream::failure& e)
		{
			cout<<"ERROR : reading file error"<<e.what()<<endl;
			result = ErrorMsg::msg_read_error;
		}
	}
	file.close();
	return result;
}
//method to store the dir info into map
void readDist::saveIntoMap(const string &line, const string input)
{
	string::size_type len = input.length();


	if(input.length()>=3)
	{

		_dir.insert({line.substr(0,input.length()),line});
	}
	else
	{

		_dir.insert({line.substr(0,input.length()),line});
	}
}
void readDist::printInfo(const string &input)
{
	auto range = _dir.equal_range(input);

	for_each (
			range.first,
			range.second,
			[&](unordered_multimap<string,string>::value_type& x){
		if(x.second.length()<=input.length()+3)
			_output.insert(x.second);}
	);
	for(auto &at:_output)
	{
		cout<<at.c_str()<<endl;;
	}
}
int main(int argc, char **argv)
{
	if(argc!=3)
	{
		cout<<"./autocomplete <dictionary-file> <input-file>"<<endl;
	}
	else
	{
		string Dist;
		string input;

		if(argv[1]!=nullptr)
		{
			Dist = argv[1];
		}
		if(argv[2]!=nullptr)
		{
			input = argv[2];
		}
		cout<<Dist.c_str()<<" "<<input.c_str()<<endl;
		readInputSearch(Dist, input);
	}
	return 0;
}



