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
	
	// TODO:�����ļ�����ӦHash��ȷ��ǰ�̽ڵ�
	
	// TODO:�ж�Hashֵ�Ƿ���ͬ����ֱͬ�ӷ��أ��������
	
	// TODO:д�������ͬʱ�������ݿ����ݣ�ע�����ǰ�̽ڵ�
	

}

void commit_add_command()
{
	// �������ļ�add
	// TODO:��ȡ�������������ļ��ļ���

	// TODO:�����ļ���ִ��commit_add_command(file_name)
}

