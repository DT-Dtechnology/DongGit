#include "stdafx.h"
#include "Branch.h"

#define TEMP_FILE "temp_file"

void Branch::write()
{
	// ��д���ļ���������
	ofstream out;
	get_hash();

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
	out.open(TEMP_FILE);
	for (auto it = node_vector_.begin(); it != node_vector_.end(); ++it)
		out << (*it).hash_value_ << ' ' << (*it).hash_value_ << "\n";
	out.close();

	md5wrapper md5;
	hash_value_ = md5.getHashFromFile(TEMP_FILE);
}

Branch::Branch(const string& hash_value):hash_value_(hash_value)
{
	// TODO:ͨ�����ݿ��ȡHashֵ��Ӧ���������<��֧>����


	// ��ȡNodeVector
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
	// �������ݿ�������
	get_hash();

	// TODO:�������ݿ��ָ����Ϣ
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



