#pragma once
#include <string>
#include <vector> 
#include "FileNode.h"

using std::string;

typedef std::vector<FileNode*> NodeVector;

/**
 * \brief 记录分支的基本信息，包含自身整体Hash值，自身名字，自身的FileNode的vector
 * 要求插入时按照字典序添加，注意要保留已经删除的节点信息，为了方便后续还原操作
 */
class Branch
{
	string branch_name_;
	string hasd_value_;
	NodeVector node_vector_;

public:
	
	/**
	 * \brief 用于记录分支信息，包含Head指向位置，以及文件的历史沿革，不记录文件，仅保留Hash
	 * 分支本身为横向结构，文件版本为纵向结构。
	 * 分支串接的所有文件需要进行整体Hash
	 */
	Branch();
	~Branch();
};

