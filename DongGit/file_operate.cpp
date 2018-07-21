#include "stdafx.h"
#include "file_operate.h"

string get_current_branch()
{
	ifstream in;
	in.open(CURRENT_BRANCH);
	string name;
	in >> name;
	in.close();
	return name;
}

void file_conflict(const string& branch1, const string& branch2)
{
}

string get_branch_file_hash(const string& branch, const string& file)
{
	const string branch_hash = DB_OP::get_Branch_Hash(branch);

	Branch branch_data(branch_hash);

	return branch_data.get_file_hash(file);
}

