#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//��ְͨ����
class Employee :public Worker
{
public:
	//���캯��
	Employee(int id, string name, int did);

	//��ʾְ����Ϣ
	virtual void ShowInfo();

	//��ȡְ����λ����
	virtual string GetDeptName();
};