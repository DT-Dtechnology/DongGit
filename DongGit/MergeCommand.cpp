#include "stdafx.h"
#include "MergeCommand.h"
#include "BasicCommandFunction.h"


void merge_command(const string& from_branch)
{
	const string to_branch = get_current_branch();

	merge_command(from_branch, to_branch);
}

void merge_command(const string& from_branch, const string& to_branch)
{
	// 判断未提交更改
	if (uncommited_change())
		throw Error("Unsummited change");

	Branch branch_from(from_branch);
	Branch branch_to(to_branch);

	// 判断是否版本更新
	if (!(from_branch > to_branch))
	{
		// 若非更新，则输出冲突
		file_conflict(from_branch, to_branch);
		return;
	}

	// 更新to_branch
	for(auto it:branch_from.getNodeVector())
	{
		branch_to.update_file(it.getName(), it.getHash());
	}
	
	// 文件写入
	branch_to.write();

	// 更新到数据库中
	DB_OP::Branch_Match_Insert(branch_to);

	// TODO:Scott
	// TODO:工作区更新，这个直接写成一个函数在file_operate中，用到次数还是很多的
}
