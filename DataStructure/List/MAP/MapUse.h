/*
 * MappUse.h
 *
 *  Created on: 14-Mar-2018
 *      Author: tapesh
 */

#ifndef MAPUSE_H_
#define MAPUSE_H_


#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<list>
#include <unordered_map>
using namespace std;


/**
 *
 * T-1 , Sort the list as per arry list
 */

template<typename T>
class MapUse
{
	unordered_map<T,int> uMap;
public:
	void SortList(list<T> &value, const vector<T> &ref);
};



#endif /* MAPUSE_H_ */
