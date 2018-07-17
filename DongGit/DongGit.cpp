// DongGit.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "md5_wrapper.h"
#include <string>
#include <iostream>

int main(int argc, const char* argv[])
{
	if(argc != 2)
		return 0;
	std::string filename = argv[1];
	md5wrapper md5;
	std::cout << "Hash Value: \n"<< md5.getHashFromFile(filename) << std::endl;
	return 0;
}
