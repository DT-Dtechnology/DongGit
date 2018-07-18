#include "stdafx.h"
#include "Branch.h"
#include "db_operate.h"

#define BRANCH_TEMP "Branch_Temp"

void Branch::write()
{
	// 仅写入文件，不更新
	get_hash();

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
	ofstream out;
	out.open(BRANCH_TEMP);
	for (auto it = node_vector_.begin(); it != node_vector_.end(); ++it)
		out << (*it).hash_value_ << ' ' << (*it).hash_value_ << "\n";
	out.close();

	md5wrapper md5;
	hash_value_ = md5.getHashFromFile(BRANCH_TEMP);

	remove(BRANCH_TEMP);
}

Branch::Branch(const string& name):branch_name_(name)
{
	// TODO:通过数据库获取Hash值对应的数据项，即<分支>Hash和pre和his_id

	// 获取NodeVector
	string file_name;
	string file_hash;

	ifstream in;
	in.open(GIT_OBJECT_HEAD + name);
	while(in)
	{
		in >> file_name >> file_hash;
		const FileNode file(file_name, file_hash);
		node_vector_.push_back(file);
	}
}


void Branch::update()
{
	get_hash();

	// TODO:更新数据库
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

inline NodeVector& Branch::getNodeVector()
{
	return node_vector_;
}

void Branch::reset_branch(const string& name)
{
	branch_name_ = name;
	pre_branch_ = NONE_FILE_HASH;
	his_id_ = 0;
}



