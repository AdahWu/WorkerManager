#include "Boss.h"
#include <string>

Boss::Boss(int id, string name, int department)
{
	this->id = id;
	this->name = name;
	this->department = department;
}

void Boss::showInfo()
{
	cout << "职工编号：" << id
		<< "\t职工姓名：" << name
		<< "\t职工部门：" << getdepartment()
		<< "\t岗位职责：管理公司事务" << endl;
}
string Boss::getdepartment()
{
	return string("老板");
}