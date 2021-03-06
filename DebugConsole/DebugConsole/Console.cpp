#include "Console.h"

namespace DebugUtils
{

	DebugConsole::DebugConsole()
	{
	}


	DebugConsole::~DebugConsole()
	{
	}

	/*Copies the default Command Functions to the 0 slot in the commands map*/
	const void DebugConsole::Init()
	{
		Command_Structure commandsCmd = 
		{
			this,
			[](void* userData, int argc, char** argv) {
			for (auto& c : static_cast<DebugConsole*>(userData)->_commands)
			{
				printf("%s \t-\t %s\n", c.second.name, c.second.description);
			}
		},
			"commands",
			"Lists all available commands"
		};

		_commands[0] = commandsCmd;


		return void();
	}
	const void DebugConsole::Shutdown()
	{
		return void();
	}
	/*Hash the identifier and add the command*/
	const void DebugConsole::AddCommand(const Command_Structure * command)
	{

		uint32_t hash = std::hash<std::string>{}(command->name);

#ifdef _DEBUG
		if (command->commandFunction == nullptr)
			throw std::exception("Invalid command function pointer.");

#endif
		
			
		_commands[hash] = *command;

		return void();
	}
	/* Adds the command with the already hashed identifer*/
	const void DebugConsole::AddCommand(uint32_t identifier, const Command_Structure * command)
	{
#ifdef _DEBUG
		if (command->commandFunction == nullptr)
			throw std::exception("Invalid command function pointer.");

#endif


		_commands[identifier] = *command;


		return void();
	}

	/*Splits the command and calls the correct command function */
	const void DebugConsole::InterpretCommand(char * command)
	{

		int argc = 0;
		char* argv[MAX_ARGUMENTS];
		_ParseCommandString(command, argc, argv);


		if (argc > 0)
		{
			uint32_t hash = std::hash<std::string>{}(argv[0]);

			auto find = _commands.find(hash);
			if (find != _commands.end()) {

				find->second.commandFunction(find->second.userData, argc, argv);
			}
			else
			{
				_commands[0].commandFunction(_commands[0].userData, argc, argv);
			}
		}

		return void();
	}
	/* Split the command string into the arg array*/
	const void DebugConsole::_ParseCommandString(char* command, int& argc, char** argv)
	{

		argc = 0;
		int j = 0;
		int i = 0;
		char c = command[i];
		while (c != '\0')
		{
			while (!(c == ' ' || c == '\0'))
			{
				i++;
				c = command[i];
			}
			argv[argc] = &command[j];
			argc++;
			if (command[i] != '\0')
			{
				command[i] = '\0';
				i++;
				j = i;
				c = command[i];
				if (argc >= MAX_ARGUMENTS)
				{
					break;
				}
				
			}
			
			
		}

	}

	bool GetArg(char* arg, char** data, int argc, char** argv)
	{
		bool found = false;

		for (int i = 0; i < argc; i++)
		{
			if (std::string(arg) == std::string(argv[i]))
			{	
				found = true;
				if (data)
				{
					if (i + 1 < argc)
					{
						*data = argv[i + 1];
					}
					else
					{
						found = false;
					}
					
				}
					
				
				break;
			}
		}
		return found;
	}

}