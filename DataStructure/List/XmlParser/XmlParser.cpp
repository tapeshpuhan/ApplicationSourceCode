/*
 * XmlParser.cpp
 *
 *  Created on: 08-Apr-2018
 *      Author: tapesh
 */
#include "XmlParser.h"
#include<istream>
#include <fstream>

void XmlPars::ParseXml(const string &path)
{
	ifstream file(path);
	map<string,tBook> data;
	if(!file.is_open())
	{
		cout<<"Error: file not found"<<endl;
		return;
	}


	getBookInfo(data,file,"/catalog");

	for(auto &at:data)
	{
		cout<<"Book Info"<<endl;
		cout<<at.first.c_str()<<endl;
		cout<<"Date:- "<<at.second.Date.c_str()<<endl;
		cout<<"Price:- "<<at.second.price.c_str()<<endl;
		cout<<"author:- "<<at.second.author.c_str()<<endl;
	}
	auto find = data.find("\"bk105\"");
	if(find!=data.end())
	{
		cout<<find->first.c_str()<<endl;
	}
	else
	{
		cout<<"end not found"<<endl;
	}

}

void XmlPars::getBookInfo(map<string,tBook> &op, ifstream &file, const string &end)
{
	string line;
	string::size_type po=0;
	string::size_type npo=0;
	tBook book;

	getline(file,line);
	while(file.good())
	{
		if(line.find("=")==string::npos)
		{
			getline(file,line);
			continue;
		}

		{

			if((po = line.find("<") )!= string::npos)
			{
				string key,value;
				string cat,vcat;
				/*Find the key */
				npo = line.find("=");
				key = line.substr(po+1,npo-(po+1));
				/*Find the value*/
				po = npo;
				npo = line.find(">");
				value = line.substr(po+1,npo-(po+1));
				//cout<<key.c_str()<<"  :: "<<value.c_str()<<endl;

				book.id = value;
				while(1)
				{
					getline(file,line);
					if( line.find("=")!=string::npos)
						break;
					else
					{
						po = line.find("<");
						npo = line.find(">");
						cat = line.substr(po+1,npo-(po+1));
						/*Find the value*/
						po = npo;
						npo = line.find("</");
						vcat = line.substr(po+1,npo-(po+1));
						//cout<<cat.c_str()<<"  :: "<<vcat.c_str()<<endl;
						if(end==cat)
						{
							break;
						}
						if("author" == cat)
						{
							book.author = vcat;
						}
						if("title" == cat)
						{
							book.titel = vcat;
						}
						if("genre" == cat)
						{
							book.genre = vcat;
						}
						if("price" == cat)
						{
							book.price = vcat;
						}
						if("publish_date" == cat)
						{
							book.Date = vcat;
						}
					}
					op[value] = book;
				}
			}
		}
	}
	//cout<<line.c_str()<<endl;

}
int main()
{
	//std::shared_ptr<XmlPars> ptr = make_shared<XmlPars>();
	//ptr->ParseXml(string("/home/tapesh/C++11/file.xml"));
	myPtr<XmlPars> ptr(move(new XmlPars));
	ptr->ParseXml(string("/home/tapesh/C++11/file.xml"));
	return 0;
}

