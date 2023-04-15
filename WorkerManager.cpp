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
		//cout << "�ļ�������" << endl;
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
		//cout << "�ļ�Ϊ��" << endl;
		this->EmpNum = 0;
		this->workers = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	this->EmpNum = getEmpNum();
	cout << "��ְ����Ϊ��" << EmpNum << endl;

	this->init_Emp();
}

void WorkerManager::showMenu()
{
	cout << "****************************************" << endl;
	cout << "**********��ӭʹ��ְ������ϵͳ**********" << endl;
	cout << "********    0.�˳��������     *********" << endl;
	cout << "********    1.����ְ����Ϣ     *********" << endl;
	cout << "********    2.��ʾְ����Ϣ     *********" << endl;
	cout << "********    3.ɾ����ְְ��     *********" << endl;
	cout << "********    4.�޸�ְ����Ϣ     *********" << endl;
	cout << "********    5.����ְ����Ϣ     *********" << endl;
	cout << "********    6.���ձ������     *********" << endl;
	cout << "********    7.��������ĵ�     *********" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addEmp()
{
	int addNum;
	cout << "����������ְ��������" << endl;
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

			cout << "�������" << i + 1 << "��Ա���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��Ա��������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "��Ա����ְλ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
				cout << "��������" << endl;
				break;
			}

			newSpace[EmpNum + i] = worker;
		}
		delete[] workers;
		workers = newSpace;
		EmpNum = newSize;
		this->FileIsEmpty = false;

		cout << "�ɹ����" << addNum << "��ְ��" << endl;
	}
	else
	{
		cout << "��������" << endl;
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
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::deleteEmp()
{
	if (!FileIsEmpty && EmpNum!= 0)
	{
		int delNum;
		cout << "������ɾ��Ա��������" << endl;
		cin >> delNum;

		for (int i = 0; i < delNum; i++) {
			cout << "�������" << i + 1 << "λҪɾ����Ա�����" << endl;
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
				cout << "��Ա��������" << endl;
				i--;
			}
		}
	}
	else
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::alterEmp()
{
	int alterNum;
	cout << "��������Ҫ�޸�ְ��������" << endl;
	cin >> alterNum;
	for (int i = 0; i < alterNum; i++)
	{
		int alterId;
		cout << "�������" << i + 1<< "λ��Ҫ�޸�Ա����ţ�" << endl;
		cin >> alterId;
		for (int j = 0; j < EmpNum; j++) {
			if (j == alterNum)
			{
				int alter_id;
				string alter_name;
				int alter_department;
				Worker* alter_worker;
				cout << "�������޸ĺ����ݣ�" << endl;
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
					cout << "��������" << endl;
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

	cout << "������������ͣ�" << endl;
	cout << "1����Ų���" << endl;
	cout << "2����������" << endl;
	cout << "3�����Ų���" << endl;
	cin >> searchType;
	switch (searchType)
	{
	case 1:
		cout << "��������Ҫ���ҵı�ţ�" << endl;
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
			cout << "�Բ��𣬲��޴���" << endl;
		}
		break;
	case 2:
		cout << "��������Ҫ���ҵ�������" << endl;
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
			cout << "�Բ��𣬲��޴���" << endl;
		}
		break;
	case 3:
		cout << "��������Ҫ���ҵĲ��ű�ţ�" << endl;
		cout << "1����ְͨԱ" << endl;
		cout << "2������" << endl;
		cout << "3���ϰ�" << endl;
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
			cout << "�Բ��𣬲��޴���" << endl;
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
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		int choice;
		cout << "��ѡ������ʽ��" << endl;
		cout << "1����ְ�������������" << endl;
		cout << "2����ְ����Ž�������" << endl;
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
		cout << "������Ϊ��" << endl;
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