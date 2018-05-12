/*
 * DoTask.h
 * The class is design to perform
 * reading and writing task
 *  Created on: 05-Mar-2018
 *      Author: tapesh
 */

#ifndef DOTASK_H_
#define DOTASK_H_
//#include "../FrameWork/FrameWork.hpp"
#include "../BaseType.h"
#include "../CsvFiles/CsvFiles.h"
#include "../ReadWriteLive/ReadWriteLive.h"
#include <sys/stat.h> // For struct stat and stat()

class DoTask
{
protected :

	/*
	 * IfFileModifyed always return false if input
	 * file is not modified by external source
	 *
	 * */
	bool IfFileModifyed(const std::string &InPath, std::string &Output);

	/*last time file is modified*/
	struct timespec _last;
public:

	DoTask(){
		/*Initialize last time stamp for the file*/
		_last.tv_nsec = 0;
		_last.tv_sec = 0;
	}

	/* Interface to USER  ICreateTask
	 *  InPath :- Input path for reading file
	 *  OutPath :- Outpath to write result in a record
	 * */
	tErrorMsg ICreateTask(const std::string &InPath, const std::string &OutPath);
};

#endif /* DOTASK_H_ */
