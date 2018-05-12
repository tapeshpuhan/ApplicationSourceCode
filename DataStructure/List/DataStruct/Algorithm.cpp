/*
 * Algorithm.cpp
 *
 *  Created on: 01-Apr-2018
 *      Author: tapesh
 */

#include "BaseFile.h"
#if 0
void test1()
{
	vector<int> v={2,3,4,5,1,6};

	if(all_of(v.cbegin(),v.cend(),[&](const int &i){return (i>=2);}))
	{
		cout<<"All values are greter than 2"<<endl;
	}
	else
	{
		cout<<"NOT All values are greter than 2"<<endl;
	}
}

void test_findnot()
{
	vector<int> v={2,3,4,5,1,6};

	auto at = find_if_not(v.cbegin(),v.cend(),[&](const int &i){return (i>=2);});
	cout<<*at<<endl;
	array<int, 10> arr =  { 3, 2, 5, 7, 3, 5, 6, 7 };
	vector<int> res;
	copy_if(arr.begin(), arr.end(), back_inserter(res),[](const int i) { return i == 5 || i == 7; });
	for(auto &at:res)
	{
		cout<<at<<endl;
	}
}

void test_foreach()
{
	vector<int> v={2,3,4,5,1,6};
	int res= 0;
	 for_each(v.cbegin(),v.cend(),[&](int a){res = res + a;});
	cout<<res<<endl;
}

void test_replacec()
{
	vector<int> v={2,3,4,5,1,6};

	replace_if(v.begin(),v.end(),[&](int a){return a>4;},100);
	for_each(v.cbegin(),v.cend(),[&](int a){cout<<a<<endl;});
}
void test_sort()
{
	vector<int> v={2,3,4,5,1,6};

	sort(v.begin(),v.end(),[&](int a, int b){return a<b;});
	for_each(v.cbegin(),v.cend(),[&](int a){cout<<a<<endl;});
}



int Candy(){
	int num;

	vector<int> Ai= {2,3};// Reading input from STDIN
	vector<int> Mi = {3, 2, 9, 11, 2};

	//vector<int>::const_iterator it  =
			//find_if(Mi.cbegin(),Mi.cend(),[&](int & a){return (find(Ai.cbegin(),Ai.cend(),a)!=Ai.end());});
	//cout<<*it<<endl;
	for(auto &at:Mi)
	{
		vector<int>::const_iterator it = find(Ai.cbegin(),Ai.cend(),at);
		if(it!=Ai.end())
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

void printKMax(int arr[], int n, int k){
     deque<int> dq;

    for (int i=0; i<n; i++){

        // base case for first element
        if (dq.empty()){
            dq.push_back(i);
        }

        // remove elements outside the current window
        if (dq.front() <= (i - k)){
            dq.pop_front();
        }

        // move max element to the front
        while (!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }

        dq.push_back(i);

        // print out only when the first window is completed
        if (i >= (k - 1)){
            cout << arr[dq.front()] << " ";
        }
    }
    cout << endl;
}
int main(){

   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}
#endif
