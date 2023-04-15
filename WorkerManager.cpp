#include "WorkerManager.h"
#include "Boss.h"
#include "Manager.h"
#include "Employee.h"
#include "Worker.h"
#include <fstream>
#include <string>
#define FILENAME "Workers.txt"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		EmpNum = 0;
		workers = NULL;
		FileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->EmpNum = 0;
		this->workers = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	this->EmpNum = getEmpNum();
	cout << "在职人数为：" << EmpNum << endl;

	this->init_Emp();
}

void WorkerManager::showMenu()
{
	cout << "****************************************" << endl;
	cout << "**********欢迎使用职工管理系统**********" << endl;
	cout << "********    0.退出管理程序     *********" << endl;
	cout << "********    1.增加职工信息     *********" << endl;
	cout << "********    2.显示职工信息     *********" << endl;
	cout << "********    3.删除离职职工     *********" << endl;
	cout << "********    4.修改职工信息     *********" << endl;
	cout << "********    5.查找职工信息     *********" << endl;
	cout << "********    6.按照编号排序     *********" << endl;
	cout << "********    7.清空所有文档     *********" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addEmp()
{
	int addNum;
	cout << "请输入增加职工的数量" << endl;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize * sizeof(Worker*)];//!!!!!!!!!
		if (workers != NULL)
		{
			for (int i = 0; i < EmpNum; i++) 
			{
				newSpace[i] = workers[i];
			}
		}
		for (int i = 0; i < addNum; i++) 
		{
			int id;
			string name;
			int department;

			cout << "请输入第" << i + 1 << "个员工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个员工的姓名" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个员工的职位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> department;

			Worker* worker = NULL;
			switch (department)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "输入有误" << endl;
				break;
			}

			newSpace[EmpNum + i] = worker;
		}
		delete[] workers;
		workers = newSpace;
		EmpNum = newSize;
		this->FileIsEmpty = false;

		cout << "成功添加" << addNum << "名职工" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
	this->save();
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < EmpNum; i++) {
		ofs << workers[i]->id << " "
			<< workers[i]->name << " "
			<< workers[i]->department << endl;
	}
	ofs.close();
}

