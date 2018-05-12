/*
 * Sorting.h
 *
 *  Created on: 17-Feb-2018
 *      Author: tapesh
 */


#ifndef SORTING_H_
#define SORTING_H_

#include<iostream>
#include<vector>
#include<string>
#include <chrono>
using namespace std;


enum SortType
{
	eSelection=0,
	eInsertion,
	eBubble,
	merge,
	Quick
};
// Bace class to insert elements
template<typename T>
class Sorting
{
public:
	using tTwoArray = vector<vector<T>>;
	void Insert(T data);
	void Display();
	void Display(vector<T> &Value);
	void Swap(vector<T> &Value, int source,int dest);

	virtual void Sort()=0;
	virtual ~Sorting(){_data.clear();}
	vector<T> & getSorted()
	{
		return _data;
	}
protected:
	vector<T> _data;
};

template<typename T>
class SelectionSort:public Sorting<T>
{
public:

	void Sort();
};

template<typename T>
class MergeSort:public Sorting<T>
{
private:
	vector<T> mergeArray(vector<T> &arr1, vector<T> &arr2);
public:

	void Sort();
};

/*
 * select Pivot as end of the list
 * Find the correct position of the pivot
 *
 *[
 * compair i = 0 , pindex = 0
 *  if a[i] is greater than pivote do nothing only i++
 * if a[i] is less than pivote swap a[pindex] to a[i]
 * then i++ and pindex++
 * After list complete swap a[pindex] to pivot
 * ]
 * Continue this process until array is divide to single element
 *
 * */
template<typename T>
class QuickSort:public Sorting<T>
{
private:
	vector<vector<T>> GetPivotArray(vector<T> &arr1);
	vector<vector<T>> lData;
public:

	void Sort();
};

template<typename T>
class Searching
{
public:

	void Insert(const vector<T> &data)
	{
		_data = data;
	}

	virtual int Search(T value)=0;
	virtual ~Searching(){_data.clear();}
protected:
	vector<T> _data;
};

template<typename T>
class BinarySearch:public Searching<T>
{
public:

	int Search(T value);
};

#endif /* SORTING_H_ */
