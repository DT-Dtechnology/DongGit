#include "stdafx.h"
#include "dbInit.h"
#include "DebugInclude.h"
#include <direct.h>
#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::ofstream;
using std::endl;

void init_folder()
{
	string main_fold_name = ".git";
	string ref_folder = ".git\\ref";
	string db_folder = ".git\\db";
	string object_folder = ".git\\object";
	string status_folder = ".git\\status";
	
	_mkdir(main_fold_name.c_str());
	_mkdir(ref_folder.c_str());
	_mkdir(db_folder.c_str());
	_mkdir(object_folder.c_str());
	_mkdir(status_folder.c_str());
}

void init_file()
{
	ofstream out;

	out.open(FILE_MATCH);
	out.close();

	out.open(BRANCH_MATCH);
	out.close();

	out.open(CURRENT_BRANCH);
	out.close();
}

void create_master()
{
	ofstream out;
	out.open(BRANCH_MATCH);
	out << "master" << " " << NONE_FILE_HASH << endl;
	out.close();

	out.open(CURRENT_BRANCH);
	out << "master" << endl;
	out.close();

	_mkdir(".git/ref/master");

	// Write Log 

}

void initial_all()
{
	init_folder();
	init_file();
	create_master();
	std::cout << "Initial All" << endl;
}

void initial_all(const std::string& path)
{
	string cmd = "cd " + path;
	system("cmd");
	initial_all();
}
