#include "stdafx.h"
#include "BranchCommand.h"
#include "file_operate.h"


void branch_command()
{
	// TODO:Arthur
	// TODO:利用数据库实现获取所有分支名称的指令
}

void branch_command(const string& to_branch)
{
	// 获取当前分支名
	const string from_branch = get_current_branch();

	branch_command(from_branch, to_branch);
}

void branch_command(const string& from_branch, const string& to_branch)
{
	// TODO:Arthur
	// TODO:检测分支存在性

	// 基于原分支创建新分支(注意更改分支名称和his_id)
	Branch new_branch(from_branch);
	new_branch.set_start(to_branch);

	// 更新Branch_Match信息
	DB_OP::Branch_Match_Insert(new_branch);

	// TODO:Scott
	// TODO:添加Branch到GIT_REF （暂时不知道有什么用？）
}
