#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//普通职工类
class Employee :public Worker
{
public:
	//构造函数
	Employee(int id, string name, int did);

	//显示职工信息
	virtual void ShowInfo();

	//获取职工岗位名称
	virtual string GetDeptName();
};