/*
 * RedundantOp.cpp
 *
 *  Created on: 09-May-2018
 *      Author: tapesh
 */
#include "RedundantOp.h"
#define DOperation 0

RedundantOp *RedundantOp::_Instance=nullptr;

/*
 * 		Destrocter
 * */
RedundantOp::~RedundantOp()
{
	if(nullptr != _datablock)
	{
		delete []_datablock;
		_datablock = nullptr;
	}
}
/* Function Name GenBlock
 * Input : Void
 * Output: Void
 * Return : Void
 * This is a thread Handler to generate Random character
 * for the input block.
 * It also mark the corresponding block is filled with
 * Random Number
 * */
void RedundantOp::GenBlock()
{
	std::unique_lock<mutex> lk(_Instance->_mut);

#if DOperation
	cout<<"GenBlock "<<std::this_thread::get_id()<<endl;
#endif
	/* Null check for Static instance*/
	if(_Instance == nullptr)
	{
		lk.unlock();
		return;
	}
	/* Store Total Block and number of gem thread*/
	auto totalBlok = _Instance->_config._numberBlock;
	auto genThread = _Instance->_config._numGenThr;

	/*We can able to process num =totalBlok/genThread,
	 * num number of process in each thread 
	 * 
	 * */
	auto num = totalBlok/genThread;	
	auto index = _Instance->_totalNum.load();
	auto remain = totalBlok%genThread;

	if(!num)
	{
		num = 1;
	}
	if(_Instance->_datablock!=nullptr)
	{
		for(;(index < (num+_Instance->_totalNum.load())) && (index < totalBlok); index++)
		{
			/*Fill the Random Data into arrray of block
			 * */
			_Instance->_utils->genRandChar(_Instance->_datablock[index]._data,_Instance->_blockSize);

			/*Mark for the index is read for generate random data*/
			_Instance->_datablock[index]._dataFilled = true;
		}
		/*Update the total num with new index value*/
		_Instance->_totalNum.store(index);


		if(remain != 0 && (_Instance->_totalNum.load() == (totalBlok-remain)))
		{
			for(;index < totalBlok;index++)
			{
				/*Fill the Random Data into arrray of block
				 * */
				_Instance->_utils->genRandChar(_Instance->_datablock[index]._data,_Instance->_blockSize);

				/*Mark for the index is read for generate random data*/
				_Instance->_datablock[index]._dataFilled = true;
			}
			/*Update the total num with new index value*/
			_Instance->_totalNum.store(index);
		}


		/*Below Part Is only for Debugging
		 * */
#if DOperation
		cout<<"Gen Value::"<<endl;
		for(auto i = 0; i<totalBlok ; i++)
		{
			for(auto &at:_Instance->_datablock[i]._data)
			{
				cout<<at<<" ";
			}
			cout<<endl;
		}
#endif
	}
	/*Make Conditional value to read true 
	 * Thread B will get chance to read info and 
	 * set CRC field
	 * */
	_Instance->_gnrDone.store(true);
	/* Unlock the mutex and set conditional variable to operate*/
	lk.unlock();
	_Instance->_condition.notify_all();

#if DOperation
	cout<<"GenBlock End"<<std::this_thread::get_id()<<endl;
#endif
}

/* Function Name CrcBlock
 * Input : Void
 * Output: Void
 * Return : Void
 * This is a thread Handler to generate CRC for each block and fill 
 * Array of CRC value with its corresponding thread Id
 * It also mark the corresponding block is filled with
 * CRC value
 * */
void RedundantOp::CrcBlock()
{
	std::unique_lock<mutex> lk(_Instance->_mut);
#if DOperation
	cout<<"Crc Thread ID :: "<<std::this_thread::get_id()<<endl;
	cout<<"Crc Thread Load :: "<<_Instance->_gnrDone.load()<<endl;
	cout<<"Crc Thread Total Number :: "<<_Instance->_totalNum.load()<<endl;
#endif
	/* This thread will wait until thread A is filled with Data*/
	_Instance->_condition.wait(lk,[&]{return (_Instance->_gnrDone.load() || 
			((_Instance->_totalNum.load()) >= (_Instance->_config._numberBlock)));});


	auto dataRead = _Instance->_totalNum.load();
	for(auto index = 0; index < dataRead; index++)
	{
		if(_Instance->_datablock[index]._dataFilled == true)
		{
			std::uint32_t crc;
			/*Use Until Function to get CRC for the requaired Block*/
			_Instance->_utils->genCRC32(_Instance->_datablock[index]._data,crc);

			if(_Instance->_datablock[index]._crcFilled == true)
			{
				if(_Instance->_datablock[index]._crc != crc)
				{
					_Instance->_datablock[index] = crc;
				}
			}
			else
			{
				/*CRC flag is set */
				_Instance->_datablock[index]._crcFilled = true;
				_Instance->_datablock[index]._crc = crc;
			}

#if DOperation
			cout<<"CRC Value "<<crc<<endl;
#endif

			_Instance->_datablock[index]._crc = crc;
		}
	}
	/*Make Conditional value to read false 
	 * Thread A will generate Rest Of the Data block with
	 * Random character.
	 * */
	_Instance->_gnrDone.store(false);
#if DOperation
	cout<<"Crc Thread ID :: End "<<endl;
#endif
}
/* Function Name init
 * Input : Void
 * Output: Void
 * Return : Void
 * This is Initialization function to initialize
 * thread pool and trigger n number thread as per
 * user request
 * */
void RedundantOp::init()
{
	_datablock = new dataBlock<char>[_config._numberBlock];
	_utils = std::unique_ptr<Utils>();
	_blockSize = _config._dataSize;
}

// Start worket threads 
void RedundantOp::start()
{
	_totalNum.store(0); // initilize size of data to read or write
	_gnrDone.store(0); // updatet the flag to initiate thread Syncronization

	//Create Thred pool as per user provided configuration
	std::shared_ptr<ThreadPool> genPool = std::make_shared<ThreadPool>(_config._numGenThr);
	std::shared_ptr<ThreadPool> crcPool = std::make_shared<ThreadPool>(_config._numCrcThr);

	if(nullptr!=genPool)
	{
		for(int index = 0; index < max(_config._numGenThr,_config._numCrcThr);++index)
		{
			if(index < _config._numGenThr)
			{
				genPool->submit(RedundantOp::GenBlock);
			}
			if(index < _config._numCrcThr)
			{
				crcPool->submit(RedundantOp::CrcBlock);
			}
		}
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
// D initilize allocated memory
void RedundantOp::dInit()
{
	if(nullptr != _datablock)
	{
		delete []_datablock;
		_datablock = nullptr;
	}
	if(nullptr!=_utils)
	{
		_utils.reset();
	}
}

std::uint8_t RedundantOp::max(const std::uint8_t th1, const std::uint8_t th2)
{
	if(th1 > th2)
	{
		return th1;
	}
	return th2;
}
