#include"WorkerManager.h"
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"


WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME , ios::in);

	//�ļ������ڵ����
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;

		//��ʼ��ְ������
		this->m_EmpNum = 0;

		//��ʼ���ļ��ı�־Ϊ��
		this->m_FileIsEmpty = true;

		//��ʼ��ְ������ָ��
		this->m_EmpArray = NULL;

		ifs.close();
		return;
	}

	//�ļ����ڵ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;

		//��ʼ��ְ������
		this->m_EmpNum = 0;

		//��ʼ���ļ��ı�־Ϊ��
		this->m_FileIsEmpty = true;

		//��ʼ��ְ������ָ��
		this->m_EmpArray = NULL;

		ifs.close();
		return;
	}

	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	init_Emp();
}



void WorkerManager::ShowMenu()
{
	cout << "***********************************************************************" << endl;
	cout << "*************************��ӭʹ��ְ������ϵͳ!*************************" << endl<<endl;
	cout << "****************************0.�˳�����ϵͳ*****************************" << endl;
	cout << "****************************1.����ְ����Ϣ*****************************" << endl;
	cout << "****************************2.��ʾְ����Ϣ*****************************" << endl;
	cout << "****************************3.ɾ����ְְ��*****************************" << endl;
	cout << "****************************4.�޸�ְ����Ϣ*****************************" << endl;
	cout << "****************************5.����ְ����Ϣ*****************************" << endl;
	cout << "****************************6.��������ְ��*****************************" << endl;
	cout << "****************************7.��չ���ϵͳ*****************************" << endl<<endl;
	cout << "***********************************************************************"<< endl;
	cout << endl;
}



void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}



void WorkerManager::Add_Emp()
{
	cout << "���������ְ����������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//�����¿ռ��С��ԭ�е� + �����ģ�
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ�ռ��µ����ݴ�ŵ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//��������ְ����Ϣ
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:   //��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2:   //����
				worker = new Manager(id, name, 2);
				break;
			case 3:   //�ܲ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//��ŵ��µĿռ�
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//����ְ������
		this->m_EmpNum = newSize;

		//�����ļ��Ƿ�Ϊ�յı�־
		this->m_FileIsEmpty = false;

		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		//�������ݵ��ļ���
		this->Save();
	}
	else
	{
		cout << "������������������" << endl;
	}

	system("pause");

	system("cls");
}



//�������ݵ��ļ���
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



//ͳ��ְ������
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
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}



//��ʼ��ְ��
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
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		//��ͨԱ��
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		//����
		else if (did ==2)
		{
			worker = new Manager(id, name, did);
		}
		//�ܲ�
		else
		{
			worker = new Boss(id, name, did);
		}

		//��ŵ�������
		this->m_EmpArray[index] = worker;
		index++;
	}
}



//��ʾְ����Ϣ
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
			this->m_EmpArray[i]->ShowInfo();
		}
	}

	system("pause");
	system("cls");
}



//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ�գ�" << endl;
	}
	else
	{
		//��ְ�����ɾ��
		cout << "������Ҫɾ����ְ���ı�ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)   //˵����ְ����Ŵ��ڣ�����ɾ��
		{
			for (int i = index; i < m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->Save();   //ɾ����ͬ�����ݵ��ļ���
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ��ñ�ŵ�ְ��" << endl;
		}
	}

	system("pause");
	system("cls");
}



//����ְ������ж�ְ���Ƿ���ڣ��������򷵻�ְ���������е�λ�ã��������򷵻�-1
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



//�޸�ְ����Ϣ
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸���Ϣ��ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)   //˵����ְ����Ŵ��ڣ������޸���Ϣ
		{
			delete this->m_EmpArray[index];

			int newId = 0;
			string newName = " ";
			int dSelect = 0;

			cout << "�鵽��" << id << "��ְ�����������µ�ְ����ţ�" << endl;
			cin >> newId;

			cout << "�������µ�ְ��������" << endl;
			cin >> newName;

			cout << "������ְ���µĸ�λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:   //��ͨԱ��
				worker = new Employee(newId, newName, 1);
				break;
			case 2:   //����
				worker = new Manager(newId, newName, 2);
				break;
			case 3:   //�ܲ�
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			
			//�������ݵ�������
			this->m_EmpArray[index] = worker;

			cout << "�޸ĳɹ���" << endl;

			//�޸ĺ�ͬ�����ݵ��ļ���
			this->Save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ�δ���ҵ���ְ��" << endl;
		}
	}

	system("pause");
	system("cls");
}



//����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "��������Ҫ���ҵ�ְ�����" << endl;
			cin >> id;

			int index = this->IsExist(id);
			if (index != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[index]->ShowInfo();
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "��������Ҫ���ҵ�ְ������" << endl;
			cin >> name;

			bool flag = false;   //���ҵ��ı�־
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;

					flag = true;

					this->m_EmpArray[i]->ShowInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}

	system("pause");
	system("cls");
}



//����ְ��
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
		
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��ְ�������������" << endl;
		cout << "2.��ְ����Ž�������" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;
			for (int j = i+1; j < this->m_EmpNum; j++)
			{
				if (select == 1)   //��������
				{
					if (m_EmpArray[MinOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				else   //��������
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

		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		//ͬ�����ݵ��ļ���
		this->Save();
		this->Show_Emp();
	}
}



//����ļ�
void WorkerManager::Clean_File()
{
	cout << "�Ƿ�ȷ�����" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//trunc   ����ļ�������ɾ�������´���
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

		cout << "��ճɹ�" << endl;
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