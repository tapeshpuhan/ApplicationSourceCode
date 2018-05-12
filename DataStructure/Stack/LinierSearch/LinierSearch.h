/*
 * LinierSearch.h
 *
 *  Created on: 13-Feb-2018
 *      Author: tapesh
 */

#ifndef LINIERSEARCH_H_
#define LINIERSEARCH_H_


#include<iostream>
#include<string>
#include<vector>
#include<initializer_list>
using namespace std;


template<typename T>
class LinerSearch
{
private:
	T value;
	std::vector<T> data;
public :
	/*LinerSearch(initializer_list<T> t)
	{
		for (auto at : t)
		{
			data.push_back(at);
		}
	}*/
	LinerSearch(const std::vector<T> &d):data(d){}
	bool searchValue(const T &value);
	void print();

};


#endif /* LINIERSEARCH_H_ */
