#include<iostream>
using namespace std;
#include"WorkerManager.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#include"Worker.h"

int main()
{
	//实例化管理者对象
	WorkerManager wm;
	int choice = 0;

	while (true)
	{
		//调用展示菜单成员函数
		wm.ShowMenu();
		cout << "请输入您的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:   //退出系统
			wm.ExitSystem();
		case 1:   //添加职工
			wm.Add_Emp();
			break;
		case 2:   //显示职工
			wm.Show_Emp();
			break;
		case 3:   //删除职工
			wm.Del_Emp();
			break;
		case 4:   //修改职工
			wm.Mod_Emp();
			break;
		case 5:   //查找职工
			wm.Find_Emp();
			break;
		case 6:   //排序职工
			wm.Sort_Emp();
			break;
		case 7:   //清空系统
			wm.Clean_File();
			break;
		default:
			system("cls");
		}
	}

	system("pause");

	return 0;
}