#include "stdafx.h"
#include "sqlite3.h"
#include "callback.h"
#include "db_operate.h"
#include "DefineSetting.h"

void DB_OP::File_Match_Insert(const string& name, const string& hash)
{
	sqlite3* db;
	int rc;
	char *zErrMsg = nullptr;

	rc = sqlite3_open(INFO_DB, &db);
	if (rc)
	{
		string sql = "INSERT INTO TABLE FILE_MATCH VALUES ('" + name +"','"+hash+"','"+ NONE_FILE_HASH+"')";
		rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else 
		{
			fprintf(stdout, "Insert Successfully");
		}
		sqlite3_close(db);
		return;
	}
	else
	{
		fprintf(stdout, "###ERROR_OPEN_DATABASE###");
	}

}

void DB_OP::File_Match_Update(const string& name, const string& hash, const string& pre_hash)
{
	sqlite3* db;
	int rc;
	char *zErrMsg = nullptr;

	rc = sqlite3_open(INFO_DB, &db);
	if (rc)
	{
		string sql = "INSERT INTO TABLE FILE_MATCH VALUES ('" + name + "','" + hash + "','" + pre_hash + "')";
		rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else
		{
			fprintf(stdout, "Update Successfully");
		}
		sqlite3_close(db);
		return;
	}
	else
	{
		fprintf(stdout, "###ERROR_OPEN_DATABASE###");
	}
}


void DB_OP::Branch_Match_Adddisc(const string& disc,const string& hash)
{
	sqlite3* db;
	int rc;
	char *zErrMsg = nullptr;

	rc = sqlite3_open(INFO_DB, &db);
	if (rc)
	{
		string sql = "UPDATE BRANCH_MATCH SET DISC='" + disc + "'WHERE HASH='" + hash + "'" ;
		rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else
		{
			fprintf(stdout, "Update Successfully");
		}
		sqlite3_close(db);
		return;
	}
	else
	{
		fprintf(stdout, "###ERROR_OPEN_DATABASE###");
	}

}


void DB_OP::Branch_Match_Insert(const string& name, const string& hash)
{
	sqlite3* db;
	int rc;
	char *zErrMsg = nullptr;

	rc = sqlite3_open(INFO_DB, &db);
	if (rc)
	{
		string sql = "INSERT INTO TABLE BRANCH_MATCH VALUES ('" + name + "','" + hash + "','" + NONE_FILE_HASH+ "',0,NULL)";
		rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else
		{
			fprintf(stdout, "Insert Successfully");
		}
		sqlite3_close(db);
		return;
	}
	else
	{
		fprintf(stdout, "###ERROR_OPEN_DATABASE###");
	}
}

void DB_OP::Branch_Match_Update(const string& name, const string& hash, const string& pre_hash, int his_id)
{
	//UNDONE
	sqlite3* db;
	int rc;
	char *zErrMsg = nullptr;

	rc = sqlite3_open(INFO_DB, &db);
	if (rc)
	{
		string sql = "INSERT INTO TABLE BRANCH_MATCH VALUES ('" + name + "','" + hash + "','" + pre_hash + "',"+std::to_string(his_id)+",NULL)";
		rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else
		{
			fprintf(stdout, "Update Successfully");
		}
		sqlite3_close(db);
		return;
	}
	else
	{
		fprintf(stdout, "###ERROR_OPEN_DATABASE###");
	}
}

string DB_OP::Branch_Search_Name(const string& hash)
{
	//UNDONE
}

string DB_OP::Branch_Search_Hash(const string& name)
{
	//UNDONE
}

string DB_OP::File_Search_Name(const string& hash)
{
	//UNDONE
}

string DB_OP::File_Search_Hash(const string& name)
{
	//UNDONE
}

string File_Match_Pre(const string& hash)
{
	// TODO:更新前继节点
}
