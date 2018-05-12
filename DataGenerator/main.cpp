/*
 * main.cpp
 *
 *  Created on: 08-Mar-2018
 *      Author: tapesh
 */

#include<iostream>
#include "ThreadPool.h"
#include "Config.h"
#include "RedundantOp.h"

#define Debug_main 0

using namespace std;

int main(int argc, char** argv)
{
	if(argc!=5)
	{
		cout<<"help:: "<<"Command :: Number of Generator Thread"<<endl;
		cout<<"    :: "<<" Number of Crc Thread"<<endl;
		cout<<"    :: "<<" Number of data Blocks"<<endl;
		cout<<"    :: "<<" Size of data Blocks"<<endl;
	}
	else
	{
		config _conf;
		_conf._numGenThr = atoi(argv[1]);
		_conf._numCrcThr = atoi(argv[2]);
		_conf._numberBlock = atoi(argv[3]);
		_conf._dataSize = atoi(argv[4]);
		
		if(_conf._numGenThr != 0 && _conf._numCrcThr !=0 )
		{
			//Initilise Thread Pool with size as Input
			std::unique_ptr<RedundantOp> Op(new RedundantOp(_conf));
			if(Op!=nullptr)
			{
				Op->init();
				while(1)
				{
					Op->start();
					cout<<"\n\nI am waiting for 5 second to regenerate new data :  d :)"<<endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(5000));
				}
			}
		}
		else
		{
			cout<<"ERROR Input - Number of thread should not be Zero"<<endl;
		}
		
	}


	return 0;
}
