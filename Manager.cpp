#include"Manager.h"

//���캯��
Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ʾְ����Ϣ
void Manager::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		    << "\tְ����ţ�" << this->m_Name
	     	<< "\tְ����ţ�" << this->GetDeptName()
	    	<< "\t��λְ������ܲý��������񣬲��·�����ְͨ��" << endl;
}

//��ȡְ����λ����
string Manager::GetDeptName()
{
	return string("����");
}
