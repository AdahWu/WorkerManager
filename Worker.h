#pragma once//��ֹͷ�ļ��ظ�����
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