#pragma once
#include <string>
#include <vector> 
#include "FileNode.h"

using std::string;

typedef std::vector<FileNode*> NodeVector;

/**
 * \brief ��¼��֧�Ļ�����Ϣ��������������Hashֵ���������֣������FileNode��vector
 * Ҫ�����ʱ�����ֵ�����ӣ�ע��Ҫ�����Ѿ�ɾ���Ľڵ���Ϣ��Ϊ�˷��������ԭ����
 */
class Branch
{
	string branch_name_;
	string hasd_value_;
	NodeVector node_vector_;

public:
	
	/**
	 * \brief ���ڼ�¼��֧��Ϣ������Headָ��λ�ã��Լ��ļ�����ʷ�ظ����¼�ļ���������Hash
	 * ��֧����Ϊ����ṹ���ļ��汾Ϊ����ṹ��
	 * ��֧���ӵ������ļ���Ҫ��������Hash
	 */
	Branch();
	~Branch();
};

