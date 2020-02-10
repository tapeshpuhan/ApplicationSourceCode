#include "hallow_world_interface.h"
#include "console_output_policy.h"
#include "german_language.h"
#include "english_language.h"

int main()
{
	using HallowWorldEnglishInConsole = HallowWorld<ConsoleOutput,EnglishLanguage>;
	using HallowWorldGermanInConsole = HallowWorld<ConsoleOutput,GermanLanguage>;
	
	HallowWorldEnglishInConsole obj;
	HallowWorldGermanInConsole Obj2;
	obj.Run(); 
	Obj2.Run();
	return 0;
}
