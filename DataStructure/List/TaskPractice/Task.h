/*
 * Task.h
 *
 *  Created on: 11-Apr-2018
 *      Author: tapesh
 */



#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<set>
#include <limits>
#include<memory>
#include<set>
#include <algorithm>
#include<queue>
#include <mutex>
#include <condition_variable>
#include<thread>
#include <deque>
#include<unordered_map>
#include <functional>
#include<atomic>

using namespace std;


template<typename T>
void PRINT(T &e)
{
	for(auto &at:e)
	{
		cout<<" "<<at;
	}
	cout<<endl;
}