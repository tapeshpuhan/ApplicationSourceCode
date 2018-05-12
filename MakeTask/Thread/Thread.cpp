/*
 * Thread.cpp
 *
 *  Created on: 18-Feb-2018
 *      Author: tapesh
 */
#include"Thread.h"


/*

void CreateThread::CreateThredByAsync(auto var)
{
	//_fut = async(var);
}
void CreateThread::CreateThredByID(auto var)
{
	thread  t(CreateThread::fun);

}
int CreateThread::fun()
{
	return 0;
}
int main()
{
	return 0;
}*/

void thread_function()
{
    std::cout << "thread function\n";
}

int main()
{
    std::thread t(&thread_function);   // t starts running
    std::cout << "main thread\n";
    t.join();   // main thread waits for the thread t to finish
    return 0;
}
