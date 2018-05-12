/*
 * ReadWriteLive.h
 * This Module perform read and write operation
 * in concurrent manner
 *  Created on: 04-Mar-2018
 *      Author: tapesh
 */

#ifndef READWRITELIVE_H_
#define READWRITELIVE_H_
#include "../FrameWork/FrameWork.hpp"
#include "../BaseType.h"
#include "../CsvFiles/CsvFiles.h"

/**
 * Class : ThreadToRead
 * 		   Object which perform
 * 		   reading operation from the input file
 */
class ThreadToRead
{
public:
	//Constructor
	ThreadToRead(){

	}

	//Destroctor
	~ThreadToRead(){

	}

	/*overload () operator to pass address of the constructor
	 * the thread call can be pass as parameter.
	 * Agumets are input path and previous line number of input file.
	 */
    void operator()(const std::string &path)
    {
    	doTaskToRead(path);
    }

protected:

    //local function for doing read file operation
	void doTaskToRead(const std::string &path);
};

/**
 * Class : ThreadToWrite
 * 		   Object which perform
 * 		   write operation on new record
*/
class ThreadToWrite
{

public:

	/*
	 * eRecord is a enum type to specify order of
	 * bank informations
	 */
	typedef enum  {Date=0,sAcc,tAcc,Amount} eRecord;

	//constructor
	ThreadToWrite();

	//destructor
	~ThreadToWrite(){

	}

	/*overload () operator to pass address of the constructor
	 * the thread call can be pass as parameter.
	 * Arguments are output path and previous line number of input file.
	 */
    void operator()(const std::string &path)
    {
    	doTaskToWrite(path);
    }

    /*
     * Interface which provide user to clear the record
     */
	void clearRecord(const std::string &path);

protected:
	//member function
	//local function for doing write file operation
	void doTaskToWrite(const std::string &path);

	/*
	 * parseInput
	 * this is local method which is used to pass
	 * Comma separated line as input argument and get
	 * each target bank info
	 */
	tErrorMsg parseLine(const std::string &line,
			BankInfo &Binfo);

	//member variable

	//Each Target Account information
	tTargetAcc _lTargetAcc;

	//get sum of total amount.
	long double _SumNewRecAmount;

	//List of Account info to be stored in new record
	std::vector<BankInfo> _AccInfo;
};


#endif /* READWRITELIVE_H_ */
