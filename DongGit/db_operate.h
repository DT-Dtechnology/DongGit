#pragma once
#include <string>

using std::string;

// FILE_MATCH 和 BRANCH_MATCH的结构如下
// FILR_MATCH: Hash和对应的文件名Name
// BRANCH_MATCH: Hash和对应的最新分支名Branch
// 暂时没有考虑远程数据库的问题

void File_Match_Insert(const string& name, const string& hash);

void File_Match_Update(const string& name, const string& hash, const string& pre_hash);

void Branch_Match_Insert(const string& name, const string& hash);

void Branch_Match_Update(const string& name, const string& hash, const string& pre_hash, int his_id);

string Branch_Search_Name(const string& hash);

string Branch_Search_Hash(const string& name);

string File_Search_Name(const string& hash);

string File_Search_Hash(const string& name);

string File_Match_Pre(const string& hash);