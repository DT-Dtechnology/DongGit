#include "stdafx.h"
#include "BranchCommand.h"

void branch_command()
{
	// TODO:�������ݿ�ʵ�ֻ�ȡ���з�֧���Ƶ�ָ��
}

void branch_command(const string& to_branch)
{
	// ��ȡ��ǰ��֧��
	string from_branch;
	ifstream in;
	in.open(CURRENT_BRANCH);
	in >> from_branch;
	in.close();

	branch_command(from_branch, to_branch);
}

void branch_command(const string& from_branch, const string& to_branch)
{
	// TODO:����֧������

	// TODO:����ԭ��֧�����·�֧��ע����ķ�֧���ƺ�his_id��

	// TODO:����Branch_Match��Ϣ

}
