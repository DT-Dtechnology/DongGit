#pragma once
#include <cstdio>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	if (NotUsed != NULL)
	{
		char* tm = (char*)NotUsed;
		tm = argv[0];//����������Ϊ�գ��򽫴����ָ��ָ��������һ��Ԫ�أ�SELECTʱ�ã���
	}
	
	return 0;
}