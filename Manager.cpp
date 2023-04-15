#include "Manager.h"
#include <string>

Manager::Manager(int id, string name, int department)
{
	this->id = id;
	this->name = name;
	this->department = department;
}
void Manager::showInfo()
{
	cout << "职工编号：" << id
		<< "\t职工姓名：" << name
		<< "\t职工部门：" << getdepartment()
		<< "\t岗位职责：完成老板交代的任务，并下发任务给员工" << endl;
}
string Manager::getdepartment()
{
	return string("经理");
}