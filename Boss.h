#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//�ܲ���
class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int did);

	//��ʾְ����Ϣ
	virtual void ShowInfo();

	//��ȡְ����λ����
	virtual string GetDeptName();
};