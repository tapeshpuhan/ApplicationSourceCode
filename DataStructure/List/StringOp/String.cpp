/*
 * String.cpp
 *
 *  Created on: 17-Mar-2018
 *      Author: tapesh
 */

#include<iostream>
#include<string>
using namespace std;


void GetSubString(string sStr, string subStr)
{
	/*string::size_type sPos = sStr.find_first_not_of(subStr,0);
	string::size_type nPos = sStr.find_first_of(subStr, sPos);

	while(string::npos!=nPos)
	{
		cout<<"Position "<<nPos<<endl;
		sPos = sStr.find_first_not_of(subStr,nPos);
		nPos = sStr.find_first_of(subStr, sPos);
	}*/
	string::size_type nPos = sStr.find(subStr, 0);
	while(string::npos!=nPos)
	{
		cout<<"Position "<<nPos<<endl;
		nPos = sStr.find(subStr, nPos+1);
	}
}
void C_GetSubString(string sStr, string subStr)
{
	string::size_type pos = 0;
	bool found = false;

	for(int i = 0; i<sStr.length();i++)
	{
		int pos = i;
		found = true;
		for(int j = 0; j < subStr.length();j++)
		{

			if(sStr[pos++] !=subStr[j])
			{
				found = false;
				break;
			}
		}
		if(true == found)
		{
			cout<<"Position Is "<<i<<endl;
		}
	}
}
int main()
{
//	GetSubString("THIS IS A TEST TEXT", "TEST");
	//GetSubString("AABAACAADAABAABA", "AABA");
	C_GetSubString("AABAACAADAABAABA", "AABA");
	C_GetSubString("THIS IS A TEST TEXT", "TEST");
	return 0;
}