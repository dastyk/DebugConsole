
#ifndef _CONSOLE_H_
#define _CONSOLE_H_
#pragma once
#include <map>
#include <stdint.h>

namespace DebugUtils
{
#define MAX_ARGUMENTS 20

	/* Typedef of the command function pointer*/
	typedef void (*Console_Command_Function_Pointer)(int argc, char** argv);
	class Console
	{
	public:
		struct Command_Structure
		{
			Console_Command_Function_Pointer commandFunction;
			Console_Command_Function_Pointer commandHelpFunction;
		};
	private:
		/* Stores all the commands*/
		std::map<uint32_t, Command_Structure> _commands;
	public:
		Console();
		~Console();

		/* Initiates the console
		* Parameter is the default function to call if a interpreted command does not exist.
		*/
		const void Init(const Command_Structure* defaultCommandFunctions);
		/* Shutdown the console*/
		const void Shutdown();
		/* Add a new command to the console
		* First parameter is the identifier, second parameter is the function to call.
		*/
		const void AddCommand(char* identifier, const Command_Structure* command);
		/* Add a new command to the console
		* First parameter is the identifier, second parameter is the function to call.
		* Pre-hashed identifier.
		*/
		const void AddCommand(uint32_t indentifer, const Command_Structure* command);
		/* Interpret a command and dispatch the correct function.
		* Parameter is the command, with args.
		*/
		const void InterpretCommand(char* command);

	private:
		const void _ParseCommandString(char* command, int& argc, char** argv);
	};
}



#endif