int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	string department;

	int num = 0;
	string s;

	while (ifs >> id && ifs >> name && ifs >> department)
	{
		num++;
	}

	ifs.close();

	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	workers = new Worker * [EmpNum * sizeof(Worker*)];

	int id;
	string name;
	int department;

	Worker* worker = NULL;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> department)
	{
		if (department == 1)
		{
			worker = new Employee(id, name, 1);
		}
		else if (department == 2) {
			worker = new Manager(id, name, 2);
		}
		else
		{
			worker = new Boss(id, name, 3);
		}
		this->workers[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::showEmp()
{
	/*ifstream ifs;
	ifs.open("Workers.txt", ios::in);
	string buf;
	while (getline(ifs, buf)) {
		cout << buf << endl;
	}
	ifs.close();*/
	if (!FileIsEmpty && EmpNum!= 0) {
		for (int i = 0; i < EmpNum; i++) {
			workers[i]->showInfo();
		}
	}
	else
	{
		cout << "文件不存在或为空" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::deleteEmp()
{
	if (!FileIsEmpty && EmpNum!= 0)
	{
		int delNum;
		cout << "请输入删除员工数量：" << endl;
		cin >> delNum;

		for (int i = 0; i < delNum; i++) {
			cout << "请输入第" << i + 1 << "位要删除的员工编号" << endl;
			int id;
			cin >> id;
			int flag = 0;
			for (int i = 0; i < EmpNum; i++) {
				if (id == workers[i]->id) {
					for (int j = i; i < EmpNum - 1; i++) {
						workers[i] = workers[i + 1];
					}
					this->EmpNum--;
					this->save();
					flag++;
				}
			}
			if (flag == 0) {
				cout << "该员工不存在" << endl;
				i--;
			}
		}
	}
	else
	{
		cout << "文件为空或不存在" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::alterEmp()
{
	int alterNum;
	cout << "请输入需要修改职工个数：" << endl;
	cin >> alterNum;
	for (int i = 0; i < alterNum; i++)
	{
		int alterId;
		cout << "请输入第" << i + 1<< "位需要修改员工编号：" << endl;
		cin >> alterId;
		for (int j = 0; j < EmpNum; j++) {
			if (j == alterNum)
			{
				int alter_id;
				string alter_name;
				int alter_department;
				Worker* alter_worker;
				cout << "请输入修改后数据：" << endl;
				cin >> alter_id >> alter_name >> alter_department;
				switch (alter_department)
				{
				case 1:
					alter_worker = new Employee(alter_id, alter_name, alter_department);
					workers[j] = alter_worker;
					break;
				case 2:
					alter_worker = new Manager(alter_id, alter_name, alter_department);
					workers[j] = alter_worker;
					break;
				case 3:
					alter_worker = new Boss(alter_id, alter_name, alter_department);
					workers[j] = alter_worker;
					break;
				default:
					cout << "输入有误" << endl;
					j--;
					break;
				}
			}
		}
	}
	this->save();
	system("pause");
	system("cls");
}

void WorkerManager::searchEmp()
{
	int searchId;
	string searchName;
	int searchType;
	int searchDepartment;
	int flag = 0;

	cout << "请输入查找类型：" << endl;
	cout << "1、编号查找" << endl;
	cout << "2、姓名查找" << endl;
	cout << "3、部门查找" << endl;
	cin >> searchType;
	switch (searchType)
	{
	case 1:
		cout << "请输入需要查找的编号：" << endl;
		cin >> searchId;
		for (int i = 0; i < EmpNum; i++) {
			if (workers[i]->id == searchId)
			{
				workers[i]->showInfo();
				flag++;
				break;
			}
		}
		if (flag == 0)
		{
			cout << "对不起，查无此人" << endl;
		}
		break;
	case 2:
		cout << "请输入需要查找的姓名：" << endl;
		cin >> searchName;
		for (int i = 0; i < EmpNum; i++) {
			if (workers[i]->name == searchName)
			{
				workers[i]->showInfo();
				flag++;
				break;
			}
		}
		if (flag == 0)
		{
			cout << "对不起，查无此人" << endl;
		}
		break;
	case 3:
		cout << "请输入需要查找的部门编号：" << endl;
		cout << "1、普通职员" << endl;
		cout << "2、经理" << endl;
		cout << "3、老板" << endl;
		cin >> searchDepartment;
		for (int i = 0; i < EmpNum; i++) {
			if (workers[i]->department == searchDepartment)
			{
				workers[i]->showInfo();
				flag++;
			}
		}
		if (flag == 0)
		{
			cout << "对不起，查无此人" << endl;
		}
		break;
	}
	system("pause");
	system("cls");
}

void WorkerManager::sortEmp()
{
	if (FileIsEmpty == 1 || EmpNum == 0)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		int choice;
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工编号升序排序" << endl;
		cout << "2、按职工编号降序排序" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			for (int i = 0; i < EmpNum - 1; i++)
			{
				for (int j = 0; j < EmpNum - 1 - i; j++)
				{
					if (workers[j]->id > workers[j + 1]->id)
					{
						Worker* tmp = workers[j];
						workers[j] = workers[j + 1];
						workers[j + 1] = tmp;
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < EmpNum - 1; i++)
			{
				for (int j = 0; j < EmpNum - 1 - i; j++)
				{
					if (workers[j]->id < workers[j + 1]->id)
					{
						Worker* tmp = workers[j];
						workers[j] = workers[j + 1];
						workers[j + 1] = tmp;
					}
				}
			}
			break;
		}
		save();
		cout << "排序结果为：" << endl;
		showEmp();
	}
	system("pause");
	system("cls");
}

void WorkerManager::clearFile()
{
	ofstream ofs;
	ofs. open(FILENAME, ios::trunc);
	if (workers != NULL) {
		for (int i = 0; i < EmpNum; i++)
		{
			if (this->workers[i] != NULL)
			{
				delete workers[i];
				workers[i] = NULL;
			}
		}
		delete[] workers;
		workers = NULL;
		this->EmpNum = 0;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager() 
{
	if (workers != NULL) {
		for (int i = 0; i < EmpNum; i++)
		{
			if (this->workers[i] != NULL)
			{
				delete workers[i];
				workers[i] = NULL;
			}
		}
		delete[] workers;
		workers = NULL;
		this->EmpNum = 0;
	}
}