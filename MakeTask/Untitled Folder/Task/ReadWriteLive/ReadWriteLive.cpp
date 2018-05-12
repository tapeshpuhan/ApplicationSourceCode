/*
 * ReadWriteLive.cpp
 *
 *  Created on: 04-Mar-2018
 *      Author: tapesh
 */

#include "ReadWriteLive.h"
#include <sys/stat.h>	// For struct stat and stat()
using namespace std;


/*
 * doTaskToRead : read line form input file
 */
void ThreadToRead::doTaskToRead(const string &path)
{

	tErrorMsg result = ErrorMsg::msg_read_max;
	tGetLine info;
	u32Int loc;

	//pointer to access File operations
	unique_ptr<IFileOp> fptr(new CsvFileOp);

	//lock the mutex before read file operation
	std::lock_guard<std::mutex> lock(Mutex::Instance()->_mutex);

	if(nullptr != fptr)
	{
		//read file and store line info and get the last pos of the file
		loc = FilePos::Instance()->getFilepos(path);
		cout<<"pos "<<loc<<endl;
		result = fptr->readCsvFile(path,info,loc);

#if Debug
		cout<<"pos "<<loc<<endl;
		for_each(info.begin(), info.end(),[](string s){cout<<s.c_str()<<endl;});
#endif
		//Push message to message Queue
		if(result==ErrorMsg::msg_ok && !info.empty())
		{
			MsgQueue<tGetLine>::Instance()->push(info);
		}
		FilePos::Instance()->setFilepos(path,loc);
		fptr.reset();
	}

#if Debug
	cout<<"Thread doTaskToRead Notify"<<endl;
#endif

	//notify other thread after completion of task
	Mutex::Instance()->_cond.notify_all();
#if Debug
	cout<<"Thread doTaskToRead End"<<endl;
#endif

}

/*
 * Constructor of ThreadToWrite
 */
ThreadToWrite::ThreadToWrite()
{
	_lTargetAcc.clear();
	_AccInfo.clear();
	_SumNewRecAmount=0.0;
}

/*
 * doTaskToWrite : Write information into new record
 */
void ThreadToWrite::doTaskToWrite(const std::string &path)
{
#if Debug
	cout<<"Thread doTaskToWrite "<<path.c_str()<<endl;
#endif
	tGetLine info;
	tErrorMsg result;
	pair<bool,tGetLine> qInfo(true,info);//MsgQue Info

	//pointer to access File operations
	unique_ptr<IFileOp> fptr(new CsvFileOp);
	BankInfo Info;
	unsigned int Total_record = 0;

	//Lock the shared  Mutex
	std::lock_guard<std::mutex> lock(Mutex::Instance()->_mutex);

	try
	{
		if(nullptr!=fptr)
		{
			while(qInfo.first == true)
			{
#if Debug
				cout<<"Before Pop"<<endl;
#endif
				//Get info from MsgQue
				qInfo = MsgQueue<tGetLine>::Instance()->pop();
#if Debug
				cout<<"After Pop"<<endl;
				for_each(qInfo.second.begin(), qInfo.second.end(),[](string s){cout<<s.c_str()<<endl;});
#endif

				//For each line parse and get Bank information
				for_each(qInfo.second.begin(),qInfo.second.end(),[&](const string &str){
					result = parseLine(str,Info);
					if(ErrorMsg::msg_ok == result)
					{
						//update map in case of valid input
						Total_record++;
						_lTargetAcc.insert(pair<std::string,BankInfo>(Info.TargetAccount,Info));
					}});
				//clear queue
				qInfo.second.clear();
				//collect information from parsed data and store on a vector
				for(auto &at : _lTargetAcc)
				{
					BankInfo bInfo;
					bInfo.Date = at.second.Date;
					bInfo.SourceAccount = at.second.SourceAccount;
					bInfo.TargetAccount = at.second.TargetAccount;
					bInfo.Amount = at.second.Amount;
					_AccInfo.push_back(bInfo);
					//calculate total amount for new record
					_SumNewRecAmount+=bInfo.Amount;
				}
				//clear map for new record
				_lTargetAcc.clear();
				if(_AccInfo.size())
				{
					//sort bank info as per descending order of its amount
					std::sort(_AccInfo.begin(),_AccInfo.end(),[&](BankInfo a, BankInfo b){return a>b;});
				}
#if Debug
				for(auto &at : _AccInfo)
				{
					cout<<" Target Acc "<<at.TargetAccount<<endl;
					cout<<" Amount "<<at.Amount<<endl;
				}
				cout<<fixed<<"Sum Of New Record "<<_SumNewRecAmount<<endl;
#endif
				/*
				 * Update Stored information into new record
				 */
				if(!_AccInfo.empty())
				{
					clearRecord(path);
					fptr->writeTxtFile(path,move(_AccInfo),_SumNewRecAmount,Total_record);
					//clear account info and total sum amount
					_AccInfo.clear();
					_SumNewRecAmount=0.0;
				}
			}
		}
	}
	catch(...)
	{
		cout<<"ERROR : Exception doTaskToWrite"<<endl;
	}

}
/*
 *Clear output record
 */
void ThreadToWrite::clearRecord(const std::string &path)
{
#if Debug
	cout<<"Thread clearRecord "<<path.c_str()<<endl;
#endif
	unique_ptr<IFileOp> fptr(new CsvFileOp);
	fptr->ClearTxtFile(path);
}

/**
 * parseLine : Function to parce comma separated line
 * into vector of bank information
 *  input: Line
 *  Output : Bank Information
 *
 */
tErrorMsg ThreadToWrite::parseLine(const std::string &line,
		BankInfo &Binfo)
{
#if Debug
	cout<<"parseLine"<<endl;
#endif
	tErrorMsg result=ErrorMsg::msg_ok;
	std::string t_str = line;
	vector<string> Info;

	//get list of info from input line
	Utils::Instance()->getToken(line,",",Info);
#if Debug
	for(auto &at : Info)
	{
		cout<<at<<endl;
	}
	cout<<Info.size()<<endl;
#endif

	/**
	 * Line should have at lease 4 input
	 * as Data : source account : Target account :  amount
	 */
	if(Info.size()>=4)
	{
		try{
			Binfo.Date=Info[Date];

			Binfo.SourceAccount = Info[sAcc];

			Binfo.TargetAccount = Info[tAcc];
			//Check amount
			if(!Utils::Instance()->is_double(Info[Amount]))
			{
				return ErrorMsg::msg_AmountInvalid;
			}
			Binfo.Amount = stold(Info[Amount],0);
		}
		catch(...)
		{
			cout<<"ERROR: exception in parseLine"<<endl;
		}
	}
	else
	{
		result = ErrorMsg::msg_parsefailed;
	}
#if Debug
	cout<<"parseLine End"<<endl;
#endif
	return result;
}
