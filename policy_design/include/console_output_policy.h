#ifndef CONSOLE_OUTPUT_POLICY
#define CONSOLE_OUTPUT_POLICY

#include <iostream>

class ConsoleOutput
{
	public:
	
	template<typename MESSAGE>
	void Print(MESSAGE&& msg)
	{
		std::cout<<msg<<std::endl;
	}
};


#endif //CONSOLE_OUTPUT_POLICY
