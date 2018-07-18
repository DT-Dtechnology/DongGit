#include "stdafx.h"
#include "sqlite3.h"
#include "db_operate.h"

void File_Match_Insert(const string& name, const string& hash)
{
	// TODO:向FILE_MATCH表中插入数据

}

void File_Match_Update(const string& name, const string& hash, const string& pre_hash)
{
	// TODO:向FILE_BRANCH表中更新数据
}

void Branch_Match_Insert(const string& name, const string& hash)
{
	// TODO:向BRANCH_MATCH表中插入数据
}

void Branch_Match_Update(const string& name, const string& hash, const string& pre_hash, int his_id)
{
	// TODO:向BRANCH_MATCH表中更新数据
}

string Branch_Search_Name(const string& hash)
{
}

string Branch_Search_Hash(const string& name)
{
}

string File_Search_Name(const string& hash)
{
}

string File_Search_Hash(const string& name)
{
}
