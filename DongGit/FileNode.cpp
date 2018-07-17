#include "stdafx.h"
#include "FileNode.h"
#include "md5_wrapper.h"

FileNode::FileNode(const string& file_name):file_name_(file_name)
{
	md5wrapper md5;
	hash_value_ = md5.getHashFromFile(file_name);
}

inline void FileNode::setPreNode(const string& hash_value)
{
	pre_ = hash_value;
}
