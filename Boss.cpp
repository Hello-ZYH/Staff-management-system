#include"Boss.h"

//���캯��
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ʾְ����Ϣ
void Boss::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		    << "\tְ����ţ�" << this->m_Name
	    	<< "\tְ����ţ�" << this->GetDeptName()
	    	<< "\t��λְ�𣺹���˾�ĸ�������" << endl;
}

//��ȡְ����λ����
string Boss::GetDeptName()
{
	return string("�ܲ�");
}
