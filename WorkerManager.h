#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"
#include<fstream>
#define FILENAME "EmpFile.txt"

class WorkerManager
{
public:
	//���캯��
    WorkerManager();
	
	//չʾ�˵�
	void ShowMenu();

	//�˳�ϵͳ
	void ExitSystem();

	//���ְ��
	void Add_Emp();

	//�������ݵ��ļ���
	void Save();

	//ͳ��ְ������
	int get_EmpNum();

	//��ʼ��ְ��
	void init_Emp();

	//��ʾְ����Ϣ
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//����ְ������ж�ְ���Ƿ���ڣ��������򷵻�ְ���������е�λ�ã��������򷵻�-1
	int IsExist(int id);

	//�޸�ְ����Ϣ
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ��
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��¼�ļ��е�ְ������
	int m_EmpNum;

	//ְ�������ָ��
	Worker** m_EmpArray;

	//�ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;

	//��������
	~WorkerManager();
};
