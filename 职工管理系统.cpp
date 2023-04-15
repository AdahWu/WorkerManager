#include <iostream>
using namespace std;
#include "WorkerManager.h"

int main()
{
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //退出系统
			wm.exitSystem();
			break;
		case 1: //增加职工
			wm.addEmp();
			break;
		case 2: //显示职工
			wm.showEmp();
			break;
		case 3: //删除职工
			wm.deleteEmp();
			break;
		case 4: //修改职工
			wm.alterEmp();
			break;
		case 5: //查找职工
			wm.searchEmp();
			break;
		case 6: //排序职工
			wm.sortEmp();
			break;
		case 7: //清空文档
			wm.clearFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}