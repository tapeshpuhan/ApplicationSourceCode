/*
 * Prepaire.cpp

 *
 *  Created on: 20-Mar-2018
 *      Author: tapesh
 */
#if 0
#include<iostream>
#include<vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
class test
{
public:
	void LeftRotation(vector<int> &V, int time);
	void Ex2StringAnagrams(string a, string b);
};

void test::LeftRotation(vector<int> &V, int time)
{
	int po;

	for(int i = 0; i < time; i++ )
	{
		po = V[0];
		for(int j = 0; j < (V.size()-1);j++)
		{
			V[j] = V[j+1];
		}
		V[V.size()-1] = po;
	}
}
void Ex2StringAnagrams(string a, string b)
{
	//find the common charecter frequency is same
	unordered_map<char,int> unMap;
	unsigned int count = 0;

	for(auto &at : a)
	{
		unMap[at]++;
	}
	for(auto &at : b)
	{
		unMap[at]--;
	}
	for(auto &at: unMap)
	{
		count = count + abs(at.second);
	}
	cout<<"\nCount "<<count;
}
int main()
{
	vector<int> array = {1,2,3,4,5};
	test obj;

	obj.LeftRotation(array,2);

	for(auto at:array)
	{
		cout<<at<<" ";
	}

	Ex2StringAnagrams("cde","abc");
	return 0;
}

*/

int number_needed(string a, string b) {

	 int count = 0;
#if 0
	unordered_map<char,int> unMap;

	for(auto &at : a)
	{
        if(at>='a' && at<='z')
		unMap[at]++;
	}
	for(auto &at : b)
	{
        if(at>='a' && at<='z')
		unMap[at]--;
	}
	int cr=1;
	/*for(auto &at: unMap)
	{
		//cout<<at.second<<" "<<abs(at.second)<<endl;
		//cr +=  abs(at.second);
		cr++;
		cout<<"c "<<cr<<endl;
	}*/

#endif
	cout<<"Count "<<count;
	count = 3;
	/*for (int i=0 ; i < 5; i++)
	{
		cr++;
		cout<<"c "<<cr<<endl;
	}*/
	//cout<<"Count "<<count;
    return count;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;

    cout << number_needed(a, b) << endl;
    return 0;
}
#endif
