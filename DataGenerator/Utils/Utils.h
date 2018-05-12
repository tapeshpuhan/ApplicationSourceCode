/*
 * Utils.h
 *
 *  Created on: 09-May-2018
 *      Author: tapesh
 */

#ifndef UTILS_H_
#define UTILS_H_
#include <cstdint>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "CRC.h"
#include <iostream>
class Utils
{
public:

	bool genRandChar(std::vector<char> &data, const std::uint64_t pSize);
	bool genCRC32(const std::vector<char> &data, std::uint32_t &crc);
};



#endif /* UTILS_H_ */
