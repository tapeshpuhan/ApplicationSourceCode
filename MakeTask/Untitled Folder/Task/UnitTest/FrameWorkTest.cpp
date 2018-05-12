/*
 * FrameWorkTest.cpp
 * Unit test for Framework functionality
 * tested functinality are :--
 * msg queue
 * is double
 * get token
 *  Created on: 09-Mar-2018
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
struct FrameWorkTest:public ::testing::Test
{

	void SetUp(){
		cout<<"My Test Feature Start MsgQueueTest"<<endl;

	}
	void TearDown()
	{
		cout<<"My Test Feature End MsgQueueTest"<<endl;
	}

};
/**
 * Test Msg Queue function with input of a string value
 * pop the element till end of the queue reached
 *
 */
TEST_F(FrameWorkTest,TestInsertString)
{
	std::pair<bool,string> value1(true,"");
	std::pair<bool,string> value2(true,"");
	std::pair<bool,string> value3(true,"");
	std::pair<bool,string> value4(true,"");

	MsgQueue<string>::Instance()->push("Hi My Friend");
	MsgQueue<string>::Instance()->push("Hope You Are Fine");
	MsgQueue<string>::Instance()->push("HAVE A# $ Nice Day");


	value1 = MsgQueue<string>::Instance()->pop();
	cout<<value1.second.c_str();
	ASSERT_STREQ(value1.second.c_str(),"Hi My Friend");
	EXPECT_EQ(value1.first,true);

	value2 = MsgQueue<string>::Instance()->pop();
	cout<<value2.second.c_str();
	ASSERT_STREQ(value2.second.c_str(),"Hope You Are Fine");
	EXPECT_EQ(value2.first,true);

	value3 = MsgQueue<string>::Instance()->pop();
	cout<<value3.second.c_str();
	ASSERT_STREQ(value3.second.c_str(),"HAVE A# $ Nice Day");
	EXPECT_EQ(value2.first,true);

	value4 = MsgQueue<string>::Instance()->pop();
	EXPECT_EQ(value4.first,false);
}
/**
 * test get token function with valid input
 */
TEST_F(FrameWorkTest,TestGetToken_Input1)
{
	vector<string> info;
	string del = ",";
	string Input = "I am,Your,Best,Friend";

	Utils::Instance()->getToken(Input,del,info);

	ASSERT_STREQ(info[0].c_str(), "I am");
	ASSERT_STREQ(info[1].c_str(), "Your");
	ASSERT_STREQ(info[2].c_str(), "Best");
	ASSERT_STREQ(info[3].c_str(), "Friend");

}
/**
 * test get token function with starting deleminator
 */
TEST_F(FrameWorkTest,TestGetToken_Input2)
{
	vector<string> info;
	string del = ",";
	string Input = ",I am,Your,Best,Friend";

	Utils::Instance()->getToken(Input,del,info);

	ASSERT_STREQ(info[0].c_str(), "I am");
	ASSERT_STREQ(info[1].c_str(), "Your");
	ASSERT_STREQ(info[2].c_str(), "Best");
	ASSERT_STREQ(info[3].c_str(), "Friend");

}
/**
 * test get token function with starting
 * Continuous deleminator
 */
TEST_F(FrameWorkTest,TestGetToken_Input3)
{
	vector<string> info;
	string del = ",";
	string Input = ",I am,Your,,Best,Friend";

	Utils::Instance()->getToken(Input,del,info);

	ASSERT_STREQ(info[0].c_str(), "I am");
	ASSERT_STREQ(info[1].c_str(), "Your");
	ASSERT_STREQ(info[2].c_str(), "Best");
	ASSERT_STREQ(info[3].c_str(), "Friend");

}
/**
 * test get token function with starting
 *  deleminator at end of the string
 */
TEST_F(FrameWorkTest,TestGetToken_Input4)
{
	vector<string> info;
	string del = ",";
	string Input = ",I am,Your,,Best,Friend,";

	Utils::Instance()->getToken(Input,del,info);

	ASSERT_STREQ(info[0].c_str(), "I am");
	ASSERT_STREQ(info[1].c_str(), "Your");
	ASSERT_STREQ(info[2].c_str(), "Best");
	ASSERT_STREQ(info[3].c_str(), "Friend");

}
/**
 * test is double function with valid input
 */
TEST_F(FrameWorkTest,Testis_double_Input1_sucess)
{

	string Input1 = "2.35";
	string Input2 = ".4572947363130";
	string Input3 = "4572947363130.";

	bool res;

	res = Utils::Instance()->is_double(Input1);
	EXPECT_EQ(res,true);

	res = Utils::Instance()->is_double(Input2);
	EXPECT_EQ(res,true);

	res = Utils::Instance()->is_double(Input3);
	EXPECT_EQ(res,true);
}
/**
 * test is double function with invalid input
 */
TEST_F(FrameWorkTest,Testis_double_Input1_failure)
{

	string Input1 = "2.3A5";
	string Input2 = "ABC.Df";
	string Input3 = "4572947.36313.0";
	string Input4 = "..457294736313.0";

	bool res;

	res = Utils::Instance()->is_double(Input1);
	EXPECT_EQ(res,false);

	res = Utils::Instance()->is_double(Input2);
	EXPECT_EQ(res,false);

	res = Utils::Instance()->is_double(Input3);
	EXPECT_EQ(res,false);

	res = Utils::Instance()->is_double(Input4);
	EXPECT_EQ(res,false);
}
#endif


