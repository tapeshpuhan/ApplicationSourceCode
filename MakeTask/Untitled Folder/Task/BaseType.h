/*
 * BaseType.h
 * This file will provide
 * data types
 *  Created on: 03-Mar-2018
 *      Author: tapesh
 */

#ifndef BASETYPE_H_
#define BASETYPE_H_
/*
 * Header Declarations
 */
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<set>
#include <limits>
#include<memory>
#include<set>
#include <algorithm>
#include<queue>
#include <mutex>
#include <condition_variable>
#include<thread>
#include <deque>
/*
 * TASKUNITTEST Macro should be enable when
 * needs google unit test.
 * It is because of avoiding multiple defination
 * error main.
 */
//#define TASKUNITTEST 1

/*
 * Debug should be enable when debugging source code.
 *
 */
//#define Debug 1

using u32Int = size_t;

/*
 * Message type returns from the
 * method call.
 */
using tErrorMsg = enum class ErrorMsg{
	msg_ok=0,
			msg_read_error,
			msg_read_max,
			msg_read_line_error,
			msg_write_fileopen_error,
			msg_parsefailed,
			msg_TaskFailed,
			msg_AmountInvalid,
			msg_PathInvalid
};
/**
 * BankInfo is container of bank information
 * date , source account , target account and
 * total amount available for each target account.
 */
struct BankInfo
{
	std::string Date;
	std::string SourceAccount;
	std::string TargetAccount;
	long double Amount;
	//constructor to initialize default value.
	BankInfo():Date(""),SourceAccount(""),TargetAccount(""),
			Amount(0.0){}
	//overload > operator to sort Bank info in Descending order
	bool operator>(BankInfo &info)
	{
		return Amount > info.Amount;
	}
	//overload > operator to sort Bank info in Ascending order
	bool operator<(BankInfo &info)
	{
		return Amount < info.Amount;
	}
};

/**
 * Declared types
 */
//List of Bankinfo
using tBankInfo = std::vector<BankInfo>;

//map which key value is Target Account and value is bankinfo
using tTargetAcc = std::map<std::string,BankInfo>;

//set stl is used to collect duplicate line from the log
using tGetLine =std::set<std::string>;

#endif /* BASETYPE_H_ */
