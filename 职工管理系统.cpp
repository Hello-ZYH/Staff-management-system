#include<iostream>
using namespace std;
#include"WorkerManager.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#include"Worker.h"

int main()
{
	//ʵ���������߶���
	WorkerManager wm;
	int choice = 0;

	while (true)
	{
		//����չʾ�˵���Ա����
		wm.ShowMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:   //�˳�ϵͳ
			wm.ExitSystem();
		case 1:   //���ְ��
			wm.Add_Emp();
			break;
		case 2:   //��ʾְ��
			wm.Show_Emp();
			break;
		case 3:   //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4:   //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5:   //����ְ��
			wm.Find_Emp();
			break;
		case 6:   //����ְ��
			wm.Sort_Emp();
			break;
		case 7:   //���ϵͳ
			wm.Clean_File();
			break;
		default:
			system("cls");
		}
	}

	system("pause");

	return 0;
}