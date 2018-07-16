#pragma once
#include <string>

using std::string;

/**
 * \brief 记录分支的基本信息，包含自身整体Hash值，自身名字，自身的FileNode的vector
 * 要求插入时按照
 */
class Branch
{

public:
	
	/**
	 * \brief 用于记录分支信息，包含Head指向位置，以及文件的历史沿革，不记录文件，仅保留Hash
	 * 分支本身为横向结构，文件版本为纵向结构。
	 * 分支串接的所有文件需要进行整体Hash
	 */
	Branch();
	~Branch();
};

