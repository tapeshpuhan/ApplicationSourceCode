/*
 * TestAll.cpp

 *
 *  Created on: 08-Mar-2018
 *      Author: tapesh
 */
#include<gtest/gtest.h>
#include "CsvFiles.h"
//#include "DoTaskTest.cpp"

#ifdef TASKUNITTEST
int main(int argc, char** argv)
{
	//unit test start
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
#endif



