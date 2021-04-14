#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//总裁类
class Boss :public Worker
{
public:
	//构造函数
	Boss(int id, string name, int did);

	//显示职工信息
	virtual void ShowInfo();

	//获取职工岗位名称
	virtual string GetDeptName();
};
