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
	cout << "ְ����ţ�" << id
		<< "\tְ��������" << name
		<< "\tְ�����ţ�" << getdepartment()
		<< "\t��λְ����ɾ���������������" << endl;
}
string Employee::getdepartment()
{
	return string("Ա��");
}