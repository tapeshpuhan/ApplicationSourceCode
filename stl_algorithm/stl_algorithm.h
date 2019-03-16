#ifndef STL_ALGORITHM_H
#define STL_ALGORITHM_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

struct TestStlAlgorithm
{
	virtual std::string GetInfo() = 0;
	virtual void ProcessInput() = 0;
	virtual std::string PrintOutput() = 0;
};



#endif //STL_ALGORITHM_H