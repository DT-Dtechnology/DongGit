#include "stdafx.h"
#include "CommandSwitcher.h"
#include "Command.h"
#include "HelpMassage.h"
#include "Error.h"

void CommandSwitcher(int argc, const char* argv[])
{
	if (argc == 1)
		help_message();
	else
	{
		const string instruct(argv[1]);
		if (instruct == "init")
		{
			if (argc == 2)
				init_command();
			else if (argc == 3)
				init_command(argv[2]);
			else
				throw Error("Paraments more than needed.");
		}
		else if (instruct == "add")
		{

		}
		else if (instruct == "commit")
		{

		}
		else if (instruct == "commit-a")
		{

		}
		else if (instruct == "branch")
		{

		}
		else if (instruct == "checkout")
		{

		}
		else if (instruct == "drop")
		{

		}
		else if (instruct == "reset")
		{

		}
		else if (instruct == "fetch")
		{

		}
		else if (instruct == "merge")
		{

		}
		else if (instruct == "diff")
		{

		}
		else if (instruct == "push")
		{

		}
		else if (instruct == "pull")
		{

		}
		else
			throw Error("No such an instruction.");
	}
}

