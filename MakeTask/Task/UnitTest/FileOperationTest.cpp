/*
 * CsvFileTest.cpp
 * Unit test for CSVFile Class
 *  Created on: 08-Mar-2018
 *      Author: tapesh
 */


#include<gtest/gtest.h>
#include "ReadWriteLive.h"
#include "CsvFiles.h"
#include <iostream>
using namespace std;

#if TASKUNITTEST

/**
 * ReadCsvFileTest Test case to test reading file
 *
 */
struct ReadCsvFileTest:public ::testing::Test
{
	IFileOp *filePtr;

	void SetUp(){
		cout<<"My Test Feature Start ReadCsvFileTest"<<endl;
		filePtr = new CsvFileOp();
	}
	void TearDown()
	{
		cout<<"My Test Feature End ReadCsvFileTest"<<endl;
		delete filePtr;
	}

};

/**
 * Test case to read a valid file with one line and verify
 * the line and size return type for the function call
 */
TEST_F(ReadCsvFileTest, TestdoTaskToReadSucess2)
{

	tErrorMsg ret;
	tGetLine info;
	u32Int size;

	if(filePtr!=nullptr)
	{
		ret = filePtr->readCsvFile("/home/tapesh/C++/Task/file1.csv",info,size);
	}
	EXPECT_EQ(ret,tErrorMsg::msg_ok);
}

/**
 * Test case to read a valid file with one line and verify
 * the line and size return type for the function call
 */
TEST_F(ReadCsvFileTest, TestdoTaskToReadSucess1)
{
	tErrorMsg ret;
	tGetLine info;
	u32Int size;

	if(filePtr!=nullptr)
	{
		ret = filePtr->readCsvFile("/home/tapesh/C++/Task/file.csv",info,size);
	}
	EXPECT_EQ(ret,tErrorMsg::msg_ok);
}

/**
 * Test case to read a valid file with one line and verify
 * the line and size return type for the function call
 */
TEST_F(ReadCsvFileTest, test1ReadTest1File)
{
	tErrorMsg ret;
	tGetLine info;
	u32Int size;

	if(filePtr!=nullptr)
	{
		ret = filePtr->readCsvFile("/home/tapesh/C++/Task/UTest1.csv",info,size);
	}
	for(auto &at : info)
	{
		cout<<"string "<<at.c_str()<< " "<< size<<endl;
	}
	EXPECT_EQ(ret,tErrorMsg::msg_ok);
}

/**
 * Test case to read a valid file
 */
TEST_F(ReadCsvFileTest, test1ReadAvalidFile)
{
	tErrorMsg ret;
	tGetLine info;
	u32Int size;

	if(filePtr!=nullptr)
	{
		ret = filePtr->readCsvFile("/home/tapesh/C++/Task/file.csv",info,size);
	}
	EXPECT_EQ(ret,tErrorMsg::msg_ok);
}

/**
 * Test case to verify invalid file
 */
TEST_F(ReadCsvFileTest, test1ReadNotAvalidFile)
{
	tErrorMsg ret;
	tGetLine info;
	u32Int size;

	if(filePtr!=nullptr)
	{
		ret = filePtr->readCsvFile("/home/tapesh/C++/Task/file_notavail.csv",info,size);
	}
	EXPECT_EQ(ret,tErrorMsg::msg_read_error);
}

/**
 * Test feature to test of write functionality .
 */
struct WriteCsvFileTest:public ::testing::Test
{
	IFileOp *filePtr;

	void SetUp(){
		cout<<"My Test Feature Start ReadCsvFileTest"<<endl;
		filePtr = new CsvFileOp();
	}
	void TearDown()
	{
		cout<<"My Test Feature End ReadCsvFileTest"<<endl;
		delete filePtr;
	}

};

/**
 * ReadCsvFileTest Test case to test reading file
 *
 */
/**
 * Test case to write test with valid input
 */
TEST_F(WriteCsvFileTest, test1writeAvalidFile)
{
	tErrorMsg ret;
	std::vector<BankInfo> i;
	const long double TotalAmt=100;
	if(filePtr!=nullptr)
	{
		ret = filePtr->writeTxtFile("/home/tapesh/C++/Task/file.csv.txt",i,TotalAmt,100);
	}
	ifstream file("/home/tapesh/C++/Task/file.csv.txt");
	EXPECT_EQ(true,file.is_open()); //verify output file open sucess
	EXPECT_EQ(ret,tErrorMsg::msg_ok);
}


#endif



