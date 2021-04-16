#include"WorkerManager.h"
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"


WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME , ios::in);

	//文件不存在的情况
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;

		//初始化职工人数
		this->m_EmpNum = 0;

		//初始化文件的标志为空
		this->m_FileIsEmpty = true;

		//初始化职工数组指针
		this->m_EmpArray = NULL;

		ifs.close();
		return;
	}

	//文件存在但为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空！" << endl;

		//初始化职工人数
		this->m_EmpNum = 0;

		//初始化文件的标志为空
		this->m_FileIsEmpty = true;

		//初始化职工数组指针
		this->m_EmpArray = NULL;

		ifs.close();
		return;
	}

	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	init_Emp();
}



void WorkerManager::ShowMenu()
{
	cout << "***********************************************************************" << endl;
	cout << "*************************欢迎使用职工管理系统!*************************" << endl<<endl;
	cout << "****************************0.退出管理系统*****************************" << endl;
	cout << "****************************1.增加职工信息*****************************" << endl;
	cout << "****************************2.显示职工信息*****************************" << endl;
	cout << "****************************3.删除离职职工*****************************" << endl;
	cout << "****************************4.修改职工信息*****************************" << endl;
	cout << "****************************5.查找职工信息*****************************" << endl;
	cout << "****************************6.重新排序职工*****************************" << endl;
	cout << "****************************7.清空管理系统*****************************" << endl<<endl;
	cout << "***********************************************************************"<< endl;
	cout << endl;
}



void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}



void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的人数：" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间大小（原有的 + 新增的）
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原空间下的内容存放到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//输入新增职工信息
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:   //普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2:   //经理
				worker = new Manager(id, name, 2);
				break;
			case 3:   //总裁
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//存放到新的空间
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新职工人数
		this->m_EmpNum = newSize;

		//更新文件是否为空的标志
		this->m_FileIsEmpty = false;

		//提示信息
		cout << "成功添加" << addNum << "名新职工" << endl;

		//保存数据到文件中
		this->Save();
	}
	else
	{
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");

	system("cls");
}



//保存数据到文件中
void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}



//统计职工人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int did;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}



//初始化职工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		//根据不同的部门Id创建不同对象
		//普通员工
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		//经理
		else if (did ==2)
		{
			worker = new Manager(id, name, did);
		}
		//总裁
		else
		{
			worker = new Boss(id, name, did);
		}

		//存放到数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
}



//显示职工信息
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->ShowInfo();
		}
	}

	system("pause");
	system("cls");
}



//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空！" << endl;
	}
	else
	{
		//按职工编号删除
		cout << "请输入要删除的职工的编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)   //说明该职工编号存在，可以删除
		{
			for (int i = index; i < m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->Save();   //删除后同步数据到文件中
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该编号的职工" << endl;
		}
	}

	system("pause");
	system("cls");
}



//按照职工编号判断职工是否存在，若存在则返回职工在数组中的位置，不存在则返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i= 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;

			break;
		}
	}

	return index;
}



//修改职工信息
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空！" << endl;
	}
	else
	{
		cout << "请输入需要修改信息的职工的编号：" << endl;
		int id;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)   //说明该职工编号存在，可以修改信息
		{
			delete this->m_EmpArray[index];

			int newId = 0;
			string newName = " ";
			int dSelect = 0;

			cout << "查到：" << id << "号职工，请输入新的职工编号：" << endl;
			cin >> newId;

			cout << "请输入新的职工姓名：" << endl;
			cin >> newName;

			cout << "请输入职工新的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:   //普通员工
				worker = new Employee(newId, newName, 1);
				break;
			case 2:   //经理
				worker = new Manager(newId, newName, 2);
				break;
			case 3:   //总裁
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			
			//更改数据到数组中
			this->m_EmpArray[index] = worker;

			cout << "修改成功！" << endl;

			//修改后同步数据到文件中
			this->Save();
		}
		else
		{
			cout << "修改失败，未查找到改职工" << endl;
		}
	}

	system("pause");
	system("cls");
}



//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "请输入想要查找的职工编号" << endl;
			cin >> id;

			int index = this->IsExist(id);
			if (index != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[index]->ShowInfo();
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入想要查找的职工姓名" << endl;
			cin >> name;

			bool flag = false;   //查找到的标志
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功！该职工信息如下：" << endl;

					flag = true;

					this->m_EmpArray[i]->ShowInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}

	system("pause");
	system("cls");
}



//排序职工
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
		
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工编号升序排序" << endl;
		cout << "2.按职工编号降序排序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;
			for (int j = i+1; j < this->m_EmpNum; j++)
			{
				if (select == 1)   //升序排序
				{
					if (m_EmpArray[MinOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				else   //降序排序
				{
					if (m_EmpArray[MinOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
			}

			if (i != MinOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[MinOrMax];
				m_EmpArray[MinOrMax] = temp;
			}
		}

		cout << "排序成功，排序后的结果为：" << endl;
		//同步数据到文件中
		this->Save();
		this->Show_Emp();
	}
}



//清空文件
void WorkerManager::Clean_File()
{
	cout << "是否确认清空" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//trunc   如果文件存在则删除并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}

			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}

		cout << "清空成功" << endl;
	}

	system("pause");
	system("cls");
}



WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}