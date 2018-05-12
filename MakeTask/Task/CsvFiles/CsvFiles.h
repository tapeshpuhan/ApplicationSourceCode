/*
 * CsvFiles.h
 *
 *  Created on: 03-Mar-2018
 *      Author: tapesh
 *      description :-
 *      this class is created to all file operation
 *      Related to task.
 *      1. read iput file reqested from user
 *      2, write output into enother file
 *      3. clear the file to write data from begining
 */

#ifndef CSVFILES_H_
#define CSVFILES_H_
#include "../BaseType.h"

/**
 * IFileOp is a interface class to do all file operation
 * */

class IFileOp
{

public:
	IFileOp(){}
	/*
	 * Method name : readCsvFile
	 * Input : file path , size of the file to read
	 * Output : BankInfo needs to read from CSV file
	 *  * readCsvFile :-
	 * 1.read input file and return list of string
	 * 2. duplicate lines will be discarded
	 * 3. the lines are in sorted order
	 * 4. it can take a maximum size to avoid buffer overflow for large
	 *    file input.
	 * 5. User can specify how many line needs to read , next read will start from the
	 *    previous position.
	 */
	virtual tErrorMsg readCsvFile(const std::string &path,tGetLine &info, u32Int &position)=0;
	/*
	 * Method name : writeTxtFile
	 * Input : file path
	 * Output : append txt into output file
	 */
	virtual tErrorMsg writeTxtFile(const std::string &path,const std::vector<BankInfo> &info,const long double TotalAmt, unsigned int newRecord)=0;
	/*
	 * Method name : writeTxtFile
	 * Input : file path
	 * Output : clear the file
	 */
	virtual tErrorMsg ClearTxtFile(const std::string &path)=0;
	virtual ~IFileOp(){}
};

class CsvFileOp : public IFileOp
{
protected:
	std::mutex Lock;
	void GotoLine(std::ifstream& file, u32Int num);

public:
	CsvFileOp(){}
	tErrorMsg readCsvFile(const std::string &path,tGetLine &info, u32Int &pSize)override;
	tErrorMsg writeTxtFile(const std::string &path,const std::vector<BankInfo> &info,const long double TotalAmt,unsigned int newRecord)override;
	tErrorMsg ClearTxtFile(const std::string &path);
	~CsvFileOp(){}
};


#endif /* CSVFILES_H_ */
