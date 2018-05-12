/*
 * Config.h
 *
 *  Created on: 08-May-2018
 *      Author: tapesh
 */

#ifndef DEBUG_CONFIG_H_
#define DEBUG_CONFIG_H_
#include "ThreadPool.h"
#include <cstdint>
#include <algorithm>
#define Debug 0

/**Set Configuration from command Promt .
 * */
struct config
{
	std::uint8_t _numGenThr;
	std::uint8_t _numCrcThr;
	std::uint64_t _dataSize;
	std::uint8_t _numberBlock;
	config():_numGenThr(0),_numCrcThr(0),_dataSize(0),_numberBlock(0){}
	config(const config &ob)
	{
		_numGenThr = ob._numGenThr;
		_numCrcThr = ob._numCrcThr;
		_dataSize = ob._dataSize;
		_numberBlock = ob._numberBlock;
	}
};


/** Data Block Structure
 */
template<typename T>
struct dataBlock
{
	std::atomic<bool> _crcFilled;
	std::atomic<bool> _dataFilled;
	std::uint64_t _size;
	std::vector<T> _data;
	std::uint32_t _crc;
	dataBlock():_crcFilled(false),_dataFilled(false),_size(0){}
	
	void operator = (const std::uint32_t &crc)
	{
		std::cout<<"\n\nCRC value changed :: Old CRC :- "<<_crc;
		std::cout<<"  New CRC Calculated as :- "<<crc;
		_crc = crc;
		std::cout<<"  For Below Data "<<endl;
		for_each(_data.begin(),_data.end(),[&](const char &ch){std::cout<<ch;});
		std::cout<<endl;
	}
};

#endif /* DEBUG_CONFIG_H_ */
