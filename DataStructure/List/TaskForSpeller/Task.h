/*
 * Task1.h
 *
 *  Created on: 10-Apr-2018
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

using namespace std;

/*
 * Message type returns from the
 * method call.
 */
using tErrorMsg = enum class ErrorMsg{
	msg_ok=0,
	msg_read_error,

};
class readDist
{
private:
	unordered_multimap<string,string> _dir;
	std::set<string> _output;
public:
	readDist(){
		_dir.clear();
	}
	tErrorMsg StoreDist(const string &path, const string input);
	void printInfo(const string &input);
//private:
	void saveIntoMap(const string &line, const string input);
};



