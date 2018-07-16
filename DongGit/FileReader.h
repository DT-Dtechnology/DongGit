#pragma once
#include <string>
#include <fstream>
/*
 * 文件读取，利用文件名进行搜索，返回文件的输出流ofstream
 */

using std::string;
using std::ofstream;

ofstream& getOfstream(const string& filename);