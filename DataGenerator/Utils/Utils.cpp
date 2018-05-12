/*
 * Utils.cpp
 *
 *  Created on: 09-May-2018
 *      Author: tapesh
 */

#include "Utils.h"
#include<iostream>
#include<algorithm>

const char string_value[] =
		"0123456789"
		"!@#$%^&*"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(string_value) - 1;

/**Generate Random character
 * */
char genRandom()
{
	auto value = rand();
	//std::cout<<"genRandom "<<value % stringLength<<" ";
	return string_value[value % stringLength];
}
/* Function Name genRandChar
 * Input : character data Block ,
 *         pSize = size of the block
 * Output: none
 * Return : bool , true for success
 * 			This function should fill 
 * 			Random data into data block
 * */
bool Utils::genRandChar(std::vector<char> &data, const std::uint64_t pSize)
{
	//det size of the block
	data.resize(pSize);

	// Use current time as seed for random generator

	//std::cout<<pSize<<std::endl;
	for(std::uint64_t index=0;index < pSize; ++index)
	{
		data[index] = genRandom();
	}
	return true;
}

/* Function Name genCRC32
 * Input : character data Block ,
 *         
 * Output: CRC value for the character string
 * Return : bool , true for success
 * 			This function should fill 
 * 			Random data into data block
 * Note this function use Third party Implement to
 * calculate CRC . 
 * */
bool Utils::genCRC32(const std::vector<char> &data, std::uint32_t &crc)
{
	std::uint64_t size = data.size();
	auto table = CRC::CRC_32().MakeTable();
	std::uint64_t i = 0;
	std::string sdata;
	sdata.resize(size);

	std::copy( data.begin(), data.end(), sdata.begin());
	crc = CRC::Calculate(sdata.c_str(), size, table, crc);
}

