#include "stdafx.h"
#include "BasicCommandFunction.h"
#include "Branch.h"
#include <sstream>

bool uncommited_change()
{
	Branch current;
	Branch past;

	// TODO:利用past的NodeVector建立Map，然后利用该Map判断current是否有更新

	// TODO:更新检测先判断长度，之后逐项判断；如果有更新，则返回false

	return true;
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
