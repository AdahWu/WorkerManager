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
	cout << "ְ����ţ�" << id
		<< "\tְ��������" << name
		<< "\tְ�����ţ�" << getdepartment()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}
string Manager::getdepartment()
{
	return string("����");
}