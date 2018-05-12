/*
 * ListBase.cpp
 *
 *  Created on: 27-Feb-2018
 *      Author: tapesh
 */

#include "SingleList.hpp"

int main()
{
	//shired_ptr<ListBase> ptr = make_shired(SingleList<int> value)
	//SingleList<int> list={1,2,3,46,6,7,5};

	//ListBase<int> *ptr = new(SingleList<int>);
	//SingleList list;
	SingleList<int> list={1,2,3,46,6,7,5};
	list.Display();
	list.Insert(2376);
	list.Display();
	return 0;
}




