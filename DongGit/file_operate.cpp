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
