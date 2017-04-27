//#include <iostream>
//#include "ConsoleThread.h"
//
//int main()
//{
//	DebugUtils::DebugConsole::Command_Structure def = 
//	{ 
//		nullptr,
//		[](void* userData, int argc, char** argv) {std::cout << "Command not found: " << argv[0] << std::endl; },
//		"",
//		""
//	};
//
//	DebugUtils::ConsoleThread::Init(&def);
//	DebugUtils::ConsoleThread::ShowConsole();
//	
//
//	while (true);
//
//
//	DebugUtils::ConsoleThread::Shutdown();
//	return 0;
//}