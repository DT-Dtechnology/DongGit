#pragma once
#include <string>
#include <fstream>
/*
 * �ļ���д�룬�����ļ�������������������ɾ�����½�����ֱ�Ӵ���
 * ֮�󷵻��ļ���������ifstream
 */

using std::string;
using std::ifstream;

ifstream& setIfstream(const string& filename);