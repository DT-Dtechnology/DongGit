#include "stdafx.h"
#include "BranchCommand.h"

void branch_command()
{
	// TODO:利用数据库实现获取所有分支名称的指令
}

void branch_command(const string& to_branch)
{
	// 获取当前分支名
	string from_branch;
	ifstream in;
	in.open(CURRENT_BRANCH);
	in >> from_branch;
	in.close();

	branch_command(from_branch, to_branch);
}

void branch_command(const string& from_branch, const string& to_branch)
{
	// TODO:检测分支存在性

	// TODO:基于原分支创建新分支（注意更改分支名称和his_id）

	// TODO:更新Branch_Match信息

}
