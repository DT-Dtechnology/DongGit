// DongGit.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
#include <iostream>

int main(int argc, const char* argv[])
{
	if (argc <= 1)
		return 0;

	md5wrapper md5;

	std::string str;
	std::string str_md5;

	str = argv[1];
	str_md5 = md5.getHashFromString(str);

	std::cout << "MD5 Hash: " << str_md5;

	return 0;
}
