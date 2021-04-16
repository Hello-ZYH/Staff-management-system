#include"Manager.h"

//构造函数
Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//显示职工信息
void Manager::ShowInfo()
{
	cout << "职工编号：" << this->m_Id
		    << "\t职工姓名：" << this->m_Name
	     	<< "\t职工部门编号：" << this->GetDeptName()
	    	<< "\t岗位职责：完成总裁交给的任务，并下发给普通职工" << endl;
}

//获取职工岗位名称
string Manager::GetDeptName()
{
	return string("经理");
}
