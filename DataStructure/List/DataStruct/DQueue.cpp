/*
 * DQueue.cpp
 *
 *  Created on: 01-Apr-2018
 *      Author: tapesh
 */
#include "BaseFile.h"
#if 0
int process(int arry[], int n, int k)
{
	deque<int> Q;
	int j = 0;

	for(int i = 0; i <= n-k;i++)
	{
		if(Q.empty())
		{
			Q.push_back(i);
		}
		j = i;
		while((!Q.empty()) && j<i+k)
		{
			if(arry[j] >= arry[Q.front()])
			{
				Q.pop_front();
				Q.push_back(j);
			}
			j++;
		}
		if(!Q.empty())
		{
			cout<<" "<<arry[Q.front()];
			Q.pop_front();
		}
	}
	cout<<endl;
}

int main()
{
	int array[]={3,5,23,2,67,3,6,31,45,20,46};
	//process(array, 11, 3);

	vector<int> v = {1 ,4 ,6 ,2 ,8 ,9};
	v.erase(v.begin()+2);

    for(auto &at:v)
    {
        cout<<at<<" ";
    }
    cout<<endl;
    v.erase(v.begin()+2,v.begin()+4);
    for(auto &at:v)
    {
        cout<<at<<" ";
    }
	return 0;
}
#endif
