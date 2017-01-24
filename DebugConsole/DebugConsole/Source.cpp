#include <iostream>
#include "Console.h"

int main()
{
	DebugUtils::Console console;
	DebugUtils::Console::Command_Structure def = 
	{ 
		[](int argc, char** argv) {std::cout << "Command not found: " << argv[0] << std::endl; },
		[](int argc, char** argv) {}
	};

	console.Init(&def);

	DebugUtils::Console::Command_Structure def2 =
	{
		[](int argc, char** argv)
	{
		for (int i = 0; i < argc; i++)
		{
			std::cout << argv[i] << " ";
		}

	},
		[](int argc, char** argv) {
	std::cout << "Help" << std::endl; }
	};
	console.AddCommand("Func", &def2);

	char buff[256] = { "Test -h" };

	console.InterpretCommand(buff);

	getchar();
	return 0;
}