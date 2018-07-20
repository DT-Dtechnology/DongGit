#pragma once
#include <string>
#include <vector> 
#include "FileNode.h"

using std::string;

typedef std::vector<FileNode> NodeVector;

/**
 * \brief 记录分支的基本信息，包含自身整体Hash值，自身名字，自身的FileNode的vector
 * 要求插入时按照字典序添加，注意要保留已经删除的节点信息，为了方便后续还原操作
 */
class Branch
{
	string branch_name_;
	string hash_value_;
	NodeVector node_vector_{};
	string pre_branch_;
	int his_id_;

	void get_hash();
	void sort_file();

public:

	// 基于Branch_Name建立Branch
	Branch(const string& hash_value);

	// 基于工作区建立Branch
	Branch();

	/**
	 * \brief 用于记录分支信息，包含Head指向位置，以及文件的历史沿革，不记录文件，仅保留Hash
	 * 分支本身为横向结构，文件版本为纵向结构。
	 * 分支串接的所有文件需要进行整体Hash
	 */
	void write();
	void update();
	void addFile(const FileNode& file);
	void insert();
	NodeVector& getNodeVector();

	void reset_branch(const string& name);

	// 判断分支是否相同
	friend bool operator==(const Branch& left, const Branch& right);

	// 判断分支是否更新
	friend bool operator>=(const Branch& left, const Branch& right);
};

