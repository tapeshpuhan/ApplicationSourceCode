/*
 * ReadingFileTest.cpp
 *
 *  Created on: 10-Mar-2018
 *      Author: tapesh
 */
#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "ReadWriteLive.h"
#include "CsvFiles.h"
#include <iostream>

using namespace std;
//usings for gmock
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

#if TASKUNITTEST

void CreateMaximum(string file)
{
	ofstream outputfile(file,ios::out|ios::app);
	string ds;
	if(!outputfile.fail())
	{
		string value = "2014.01.02T12:00:14, 67 1234 5678 0000 0000 1234 5678,  1234 5678";
		double d=0.1;
		for(u32Int i= 0; i < 350000; i++)
		{
			outputfile<<value.c_str()<<" "<<i<<", "<<d+i<<endl;
			ds.clear();
		}
		outputfile.close();
	}
}

/**
 * TestThreadToRead Test case to test reading file
 *
 */
struct TestThreadToRead:public ::testing::Test
{
	void SetUp(){
			cout<<"My Test Feature Start MsgQueueTest"<<endl;
	}
	void TearDown()
	{
			cout<<"My Test Feature End MsgQueueTest"<<endl;
	}
	ThreadToRead oThredRead;

};

TEST_F(TestThreadToRead, TestdoTaskToReadSucess2)
{
	oThredRead.operator ()("/home/tapesh/C++/Task/file1.csv");
}
TEST_F(TestThreadToRead, TestdoTaskToReadSucess1)
{

	oThredRead.operator ()("/home/tapesh/C++/Task/file.csv");

}
TEST_F(TestThreadToRead, TestdoTaskToReadSucess3)
{
	oThredRead.operator ()("/home/tapesh/C++/Task/UTest1.csv");
}
TEST_F(TestThreadToRead, TestdoTaskToReadSucessEmptyFile)
{
	//CreateMaximum("/home/tapesh/C++/Task/UtestMax.csv");
	oThredRead.operator ()("/home/tapesh/C++/Task/Utest2.csv");
}
/**
 * TestThreadToRead Test case to test reading file
 *
 */
struct TestThreadToWrite:public ::testing::Test
{
	void SetUp(){
			cout<<"My Test Feature Start TestThreadToWrite"<<endl;
	}
	void TearDown()
	{
			cout<<"My Test Feature End TestThreadToWrite"<<endl;
	}
	ThreadToWrite oThredWrite;

};

TEST_F(TestThreadToWrite, TestdoTaskToWriteSuces)
{

	oThredWrite.operator ()("/home/tapesh/C++/Task/Utest2.txt");
}
#endif



