/*
 * CsvFile.cpp
 *
 *  Created on: 03-Mar-2018
 *      Author: tapesh
 */

#include "CsvFiles.h"
#include<iomanip>

using namespace std;

tErrorMsg CsvFileOp::readCsvFile(const std::string &path,tGetLine &info,
		u32Int &position)
{
#if Debug
	cout<<"readCsvFile start"<<endl;
#endif
	lock_guard<mutex> lk(Lock);
	tErrorMsg result = ErrorMsg::msg_ok;


	ifstream file(path);
	if(!file.is_open())
	{
		cout<<"ERROR: Error in File opening"<<path.c_str();
		result = ErrorMsg::msg_read_error;
	}
	//if open file successful
	if(ErrorMsg::msg_ok == result)
	{
		try	{
			//go to previous line
			GotoLine(file,position);
			while(file.good())
			{
				string line;

				if(ErrorMsg::msg_ok == result)
				{

					getline(file,line);
					if(line !="")//check for valid line
					{
						info.insert(line);
					}
					if(file.good())
					{
						position = file.tellg();
						//cout<<"position  "<<position<<endl;
					}

				}
			}
		}
		catch(const ifstream::failure& e)
		{
			cout<<"ERROR : reading file error"<<e.what()<<endl;
			result = ErrorMsg::msg_read_line_error;
		}
	}
	file.close();

#if Debug
	cout<<"readCsvFile End"<<endl;
#endif
	return result;
}


tErrorMsg CsvFileOp::writeTxtFile(const std::string &path,
		const std::vector<BankInfo> &info,const long double TotalAmt
		,unsigned int newRecord)
{
#if Debug
	cout<<"writeTxtFile start"<<endl;
#endif
	lock_guard<mutex> lk(Lock);
	tErrorMsg result = ErrorMsg::msg_ok;
	unsigned int count = 1;

	try{
		ofstream outputfile(path,ios::out|ios::app);
		if(outputfile.fail())
		{
			result = ErrorMsg::msg_write_fileopen_error;
		}
		else
		{
			outputfile<<std::setprecision(2)<<std::fixed;
			outputfile<<"************************************************************************************************"<<endl;
			outputfile<<endl<<"   TOTAL NUMBER OF NEW RECORD(S) READ                      ::                  "<<newRecord<<endl;
			outputfile<<"************************************************************************************************"<<endl;
			outputfile<<" SlNo        Target Account Number                                             Amount Available "<<endl;
			for(auto &at : info)
			{
				outputfile<<" "<<count++<<"        |";
				outputfile<<" "<<at.TargetAccount<<"                          |            "
						<<"      "<<at.Amount<<"\n"<<endl;
			}
			outputfile<<"__________________________________________________________________________________________________"<<endl;

			outputfile<<"\n"<<endl;

			outputfile<<"     Sum of The Amount for New Records ::                                      |      "<<TotalAmt<<endl;
			outputfile<<"************************************************************************************************"<<endl;
			outputfile.close();
		}
	}
	catch(const ofstream::failure& e)
	{
		cout<<"ERROR : write file error"<<e.what()<<endl;
		result = ErrorMsg::msg_write_fileopen_error;
	}
#if Debug
	cout<<"writeTxtFile End"<<endl;
#endif
	return result;
}

void CsvFileOp::GotoLine(std::ifstream& file, u32Int num)
{
#if Debug
	cout<<"Last Position "<<num<<endl;
#endif
	file.seekg(num,std::ios::beg);
}

tErrorMsg CsvFileOp::ClearTxtFile(const std::string &path)
{
	lock_guard<mutex> lk(Lock);
	tErrorMsg result = ErrorMsg::msg_ok;

	//clear file before write into new record
	ofstream outputfile(path,ios::out);
	if(outputfile.fail())
	{
		result = ErrorMsg::msg_write_fileopen_error;
	}
	else
	{
		outputfile.close();
	}
	return result;
}
