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
	cout << "ְ����ţ�" << id
		<< "\tְ��������" << name
		<< "\tְ�����ţ�" << getdepartment()
		<< "\t��λְ�𣺹���˾����" << endl;
}
string Boss::getdepartment()
{
	return string("�ϰ�");
}