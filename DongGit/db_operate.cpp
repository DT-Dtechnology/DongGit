#include "stdafx.h"
#include "sqlite3.h"
#include "callback.h"
#include "db_operate.h"
#include "DefineSetting.h"




void DB_OP::File_Match_Insert(const FileNode& file)
{
	sqlite3* db;
	int rc;
	char *zErrMsg = nullptr;

	rc = sqlite3_open(INFO_DB, &db);
	if (rc)
	{
		string sql = "INSERT INTO TABLE FILE_MATCH VALUES ('" + file.file_name_+ "','" + file.hash_value_ + "','" + file.pre_file_ + "')";
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



void DB_OP::Branch_Match_Insert(const Branch& branch)
{
	sqlite3* db;
	int rc;
	char *zErrMsg = nullptr;

	rc = sqlite3_open(INFO_DB, &db);
	if (rc)
	{
		string sql = "INSERT INTO TABLE BRANCH_MATCH VALUES ('" + branch.branch_name_ + "','" +branch.hash_value_+ "','" + branch.pre_branch_ + "','" + std::to_string(branch.his_id_) + "',NULL)";
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




string DB_OP::get_File_Hash(const string& name)
{
	sqlite3* db;
	int rc;
	char *zErrMsg = nullptr;
	char *hash = nullptr;

	rc = sqlite3_open(INFO_DB, &db);
	if (rc)
	{
		string sql = "SELECT HASH FROM FILE_MATCH WHERE NAME='"+name+"'";
		rc = sqlite3_exec(db, sql.c_str(), callback, hash, &zErrMsg);
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}

		else
		{
			if (hash == nullptr)
			{
				fprintf(stdout, "##ERROR_NO_SUCH_FILE###");
				return NONE_FILE_HASH;
			}
			else fprintf(stdout, "Find Successfully");
		}
		sqlite3_close(db);
	}
	else
	{
		fprintf(stdout, "###ERROR_OPEN_DATABASE###");
	}
	
	return std::to_string(*hash);
}



string DB_OP::get_File_Pre_Hash(const string& hash)
{
	sqlite3* db;
	int rc;
	char *zErrMsg = nullptr;
	char *prehash = nullptr;

	rc = sqlite3_open(INFO_DB, &db);
	if (rc)
	{
		string sql = "SELECT PRE_HASH FROM FILE_MATCH WHERE HASH='" + hash + "'";
		rc = sqlite3_exec(db, sql.c_str(), callback, prehash, &zErrMsg);
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}

		else
		{
			if (prehash == nullptr)
			{
				fprintf(stdout, "##ERROR_NO_SUCH_FILE###");
				return NONE_FILE_HASH;
			}
			else fprintf(stdout, "Find Successfully");
		}
		sqlite3_close(db);
	}
	else
	{
		fprintf(stdout, "###ERROR_NO_SUCH_FILE###");
	}
	return std::to_string(*prehash);
}

//---------------------------------------------------------------------


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
