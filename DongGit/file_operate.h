#pragma once
#include <string>

using std::string;

// 获取当前的分支名称
string get_current_branch();

// 判断文件冲突
void file_conflict(const string& branch1, const string& branch2);

string get_branch_file_hash(const string& branch, const string& file);