#pragma once
#include <string>
#include <fstream>
/*
 * �ļ���ȡ�������ļ������������������ļ��������ofstream
 */

using std::string;
using std::ofstream;

ofstream& getOfstream(const string& filename);