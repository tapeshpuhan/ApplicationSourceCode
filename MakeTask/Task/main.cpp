/*
 * main.cpp
 *
 *  Created on: 03-Mar-2018
 *      Author: tapesh
 */
#include "./CsvFiles/CsvFiles.h"
#include "./ReadWriteLive/ReadWriteLive.h"
#include "./DoTask/DoTask.h"
#include <unistd.h>

using namespace std;
/*Different Path as input to test
 * Select / select as per test diffrent type of files
 * */
#define INPATH "/home/tapesh/C++/Task/file1.csv"
//#define INPATH "/home/tapesh/C++/Task/file.csv"
//#define INPATH "/home/tapesh/C++/Task/UtestMax.csv"

/**
 * This function used to test C++ .
 * the complete functionality test with input path
 * INPATH
 */
tErrorMsg TaskOpen()
{
	/*
	 * INPATH is a macro specified input path
	 * of csv file . The the input path can
	 * be dynamically applied to
	 */
	string path = INPATH;
	//create a instance of Task to perform task;
	std::unique_ptr<DoTask> fptr(new DoTask);
	/*
	 * ICreateTask called with first parameter
	 * as input csv file , and 2nd as a corresponding
	 * log generated.
	 */
	return fptr->ICreateTask(path, path+".txt");
}

/**
 * This function used to test C++ .
 * the complete functionality test with input path
 * from command line.
 */
tErrorMsg TaskOpen(char* str)
{
	cout<<"Input file "<<str<<endl;
	if(access(str, F_OK) != -1)
	{
		string path = str;
		//create a instance of Task to perform task;
		std::unique_ptr<DoTask> fptr(new DoTask);
		/*
		 * ICreateTask called with first parameter
		 * as input csv file , and 2nd as a corresponding
		 * log generated.
		 */
		return fptr->ICreateTask(path, path+".txt");
	}
	else
	{
		cout<<"ERROR: Fils dose not exit :: Please check file name Thanks"<<endl;
	}
	return ErrorMsg::msg_ok;
}

/**
 * Start of main function
 * User can use bin as Command line
 * example:
 *>> ./Task file.csv
 */
#ifndef TASKUNITTEST
int main(int argc , char*argv[])
{

	tErrorMsg result=ErrorMsg::msg_ok;
	cout<<"Hello Welcome "<<endl;
	cout<<"Command : File name "<<argc<<endl;

	if(argc > 1)
	{
		//Input from command line
		TaskOpen(argv[1]);

	}
	else
	{
		cout<<"ERROR Command : File name "<<endl;	
	}
	return 0;
}
#endif
