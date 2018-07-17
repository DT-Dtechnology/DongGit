#pragma once
#include <string>

class BranchFactory
{
public:
	static void create_branch(std::string branch_name);
	static void delete_branch(std::string branch_name);
};

