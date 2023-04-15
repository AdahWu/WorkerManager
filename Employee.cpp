#include "Employee.h"
#include <string>

Employee::Employee(int id, string name, int department)
{
	this->id = id;
	this->name = name;
	this->department = department;
}

void Employee::showInfo()
{
	cout << "职工编号：" << id
		<< "\t职工姓名：" << name
		<< "\t职工部门：" << getdepartment()
		<< "\t岗位职责：完成经理所交给的任务" << endl;
}
string Employee::getdepartment()
{
	return string("员工");
}