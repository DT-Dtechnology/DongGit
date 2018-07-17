#pragma once
#include <string>

/**
 * \brief ������File�Ļ�����Ϣ�����������ݿ��н������������������
 * ��Ҫ����Hashֵ���ļ������Լ������������ע�⣬������������ǵ���֧��
 */

using std::string;

class Branch;

class FileNode
{
	string file_name_;	// �ļ���������Ϊ���������ļ�������ͬ��hashValue
	string hash_value_;
	string pre_ ;		// ���ļ�����Hashֵ�洢��
						// ȫ��Ϊ0��ʾδ����״̬����׼״̬��
	friend Branch;

	void get_hash();

public:
	FileNode(const string& file_name, const string& file_hash);
	void setPreNode(const string& hash_value);	// �����ļ��м�¼��Hashֵ����������

	void write();
};

