#include "stdafx.h"
#include "CheckoutCommand.h"
#include "BasicCommandFunction.h"
#include <io.h>

void checkout_command(const string& branch_name)
{
	string path_name = GIT_REF + branch_name;
	if (_access(path_name.c_str(), 0) != -1)
	{
		// 判断是否存在未提交更改
		if (uncommited_change())
			throw Error("Unsummited change");


		string old_branch;
		ifstream in;
		in.open(CURRENT_BRANCH);
		in >> old_branch;
		in.close();

		remove(CURRENT_BRANCH);
		
		ofstream out;
		out.open(CURRENT_BRANCH);
		out << branch_name << endl;
		out.close();

		// 切换工作区文件
		refresh_file(branch_name);
	}
	else
		throw Error("You don not have this branch");
}
