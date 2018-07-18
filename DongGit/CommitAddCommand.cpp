#include "stdafx.h"
#include "CommitAddCommand.h"

void commit_add_command(const string& file_name)
{
	if(file_name == "*")
	{
		commit_add_command();
		return;
	}
	ofstream out;
	ifstream in;
	
	// TODO:查找文件名对应Hash，确定前继节点

	// 
}

void commit_add_command()
{
	// 将所有文件add
	// TODO:获取工作区下所有文件文件名

	// TODO:按照文件名执行commit_add_command(file_name)
}

