#include "stdafx.h"
#include "BasicCommandFunction.h"
#include "Branch.h"
#include <sstream>

bool uncommited_change()
{
	Branch current;
	Branch past;

	// TODO:����past��NodeVector����Map��Ȼ�����ø�Map�ж�current�Ƿ��и���

	// TODO:���¼�����жϳ��ȣ�֮�������жϣ�����и��£��򷵻�false

	return true;
}

void refresh_file(const string& branch_name)
{
	Branch branch(branch_name);
	
	// TODO:����������������ļ�

	// ����������д���ļ�
	ofstream out;
	ifstream in;
	for (auto it = branch.getNodeVector().begin(); it != branch.getNodeVector().end(); ++it)
	{
		out.open(GIT_HEAD + it->getName());
		in.open(GIT_OBJECT_HEAD + it->getHash());

		// ֱ�ӻ�ȡinȫ���ļ����ݲ�д�뵽out��
		out << in.rdbuf();

		in.close();
		out.close();
	}
}
