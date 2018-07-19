#include "stdafx.h"
#include "sqlite3.h"
#include "callback.h"
#include "db_operate.h"

void File_Match_Insert(const string& name, const string& hash)
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

void File_Match_Update(const string& name, const string& hash, const string& pre_hash)
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


void Branch_Match_Adddisc(const string& disc)
{

}


void Branch_Match_Insert(const string& name, const string& hash)
{
	sqlite3* db;
	int rc;
	char *zErrMsg = nullptr;

	rc = sqlite3_open(INFO_DB, &db);
	if (rc)
	{
		string sql = "INSERT INTO TABLE BRANCH_MATCH VALUES ('" + name + "','" + hash + "','" + NONE_FILE_HASH+ "','"+"";
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

void Branch_Match_Update(const string& name, const string& hash, const string& pre_hash, int his_id)
{
	sqlite3* db;
	int rc;
	char *zErrMsg = nullptr;

	rc = sqlite3_open(INFO_DB, &db);
	if (rc)
	{
		string sql = "INSERT INTO TABLE BRANCH_MATCH VALUES ('" + name + "','" + hash + "','" + NONE_FILE_HASH + "','" + ;
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

string Branch_Search_Name(const string& hash)
{
}

string Branch_Search_Hash(const string& name)
{
}

string File_Search_Name(const string& hash)
{
}

string File_Search_Hash(const string& name)
{
}
