#pragma once
#include <string>
#include <fstream>
/*
 * 文件的写入，利用文件名进行搜索（或者先删除后新建）或直接创建
 * 之后返回文件的输入流ifstream
 */

using std::string;
using std::ifstream;

ifstream& setIfstream(const string& filename);