#pragma once
#include <string>
#include <vector> 
#include "FileNode.h"

using std::string;

typedef std::vector<FileNode> NodeVector;

/**
 * \brief ��¼��֧�Ļ�����Ϣ��������������Hashֵ���������֣������FileNode��vector
 * Ҫ�����ʱ�����ֵ�����ӣ�ע��Ҫ�����Ѿ�ɾ���Ľڵ���Ϣ��Ϊ�˷��������ԭ����
 */
class Branch
{
	string branch_name_;
	string hash_value_;
	NodeVector node_vector_;

	void get_hash();
	void init_hash();
public:

	Branch(const string& hash_value);
	
	/**
	 * \brief ���ڼ�¼��֧��Ϣ������Headָ��λ�ã��Լ��ļ�����ʷ�ظ����¼�ļ���������Hash
	 * ��֧����Ϊ����ṹ���ļ��汾Ϊ����ṹ��
	 * ��֧���ӵ������ļ���Ҫ��������Hash
	 */
	void write();
	void update();
	void addFile(const FileNode& file);
	void insert();
};

