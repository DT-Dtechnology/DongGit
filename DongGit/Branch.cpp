#include "stdafx.h"
#include "Branch.h"

#define BRANCH_TEMP "Branch_Temp"

void Branch::write()
{
	// 仅写入文件，不更新
	init_hash();

	ofstream out;

	if (_access((GIT_OBJECT_HEAD + hash_value_).c_str(), 0) != -1)
		return;

	out.open(GIT_OBJECT_HEAD + hash_value_);
	for (auto it = node_vector_.begin(); it != node_vector_.end(); ++it)
		out << (*it).hash_value_ << ' ' << (*it).hash_value_ << "\n";
	out.close();
}

void Branch::get_hash()
{
	md5wrapper md5;
	hash_value_ = md5.getHashFromFile(GIT_OBJECT_HEAD + hash_value_);
}

void Branch::init_hash()
{
	ofstream out;
	out.open(BRANCH_TEMP);
	for (auto it = node_vector_.begin(); it != node_vector_.end(); ++it)
		out << (*it).hash_value_ << ' ' << (*it).hash_value_ << "\n";
	out.close();

	md5wrapper md5;
	hash_value_ = md5.getHashFromFile(BRANCH_TEMP);

	remove(BRANCH_TEMP);
}

Branch::Branch(const string& hash_value):hash_value_(hash_value)
{
	// TODO:通过数据库获取Hash值对应的数据项，即<分支>名称


	// 获取NodeVector
	string file_name;
	string file_hash;

	ifstream in;
	in.open(GIT_OBJECT_HEAD + hash_value);
	while(in)
	{
		in >> file_name >> file_hash;
		const FileNode file(file_name, file_hash);
		node_vector_.push_back(file);
	}
}

void Branch::update()
{
	// 更新数据库中内容
	get_hash();

	// TODO:更新数据库的指向信息
}

void Branch::addFile(const FileNode& file)
{
	node_vector_.push_back(file);
}

void Branch::insert()
{
	// 记入信息数据库
	get_hash();

	// TODO:向数据库中添加信息
}



