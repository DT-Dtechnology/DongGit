#pragma once
#include <string>

using std::string;

// FILE_MATCH �� BRANCH_MATCH�Ľṹ����
// FILR_MATCH: Hash�Ͷ�Ӧ���ļ���Name
// BRANCH_MATCH: Hash�Ͷ�Ӧ�����·�֧��Branch
// ��ʱû�п���Զ�����ݿ������


class DB_OP //���ݿ������
{
public:
	//test func
	static void Print_All_Branch();

	//---------------------------------------------------
	static void File_Match_Insert(const FileNode& file);
	static void Branch_Match_Insert(const Branch& branch);

	static string get_File_Hash(const string& name);
	static string get_File_Pre_Hash(const string& hash);

	//---------------------------------------------------

	static void File_Match_Insert(const string& name, const string& hash);

	static void File_Match_Update(const string& name, const string& hash, const string& pre_hash);
	
	
	static void Branch_Match_Insert(const string& name, const string& hash);

	static void Branch_Match_Update(const string& name, const string& hash, const string& pre_hash, int his_id);

	static void Branch_Match_Adddisc(const string& disc, const string& hash);

	
	static string Branch_Search_Name(const string& hash);
	
	static string Branch_Search_Hash(const string& name);

	static string File_Search_Name(const string& hash);
	
	static string File_Search_Hash(const string& name);

};