#include"Employee.h"

//构造函数
Employee::Employee(int id , string name , int did) 
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//显示职工信息
void Employee::ShowInfo()
{
	cout << "职工编号：" << this->m_Id
	        << "\t职工编号：" << this->m_Name
	        << "\t职工编号：" << this->GetDeptName()
	        << "\t岗位职责：完成经理交给的任务"<< endl;
}

//获取职工岗位名称
string Employee::GetDeptName()
{
	return string("员工");
}
