#pragma once
#include "Worker.h"
#include <iostream>
using namespace std;

class Employee :public Worker
{
public:
	Employee(int id, string name, int department);
	void showInfo();
	string getdepartment();
};