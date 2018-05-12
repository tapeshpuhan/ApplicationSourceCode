/*
 * DoTask.cpp
 * Create Two threads.
 * Thread1 :::::: ThreadToRead "To read line information in sorted order
 * :- "
 * Thread 2  :::::: ThreadToWrite
 * ::- Read file and parse it to Bank information
 * ::- Calculate target account amount and sort it as descending order
 * ::- Write into a new file as new record
 *  Created on: 05-Mar-2018
 *      Author: tapesh
 */
#include"DoTask.h"
#include<thread>

tErrorMsg DoTask::ICreateTask(const std::string &InPath, const std::string &OutPath)
{
	tErrorMsg res = ErrorMsg::msg_ok;
	unsigned int uRecord=0;
	while(1)
	{
		string ext;//get the last time stamp to recreate new record with time stamp
		if(true == IfFileModifyed(InPath, ext))
		{

			/*Spawn reader thread
			 * pass last position as output reference
			 * */
			std::thread thRead((ThreadToRead()),InPath);
			if(thRead.joinable())
			{
				/*Join reader thread*/
				thRead.join();
			}

			/*Spawn writer thread
			 * Pass output file name to store record
			 * */
			thread thWrite((ThreadToWrite()),InPath+std::to_string(uRecord++)+".txt");
			if(thWrite.joinable())
			{
				/*Join writer thread*/
				thWrite.join();
			}
			//cancel both threads
			if(thRead.joinable())
			{
				thRead.~thread();
			}
			if(thWrite.joinable())
			{
				thWrite.~thread();
			}
		}
		/*sleep for few seconds until new record updated in csv file.
		 * in sample application i slept for 5 sec , in real app the value
		 * can be configure.
		 */
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
	return res;
}

/***
 * This function will return true if input file is updated by external source.
 */
bool DoTask::IfFileModifyed(const std::string &InPath, std::string &Output)
{
	struct stat stResult;
	bool modified = false;

	if(stat(InPath.c_str(), &stResult) == 0)
	{
		//from system get the last modified time and compared with last
		//modified time
		bool nsec = (_last.tv_nsec==stResult.st_mtim.tv_nsec);
		bool sec = (_last.tv_sec==stResult.st_mtim.tv_sec);
		if((!nsec) || (!sec))
		{
			modified = true;
		}
		_last=stResult.st_mtim;
#ifdef Debug
		std::cout<<stResult.st_mtim.tv_nsec<<" :: ";
		std::cout<<stResult.st_mtim.tv_sec<<std::endl;
#endif
		Output = std::to_string(stResult.st_mtim.tv_nsec);
		Output += std::to_string(stResult.st_mtim.tv_sec);
	}
	return modified;
}

