/*
 * MergeSort.cpp
 *
 *  Created on: 01-Apr-2018
 *      Author: tapesh
 */
#if 0
#include "BaseFile.h"

template<typename T>
class merge_sort
{
	vector<T> _merge;
public:
	merge_sort(){}
	merge_sort(const initializer_list<T> &list)
	{
		_merge.asign(list.begin(),list.end());
	}
	void r_merge(vector<T> &data,size_t start, size_t end,size_t middle);
	void r_mergeSort(vector<T> &data, size_t start, size_t end);
	void recursion();
};

template<typename T>
void merge_sort<T>::recursion()
{
	r_mergeSort(_merge, 0, _merge.size());
}
template<typename T>
void merge_sort<T>::r_mergeSort(vector<T> &data, size_t start, size_t end)
{
	if(start<end)
	{
		size_t middle = (start+end)/2;
		r_mergeSort(data,start,middle);
		r_mergeSort(data,middle+1,start);
		r_merge(data,start,end,middle);
	}
}
template<typename T>
void merge_sort<T>::r_merge(vector<T> &data, size_t start, size_t end,size_t middle)
{

}
#endif
