#include "stdafx.h"
#include "CommitAddCommand.h"
#include "file_operate.h"

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
	const string hash = get_branch_file_hash(get_current_branch(), file_name);
	cout << "Old Hash:" << hash << endl;
	// 判断Hash值是否相同，相同直接返回，无需更改
	FileNode file(file_name);
	
	cout << "New Hash:" << file.getHash() << endl;
	if(file.getHash() == hash)
		return;
	file.setPreNode(hash);
	file.write();
	
	// 写入操作，同时更改数据库内容，注意添加前继节点
	DB_OP::File_Match_Insert(file);

}

void commit_add_command()
{
	// 将所有文件add

	// TODO:Scott
	// 获取工作区下所有文件文件名
	vector<string> file_name;
	char *buf = new char[1000];
	int i = 1000;
	GetCurrentDirectoryA(1000, buf);
	string path = buf;
	get_file_name(path, file_name);
	for (auto i = file_name.begin(); i != file_name.end(); ++i)
		(*i) = (*i).substr(path.length());
	delete[] buf;
	// 按照文件名执行commit_add_command(file_name)
	for (auto i = file_name.begin(); i != file_name.end(); ++i)
		commit_add_command((*i));
}

void commit_add_command_test()
{
	// commit_add_command();
	vector<string> file_name;
	char *buf = new char[1000];
	int i = 1000;
	GetCurrentDirectoryA(1000, buf);
	string path = buf;
	get_file_name(path, file_name);
	for (auto i = file_name.begin(); i != file_name.end(); ++i)
		(*i) = (*i).substr(path.length());
	for (auto i = file_name.begin(); i != file_name.end(); ++i)
		cout << (*i) << endl;
}

void branch_refresh(int argc, const char* argv[] )
{
	// 新建分支
	Branch branch(get_current_branch());

	// 添加文件
	for(auto it = 2 ; it < argc ; ++it)
	{
		FileNode file(argv[it]);
		branch.update_file(file.getName(), file.getHash());
	}
	branch.get_hash();
	if(branch.getHash() == branch.getPre())
		return;

	branch.write();
	DB_OP::Branch_Match_Insert(branch);
}

