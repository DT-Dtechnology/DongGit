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
	
	// 查找文件名对应Hash，确定前继节点
	string hash = DB_OP::get_File_Hash(file_name);
	
	// 判断Hash值是否相同，相同直接返回，无需更改
	FileNode file(file_name);
	if(file.getHash() == hash)
		return;
	file.setPreNode(hash);
	
	// 写入操作，同时更改数据库内容，注意添加前继节点
	DB_OP::File_Match_Insert(file);

}

void commit_add_command()
{
	// 将所有文件add

	// TODO:Scott
	// TODO:获取工作区下所有文件文件名
	// TODO:按照文件名执行commit_add_command(file_name)
}

