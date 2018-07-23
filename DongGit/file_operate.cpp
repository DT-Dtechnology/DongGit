#include "stdafx.h"
#include "file_operate.h"

string get_current_branch()
{
	ifstream in;
	in.open(CURRENT_BRANCH);
	string name;
	in >> name;
	in.close();
	return name;
}

void file_conflict(const string& branch1, const string& branch2)
{
}

string get_branch_file_hash(const string& branch, const string& file)
{
	const string branch_hash = DB_OP::get_Branch_Hash(branch);

	Branch branch_data(branch_hash);
	system("pause");

	return branch_data.get_file_hash(file);
}

string get_Branch_Latest_Hash(const string& name)
{
	ifstream in;
	string hash;
	in.open(GIT_REF + name);
	in >> hash;
	in.close();
	return hash;
}

void get_file_name(string path, vector<string>& files)
{	
	//文件句柄  
	long   hFile = 0;
	//文件信息  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之  
			//如果不是,加入列表  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0 && fileinfo.name[0] != '.')
					get_file_name(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

