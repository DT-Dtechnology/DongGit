#pragma once
#include <string>

using std::string;

// ��ȡ��ǰ�ķ�֧����
string get_current_branch();

// �ж��ļ���ͻ
void file_conflict(const string& branch1, const string& branch2);