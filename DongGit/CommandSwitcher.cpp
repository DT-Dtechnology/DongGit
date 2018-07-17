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
		if(argv[1] == "init")
		{
			if (argc == 2)
				init_command();
			else if (argc == 3)
				init_command(argv[2]);
			else
				throw Error("Paraments more than needed.");
		}
	}
}

