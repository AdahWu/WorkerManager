#pragma once
#include "Worker.h"
#include <iostream>
using namespace std;

class Boss :public Worker
{
public:
	Boss(int id, string name, int department);
	void showInfo();
	string getdepartment();
};