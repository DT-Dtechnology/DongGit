#pragma once
#include <string>
#include <iostream>

using std::string;

class Error
{
	string msg_;
public:
	Error(const string& msg) :msg_(msg) { std::cout << msg << std::endl; }
};