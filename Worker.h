#pragma once//防止头文件重复包含
#include <iostream>
using namespace std;
#include <string>

class Worker
{
public:
	virtual void showInfo() = 0;
	virtual string getdepartment() = 0;

	int id = 0;
	string name;
	int department = 0;
};