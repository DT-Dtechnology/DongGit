#include "stdafx.h"
#include "CommitAddCommand.h"

void commit_add_command(const string& file_name)
{
	if(file_name == "*")
	{
		commit_add_command();
		return;
	}
	ofstream out;
	ifstream in;
	
	// �����ļ�����ӦHash��ȷ��ǰ�̽ڵ�
	const string hash = get_branch_file_hash();
	
	// �ж�Hashֵ�Ƿ���ͬ����ֱͬ�ӷ��أ��������
	FileNode file(file_name);

	if(file.getHash() == hash)
		return;
	file.setPreNode(hash);
	
	// д�������ͬʱ�������ݿ����ݣ�ע�����ǰ�̽ڵ�
	DB_OP::File_Match_Insert(file);

}

void commit_add_command()
{
	// �������ļ�add

	// TODO:Scott
	// TODO:��ȡ�������������ļ��ļ���
	// TODO:�����ļ���ִ��commit_add_command(file_name)
}

