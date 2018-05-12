/*
 * RedundantOp.h
 *
 *  Created on: 09-May-2018
 *      Author: tapesh
 */

#ifndef REDUNDANTOP_H_
#define REDUNDANTOP_H_
#include "ThreadPool.h"
#include "Config.h"
#include "Utils.h"

/* Class Name :- RedundantOp
 * 
 * Class Is use to perform indivisual operation for the data block
 * */

class RedundantOp
{
	//Store Config Parameter
	config _config;
	//Create DataBlock
	dataBlock<char> *_datablock;
	// Create Mutex
	std::mutex _mut;
	// Create Conditinal Variable
	std::condition_variable _condition;
	// Utils Object
	std::unique_ptr<Utils> _utils;
	// Total number of data block created
	std::atomic<std::uint64_t> _totalNum;
	// Size of the blok , input taken form config
	std::uint64_t _blockSize;
	// atomic int variable to indicate data used  
	// beetween thread
	std::atomic<int> _gnrDone;
	//Print Statement for CRC mis match

	std::uint8_t max(const std::uint8_t th1, const std::uint8_t th2);
public:
	/*
	 * 		Constructer
	 *
	 */
	explicit RedundantOp(const config &conf):_config(conf),_totalNum(0),_blockSize(0){
		_Instance = this;
		_datablock = nullptr;
	}
	~RedundantOp();
	/*init Interface will initilize the config variables
	 * to Data Block .
	 * */
	void init();

	/*De Initilize Data and Instance
	 * 
	 * */
	void dInit();

	/*start Interface will start the threads
	 * */
	void start();
	static void GenBlock();
	static void CrcBlock();
	// Static instance to acess the prvate variables
	static RedundantOp *_Instance;
};

#endif /* REDUNDANTOP_H_ */
