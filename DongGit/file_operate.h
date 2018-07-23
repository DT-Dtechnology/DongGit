#pragma once
#include <string>
#include <vector>
#include <windows.h>

using std::string;
using std::vector;

// 获取当前的分支名称
string get_current_branch();

// 判断文件冲突
void file_conflict(const string& branch1, const string& branch2);

string get_branch_file_hash(const string& branch, const string& file);

string get_Branch_Latest_Hash(const string& name);

// 获取工作区下所有文件名
void get_file_name(string path, vector<string> file);