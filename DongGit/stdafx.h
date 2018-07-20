// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <string>
#include <io.h>
#include <fstream>
#include <iostream>

using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;

#define GIT_OBJECT_HEAD ".git\\object\\"

// TODO: 在此处引用程序需要的其他头文件
#include "CommandSwitcher.h"
#include "DefineSetting.h"
#include "Error.h"
#include "md5_wrapper.h"
#include "Branch.h"
#include "FileNode.h"
#include "db_operate.h"




