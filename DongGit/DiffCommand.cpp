#include "stdafx.h"
#include "DiffCommand.h"

void diff_command(const string& branch)
{
	const string branch2 = get_current_branch();
	diff_command(branch, branch2);
}

void diff_command(const string& branch1, const string& branch2)
{
	cout << "The difference between this two Branch:" << endl;

	// TODO:Scott
	// TODO:判断文件之间的不同，利用Hash值判断即可，不需要找到不同的部分
}

