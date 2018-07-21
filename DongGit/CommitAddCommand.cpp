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
	const string hash = get_branch_file_hash(get_current_branch(), file_name);
	
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

void branch_refresh(int argc, const char* argv[] )
{
	// �½���֧
	Branch branch(get_current_branch());

	// ����ļ�
	for(auto it = 2 ; it < argc ; ++it)
	{
		FileNode file(argv[it]);
		branch.update_file(file.getName(), file.getHash());
	}
	branch.get_hash();
	if(branch.getHash() == branch.getPre())
		return;

	branch.write();
	DB_OP::Branch_Match_Insert(branch);
}

