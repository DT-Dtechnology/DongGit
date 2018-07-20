#include "stdafx.h"
#include "BasicCommandFunction.h"
#include "Branch.h"
#include "file_operate.h"

bool uncommited_change()
{
	const Branch past(get_current_branch());
	const Branch current;
	
	return current == past;
}

void refresh_file(const string& branch_name)
{
	Branch branch(branch_name);
	
	// TODO:清除工作区中所有文件

	// 向工作区中重写新文件
	ofstream out;
	ifstream in;
	for (auto it = branch.getNodeVector().begin(); it != branch.getNodeVector().end(); ++it)
	{
		out.open(GIT_HEAD + it->getName());
		in.open(GIT_OBJECT_HEAD + it->getHash());

		// 直接获取in全部文件内容并写入到out中
		out << in.rdbuf();

		in.close();
		out.close();
	}
}
