#pragma once
#include <string>

/**
 * \brief ������File�Ļ�����Ϣ�����������ݿ��н������������������
 * ��Ҫ����Hashֵ���ļ������Լ������������ע�⣬������������ǵ���֧��
 */

using std::string;

class FileNode
{
	string hashValue_;
	FileNode* pre_;		// ���ļ�����Hashֵ�洢����ȡʱת��ΪFileNode��ͬʱ��ָ��Ϊ0
public:
	FileNode();
	~FileNode();
};

