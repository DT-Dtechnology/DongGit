#pragma once
#include <string>
#include <vector>
#include <windows.h>

using std::string;
using std::vector;

// ��ȡ��ǰ�ķ�֧����
string get_current_branch();

// �ж��ļ���ͻ
void file_conflict(const string& branch1, const string& branch2);

string get_branch_file_hash(const string& branch, const string& file);

string get_Branch_Latest_Hash(const string& name);

// ��ȡ�������������ļ���
void get_file_name(string path, vector<string> file);