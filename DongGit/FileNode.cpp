#include "stdafx.h"
#include "FileNode.h"
#include "md5_wrapper.h"
#include <sstream>

#define FILE_TEMP "File_Temp"

// TODO:��λ�ȡǰ�̽ڵ���Ϣ�����Գ����������ݿ�

void FileNode::get_hash()
{
	md5wrapper md5;
	hash_value_ = md5.getHashFromFile(file_name_);
}

FileNode::FileNode(const string& file_name):file_name_(file_name)
{
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
	get_hash();

	if (_access((GIT_OBJECT_HEAD + hash_value_).c_str(), 0) != -1)
		return;

	ofstream out;
	out.open(GIT_OBJECT_HEAD + hash_value_);
	
	ifstream in;
	in.open(file_name_);
	out << in.rdbuf();
	in.close();
	out.close();

}

void FileNode::insert()
{
	// TODO:��File_Match����Ӷ�Ӧ
}

inline string FileNode::getName() const
{
	return file_name_;
}

inline string FileNode::getHash() const
{
	return hash_value_;
}
