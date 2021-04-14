#include"Boss.h"

//构造函数
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//显示职工信息
void Boss::ShowInfo()
{
	cout << "职工编号：" << this->m_Id
		    << "\t职工编号：" << this->m_Name
	    	<< "\t职工编号：" << this->GetDeptName()
	    	<< "\t岗位职责：管理公司的各种事情" << endl;
}

//获取职工岗位名称
string Boss::GetDeptName()
{
	return string("总裁");
}
