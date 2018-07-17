#include "stdafx.h"
#include "FileNode.h"
#include "md5_wrapper.h"

void FileNode::get_hash()
{
	md5wrapper md5;
	hash_value_ = md5.getHashFromFile(GIT_OBJECT_HEAD + hash_value_);
}

FileNode::FileNode(const string& file_name, const string& file_hash)
	:file_name_(file_name), hash_value_(file_hash) { }

inline void FileNode::setPreNode(const string& hash_value)
{
	pre_ = hash_value;
}

void FileNode::write()
{
	
}
