#include "stdafx.h"
#include "Branch.h"
#include "db_operate.h"
#include <algorithm>
#include "file_operate.h"

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
		out << (*it).file_name_ << ' ' << (*it).hash_value_ << "\n";
	out.close();

	// 更新ref中信息
	out.open(GIT_REF + branch_name_);
	out << hash_value_;
	out.close();
}

void Branch::get_hash()
{
	sort_file();

	ofstream out;
	out.open(BRANCH_TEMP);
	for (auto it = node_vector_.begin(); it != node_vector_.end(); ++it)
		out << (*it).file_name_ << ' ' << (*it).hash_value_ << "\n";
	out.close();

	md5wrapper md5;
	hash_value_ = md5.getHashFromFile(BRANCH_TEMP);

	remove(BRANCH_TEMP);
}

void Branch::sort_file()
{
	// 按文件名进行排序
	std::sort(node_vector_.begin(), node_vector_.end(), file_name_compare);
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

	get_hash();
}

Branch::Branch()
{
	// 从当前工作区中获取一个Branch
	branch_name_ = get_current_branch();

	// TODO:通过读取文件建立Branch，注意节点排序
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


void Branch::set_start(const string& new_name)
{
	branch_name_ = new_name;
	pre_branch_ = NONE_FILE_HASH;
}

string Branch::getPre() const
{
	return pre_branch_;
}

string Branch::getHash() const
{
	return hash_value_;
}

NodeVector& Branch::getNodeVector()
{
	return node_vector_;
}

void Branch::reset_branch(const string& name)
{
	branch_name_ = name;
	pre_branch_ = NONE_FILE_HASH;
}

auto find_node(NodeVector& node_vector, const string& name)
{
	for(auto it = node_vector.begin() ; it!=node_vector.end() ; ++it)
	{
		if ((*it).getName() == name)
			return it;
	}
	return node_vector.end();
}

void Branch::update_file(const string& file_name, const string& new_hash)
{
	auto it = find_node(node_vector_, file_name);
	if (it == node_vector_.end())
	{
		node_vector_.push_back(FileNode(file_name, new_hash));
		return;
	}
	it->hash_value_ = new_hash;
}

string Branch::get_file_hash(const string& file_name)
{
	auto it = find_node(node_vector_, file_name);
	if (it == node_vector_.end())
		return NONE_FILE_HASH;
	return it->getHash();
}


bool operator==(const Branch& left, const Branch& right)
{
	// ??? 是否需要保证pre_hash同样相同 ???
	return (left.branch_name_ == right.branch_name_) &&
		(left.hash_value_ == right.hash_value_);
}

bool operator>=(const Branch& left, const Branch& right)
{
	// TODO:判断left上的全部文件节点是否均比right上对应结点新，注意，当right对应为空节点时，永远为新
	
	// TODO:为此，需要构建right的对应关系的map

	// TODO:依次判断各个节点的更新情况
}
