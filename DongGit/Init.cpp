#include "stdafx.h"
#include "Init.h"
#include <direct.h>
#include <string>
#include <fstream>
#include <iostream>
#include "sqlite3.h"
#include "callback.h"

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

	out.open(CURRENT_BRANCH);
	out.close();
}

void init_db()
{
	sqlite3* db;
	char *zErrMsg = nullptr;
	int  rc;

	// 检测是否正确创建
	rc = sqlite3_open(INFO_DB, &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else {
		fprintf(stdout, "Opened database successfully\n");
	}

	// 创建Branch的对应表
	auto sql = "CREATE TABLE BRANCH_MATCH("  \
		"NAME TEXT NOT NULL,"		\
		"HASH TEXT NOT NULL,"		\
		"PRE_HASH TEXT NOT NULL"	\
		"HIS_ID INTEGER,"\
		"DISC	TEXT)";

	rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Table created successfully\n");
	}

	// 创建File的对应表
	sql = "CREATE TABLE FILE_MATCH("  \
		"NAME TEXT NOT NULL,"		\
		"HASH TEXT PRIMARY KEY,"	\
		"PRE_HASH TEXT NOT NULL)";

	rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Table created successfully\n");
	}

	sqlite3_close(db);
}

void create_master()
{
	ofstream out;

	out.open(CURRENT_BRANCH);
	out << "master" << endl;
	out.close();
	Branch master;
	
	// 向数据中的Branch数据表中添加新的对应


	

	_mkdir(".git/ref/master");

	// Write Log 

}

void initial_all()
{
	init_folder();
	init_file();
	init_db();
	create_master();
	std::cout << "Initial All" << endl;
}

void initial_all(const std::string& path)
{
	string cmd = "cd " + path;
	system("cmd");
	initial_all();
}
