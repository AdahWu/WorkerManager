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
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: //����ְ��
			wm.addEmp();
			break;
		case 2: //��ʾְ��
			wm.showEmp();
			break;
		case 3: //ɾ��ְ��
			wm.deleteEmp();
			break;
		case 4: //�޸�ְ��
			wm.alterEmp();
			break;
		case 5: //����ְ��
			wm.searchEmp();
			break;
		case 6: //����ְ��
			wm.sortEmp();
			break;
		case 7: //����ĵ�
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