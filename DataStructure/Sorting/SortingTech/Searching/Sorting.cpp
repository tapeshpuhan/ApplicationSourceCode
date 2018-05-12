/*
 * Sorting.cpp
 *
 *  Created on: 19-Feb-2018
 *      Author: tapesh
 */


/*
 * Sorting.cpp
 *
 *  Created on: 17-Feb-2018
 *      Author: tapesh
 */
#include"Sorting.h"
#include "Searching.h"

template<typename T>
void Sorting<T>::Insert(T pData)
{
	cout<<"Sorting :: Insert "<<pData<<endl;
	_data.push_back(pData);
}

template<typename T>
void Sorting<T>::Display()
{
	cout<<"Final Sorting :: Display"<<endl;
	for(auto at : _data)
	{
		cout<<at<<endl;
	}
}

template<typename T>
void Sorting<T>::Display(vector<T> &Value)
{
	cout<<"Sorting :: Display"<<endl;
	for(auto at : Value)
	{
		cout<<at<<endl;
	}
}
template<typename T>
void Sorting<T>::Swap(vector<T> &Value, int source,int dest)
{
	auto temp = Value[source];
	Value[source] = Value[dest];
	Value[dest] = temp;
}
template<typename T>
void SelectionSort<T>::Sort()
{
	cout<<"SelectionSort :: Sort"<<endl;
	auto Small=Sorting<T>::_data[0];
	int index;
	bool changed =false;

	for (size_t i = 0; i < Sorting<T>::_data.size(); i++)
	{
		Small = Sorting<T>::_data[i];
		for(size_t j = i+1;j<Sorting<T>::_data.size();j++)
		{
			if(Sorting<T>::_data[j]<Small)
			{
				Small = Sorting<T>::_data[j];
				index = j;
				changed = true;
			}
		}
		if(changed)
		{
			Sorting<T>::Swap(Sorting<T>::_data, i,index);
		}
		changed = false;
	}
}



template<typename T>
void MergeSort<T>::Sort()
{
	cout<<"Merge :: Sort"<<endl;

	vector<T> _lData = Sorting<T>::_data;
	vector<vector<T>> _arrVector;
	vector<vector<T>> _tempVector;
	vector<T> _tData;

	for(auto at: _lData)
	{
		_tData.clear();
		_tData.push_back(at);
		_arrVector.push_back(_tData);
	}
	size_t size = _arrVector.size();
	cout<<"Merge :: Sort size "<< size<<endl;
	while(size > 1)
	{
		_tempVector.clear();
		for(size_t i =0; i < size; i++)
		{
			if(i+1 < size)
			{
				_tData = mergeArray(_arrVector[i],_arrVector[i+1]);
				i = i+1;
			}
			else
			{
				_tData = _arrVector[i];
			}
			_tempVector.push_back(_tData);
			_tData.clear();
		}
		_arrVector.clear();
		_arrVector = _tempVector;
		size = _arrVector.size();
		cout<<"Merge :: Sort tsize "<< size<<endl;
	}
	Sorting<T>::_data = _arrVector[0];
}

template<typename T>
vector<T> MergeSort<T>::mergeArray(vector<T> &arr1, vector<T> &arr2)
{
	size_t s1 = arr1.size();
	size_t s2 = arr2.size();

	size_t ref1 = 0;
	size_t ref2 = 0;
	vector<T> mArr;

	while(ref1<s1 || ref2<s2)
	{
		if(ref1==s1) // rest of element push into the vector for array 2
		{
			for(size_t i = ref2; i<s2; i++)
			{
				mArr.push_back(arr2[i]);
			}
			break;
		}
		if(ref2==s2) // rest of element push into the vector for array 1
		{
			for(size_t i = ref1; i<s1; i++)
			{
				mArr.push_back(arr1[i]);
			}
			break;
		}
		// compaire and push the small value into temp array
		if(arr1[ref1] < arr2[ref2])
		{
			mArr.push_back(arr1[ref1]);
			ref1++;
		}
		else
		{
			mArr.push_back(arr2[ref2]);
			ref2++;
		}

	}
 return mArr;
}

/*
 * Quick Sort ::
 *
 *
 * */


