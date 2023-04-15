#pragma once
#include "Worker.h"
#include <iostream>
using namespace std;

class Manager :public Worker
{
public:
	Manager(int id, string name, int department);
	void showInfo();
	string getdepartment();
};