// DongGit.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

int main(int argc, const char* argv[])
{
	try {
		CommandSwitcher(argc, argv);
	} catch(Error e)
	{
		e.print_msg();
	}
	return 0;
}
