#pragma once
#include <string>

using std::string;

// FILE_MATCH �� BRANCH_MATCH�Ľṹ����
// FILR_MATCH: Hash�Ͷ�Ӧ���ļ���Name
// BRANCH_MATCH: Hash�Ͷ�Ӧ�����·�֧��Branch
// ��ʱû�п���Զ�����ݿ������

void File_Match_Insert(const string& name, const string& hash);

void File_Match_Update(const string& name, const string& hash, const string& pre_hash);

void Branch_Match_Insert(const string& name, const string& hash);

void Branch_Match_Update(const string& name, const string& hash, const string& pre_hash, int his_id);

string Branch_Search_Name(const string& hash);

string Branch_Search_Hash(const string& name);

string File_Search_Name(const string& hash);

string File_Search_Hash(const string& name);

string File_Match_Pre(const string& hash);