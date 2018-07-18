#include "stdafx.h"
#include "FileNode.h"
#include "md5_wrapper.h"
#include <sstream>

#define FILE_TEMP "File_Temp"

void FileNode::get_hash()
{
	md5wrapper md5;
	hash_value_ = md5.getHashFromFile(GIT_OBJECT_HEAD + hash_value_);
}

void FileNode::init_hash()
{
	ofstream out;
	out.open(FILE_TEMP);
	out << pre_;		// 首先将Pre的信息写入

	ifstream in;
	in.open(file_name_);
	std::ostringstream tmp;
	tmp << in.rdbuf();
	const string str = tmp.str();
	in.close();
	out << str;
	out.close();

	md5wrapper md5;
	hash_value_ = md5.getHashFromFile(FILE_TEMP);

	remove(FILE_TEMP);
}

FileNode::FileNode(const string& file_name):file_name_(file_name)
{
	write();
	get_hash();
}

FileNode::FileNode(const string& file_name, const string& file_hash)
	:file_name_(file_name), hash_value_(file_hash) { }

inline void FileNode::setPreNode(const string& hash_value)
{
	pre_ = hash_value;
}

void FileNode::write()
{
	init_hash();

	if (_access((GIT_OBJECT_HEAD + hash_value_).c_str(), 0) != -1)
		return;

	ofstream out;
	out.open(GIT_OBJECT_HEAD + hash_value_);
	out << pre_;		// 首先将Pre的信息写入
	
	ifstream in;
	in.open(file_name_);
	out << in.rdbuf();
	in.close();
	out.close();

}

void FileNode::insert()
{
	// TODO:向File_Match中添加对应
}

inline string FileNode::getName() const
{
	return file_name_;
}

inline string FileNode::getHash() const
{
	return hash_value_;
}