template<typename T>
void QuickSort<T>::Sort()
{
	cout<<"Quick :: Sort"<<endl;

	vector<T> _lData = Sorting<T>::_data;
	//create a two dimensional array to store device array
	vector<vector<T>> _2DArry;
	//Temp create a two dimensional array to store device array
	vector<vector<T>> _2DTArry;
	//Final array create a two dimensional array to store device array
	vector<vector<T>> _2DFinalArry;

	_2DArry.push_back(_lData);
	size_t size = _lData.size();
	size_t TSize = _2DArry.size();
	size_t count = 0;
	bool flag = 1;
	while(flag)
	{
		for(auto at : _2DArry)
		{
			/*devide array with three parts from 0 to pivot , pibot+1 to n-1*/
			_2DTArry = GetPivotArray(at);
			for(auto at : _2DTArry)
			{
				_2DFinalArry.push_back(at);
			}
			_2DTArry.clear();
		}
		_2DArry = _2DFinalArry;
		_2DFinalArry.clear();
		flag = 0;
		for(auto at : _2DArry)
		{
			if(at.size() > 1)
			{
				flag = 1;
				break;
			}
		}
	}
	Sorting<T>::_data.clear();
	for(auto at : _2DArry)
	{
		Sorting<T>::_data.push_back(at[0]);
	}

}
template<typename T>
vector<vector<T>> QuickSort<T>::GetPivotArray(vector<T> &arr1)
{
	vector<T> arr =  arr1;
	vector<T> tempArr;
	bool found = 0;

	lData.clear();
	size_t size = arr1.size();
	if(size>1)
	{
		T pivot = arr1[size-1];
		size_t i = 0;
		size_t pIndex = 0;

		for(i = 0; i < size-1; i++)
		{
			if(arr[i] < pivot)
			{
				if(arr[i] != arr[pIndex])
				{
					Sorting<T>::Swap(arr,i,pIndex);
				}
				pIndex++;
			}
		}
		Sorting<T>::Swap(arr,size-1,pIndex);
		for(int i=0;i<pIndex;i++)
		{
			tempArr.push_back(arr[i]);
			found = 1;
		}
		if(found)
		{
			lData.push_back(tempArr);
			tempArr.clear();
		}

		tempArr.push_back(arr[pIndex]) ;
		lData.push_back(tempArr);
		tempArr.clear();
		found = 0;
		for(int i=pIndex+1;i<size;i++)
		{
			int j = 0;
			tempArr.push_back(arr[i]);
			found = 1;
			j++;
		}
		if(found)
		{
			lData.push_back(tempArr);
			tempArr.clear();
		}

	}
	else if(size == 1)
	{
		lData.push_back(arr);
	}

	for(auto at: lData)
	{
		cout<<"Elemetnts Are In pivote"<<endl;
		Sorting<T>::Display(at);
	}
	return lData;
}


int main()
{
	int type;
	cout<<"Selection :: 0 "<<"Insertion :: 1 "<<"Bubble :: 2 merge :: 3 Quick : 4"<<endl;

	cin>>type;
	switch(type)
	{
		case SortType::eSelection:
		{
			Sorting<int> *ptr =  new SelectionSort<int>;
			Sorting<string> *ptr1 =  new SelectionSort<string>;
			if(nullptr!= ptr)
			{
				vector<int> v = {23,56,24,1,567,234,34,900};
				for(auto at : v)
				{
					ptr->Insert(at);
				}
				ptr->Sort();
				ptr->Display();

				vector<string> sv = {"tapu","papli","putul","mausi","ram"};
				//vector<char> sv = {23,56,24,1,3,4,34,123};

				for(auto at : sv)
				{
					ptr1->Insert(at);
				}
				ptr1->Sort();
				ptr1->Display();
			}
			delete ptr;
			delete ptr1;

		}
		break;
	case SortType::eInsertion:
	{

	}
		break;
	case SortType::eBubble:
	{

	}
			break;
	case SortType::merge:
	{
		Sorting<int> *ptr =  new MergeSort<int>;
		Sorting<string> *ptr1 =  new SelectionSort<string>;
		if(nullptr!= ptr)
		{
			vector<int> v = {23,56,24,1,567,234,34};
			for(auto at : v)
			{
				ptr->Insert(at);
			}
			ptr->Sort();
			ptr->Display();

			vector<string> sv = {"tapu","papli","putul","mausi","ram"};
			//vector<char> sv = {23,56,24,1,3,4,34,123};

			for(auto at : sv)
			{
				ptr1->Insert(at);
			}
			ptr1->Sort();
			ptr1->Display();
		}
		delete ptr;
		delete ptr1;
	}
			break;
	case SortType::Quick:
	{
		Sorting<int> *ptr =  new QuickSort<int>;
		if(nullptr!= ptr)
		{
					vector<int> v = {23,56,24,1,567,234,34};
					for(auto at : v)
					{
						ptr->Insert(at);
					}
					ptr->Sort();
					ptr->Display();
					Searching<int> *ser = new BinarySearch<int>;
					ser->Insert(ptr->getSorted());
					cout<<"Position  "<<ser->Search(56)<<endl;
					cout<<"Position  "<<ser->Search(1)<<endl;
					cout<<"Position  "<<ser->Search(13)<<endl;
		}
		ptr = nullptr;
		break;
	}
	default:
	{

	}
		break;
	}

	return 0;
}
template<typename T>

int BinarySearch<T>::Search(T value)
{
	int po = 0;
	int mid = Searching<T>::_data.size()/2;
	int size = Searching<T>::_data.size()-1;
	bool found = false;


	while(mid)
	{
		if(value == Searching<T>::_data[mid])
		{

				po = mid;
				found = true;
				break;

		}
		if(value > Searching<T>::_data[mid])
		{
			po = mid+1;
			mid = (po+size)/2;
		}
		else if(value < Searching<T>::_data[mid])
		{
			size = mid-1;
			mid = (po+size)/2;
			if(!size)
			{
				if(value == Searching<T>::_data[mid])
						{

								po = mid;
								found = true;

						}
			}
		}

	}
	if(!found)
		po = -1;

	return po;
}
