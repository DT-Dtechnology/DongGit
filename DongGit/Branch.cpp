#include "stdafx.h"
#include "Branch.h"
#include "db_operate.h"

#define BRANCH_TEMP "Branch_Temp"

void Branch::write()
{
	// ��д���ļ���������
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
	// TODO:ͨ�����ݿ��ȡHashֵ��Ӧ���������<��֧>Hash��pre��his_id

	// ��ȡNodeVector
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

	// TODO:�������ݿ�
}

void Branch::addFile(const FileNode& file)
{
	node_vector_.push_back(file);
}

void Branch::insert()
{
	// ������Ϣ���ݿ�
	get_hash();

	// TODO:�����ݿ��������Ϣ
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



