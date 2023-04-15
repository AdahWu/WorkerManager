#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>
using namespace std;
#include <string>
#include "Worker.h"
#include <fstream>

class WorkerManager
{
public:
	WorkerManager();

	
	void exitSystem();
	void addEmp();
	void showEmp();
	void deleteEmp();
	void alterEmp();
	void searchEmp();
	void sortEmp();
	void clearFile();

	int getEmpNum();
	void init_Emp();
	void showMenu();
	void save();


	~WorkerManager();

	bool FileIsEmpty;
	int EmpNum;
	Worker** workers;
};