#include"Employee.h"

//���캯��
Employee::Employee(int id , string name , int did) 
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ʾְ����Ϣ
void Employee::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
	        << "\tְ��������" << this->m_Name
	        << "\tְ�����ű�ţ�" << this->GetDeptName()
	        << "\t��λְ����ɾ�����������"<< endl;
}

//��ȡְ����λ����
string Employee::GetDeptName()
{
	return string("Ա��");
}
