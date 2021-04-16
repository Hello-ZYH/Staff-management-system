#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"
#include<fstream>
#define FILENAME "EmpFile.txt"

class WorkerManager
{
public:
	//构造函数
    WorkerManager();
	
	//展示菜单
	void ShowMenu();

	//退出系统
	void ExitSystem();

	//添加职工
	void Add_Emp();

	//保存数据到文件中
	void Save();

	//统计职工人数
	int get_EmpNum();

	//初始化职工
	void init_Emp();

	//显示职工信息
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//按照职工编号判断职工是否存在，若存在则返回职工在数组中的位置，不存在则返回-1
	int IsExist(int id);

	//修改职工信息
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//记录文件中的职工人数
	int m_EmpNum;

	//职工数组的指针
	Worker** m_EmpArray;

	//文件是否为空的标志
	bool m_FileIsEmpty;

	//析构函数
	~WorkerManager();
};
