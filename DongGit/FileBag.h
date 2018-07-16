#pragma once
/**
 * \brief 包含了File的基本信息，用于向数据库中进行内容输入与输出。
 * 需要包含Hash值，文件名，以及链接情况。（注意，链接情况仅考虑单分支）
 */
class FileBag
{
public:
	FileBag();
	~FileBag();
};

