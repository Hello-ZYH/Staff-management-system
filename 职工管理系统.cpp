#include<iostream>
using namespace std;
#include"WorkerManager.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"

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
			break;
		case 2:   //��ʾְ��
			break;
		case 3:   //ɾ��ְ��
			break;
		case 4:   //�޸�ְ��
			break;
		case 5:   //����ְ��
			break;
		case 6:   //����ְ��
			break;
		case 7:   //���ϵͳ
			break;
		default:
			system("cls");
		}
	}


	

	system("pause");

	return 0;
}