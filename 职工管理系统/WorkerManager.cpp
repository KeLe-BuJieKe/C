#include"WorkerManager.h"
WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open("empFile.txt", ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.�ļ����� ������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݣ��浽������
	this->init_Emp();
}
//ͳ���ļ�������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open("empFile.txt", ios::in);   //���ļ� ��

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//ͳ����������
		num++;
	}
	return num;
};

//��ʼ��Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open("empFile.txt", ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)  //��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		else if(dId==2) //����
		{
			worker = new Manager(id, name, dId);
		}
		else //�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete[]this->m_EmpArray[i];
			}
		}
		delete[]this->m_EmpArray;
	}

}
//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open("empFile.txt", ios::out); //������ķ�ʽ���ļ�  --д�ļ�

	//��ÿ���˵�����д�뵽�ļ���
	for (int k = 0; k < this->m_EmpNum; k++)
	{
		ofs << this->m_EmpArray[k]->m_Id << "   "
			<< this->m_EmpArray[k]->m_Name << "   "
			<< this->m_EmpArray[k]->m_DeptId << endl;
	}

	//�ر��ļ�
	ofs.close();
}
void WorkerManager::Show_Menu()
{
	cout << "**********************************************" << endl;
	cout << "**********  ��ӭʹ��ְ������ϵͳ  ************" << endl;
	cout << "**************  0.�˳��������  **************" << endl;
	cout << "**************  1.����ְ����Ϣ  **************" << endl;
	cout << "**************  2.��ʾְ����Ϣ  **************" << endl;
	cout << "**************  3.ɾ����ְְ��  **************" << endl;
	cout << "**************  4.�޸�ְ����Ϣ  **************" << endl;
	cout << "**************  5.����ְ����Ϣ  **************" << endl;
	cout << "**************  6.���ձ������  **************" << endl;
	cout << "**************  7.��������ĵ�  **************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}
//0.�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//1.���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ����������" << endl;
	int addNum = 0;     //�����û�����������
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;   //�¿ռ�����=ԭ����¼������+��������

		//�����¿ռ�
		Worker**newSpace=new Worker* [newSize];

		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int j = 0; j < addNum; j++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��

			cout << "�������" << j + 1 << "����ְ�����" << endl;
			cin >> id;

			cout << "�������" << j + 1 << "����ְ������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker=NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//��������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum+j] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[]this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;
		//��ʾ��ӳɹ�
		cout << "�ɹ���ӣ�" << addNum << "����ְ��!" << endl;

		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}

	//��������� ������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//2.��ʾְ��
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int L = 0; L < this->m_EmpNum; L++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[L]->ShowInfo();
		}
	}
	//��������� ������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//3.ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		 //����ְ�����ɾ��
		cout << "��������Ҫɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;
		int index=this->IsExist(id);
		if (index != -1)  //˵��ְ�����ڣ�����Ҫɾ����indexλ���ϵ�ְ��
		{
			//����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//���������м�¼��Ա����
			this->m_EmpNum--;
			//����ͬ�����µ��ļ��� 
			this->save();
		}
		else
		{
			cout << "ɾ��ʧ��,δ�ҵ���ְ��" << endl;
		}
	}
	//��������� ������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����  ������ڷ���ְ�����������е�λ�ã������ڷ���-1
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int H = 0; H < this->m_EmpNum; H++)
	{
		if (this->m_EmpArray[H]->m_Id == id)
		{
			//�ҵ�ְ��
			index = H;
			break;
		}
	}
    return index;
}

//4.�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�ְ�����" << endl;
		int id;
		cin >> id;

		int ret=this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ��
			int newId=0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽�� " << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newId;

			cout << "�������µ������� " << endl;
			cin >> newName;

			cout << "�������λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			//�������� ��������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();

		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	//��������� ������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//5.����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ:" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//���ձ�Ų�
			int id;
			cout << "��������Ҫ���ҵı��:" << endl;
			cin >> id;

			int ret=IsExist(id);

			if (ret != -1)
			{
				//�ҵ���ְ��
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select==2)
		{
			//����������
			string name;
			cout << "��������Ҫ���ҵ�������" << endl;
			cin >> name;
			 
			//�����ж��Ƿ�鵽�ı�־
			bool flag = false; //Ĭ��δ�ҵ���ְ��
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ:" 
						<< this->m_EmpArray[i]->m_Id 
						<< "��ְ����Ϣ����:" << endl;

					flag = true;
					//������ʾ��Ϣ�ӿ�
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
			cout << "�����ѡ������" << endl;
		}
	}
	//��������� ������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");

}

//6.����ְ��
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;

		//��������� ������ص��ϼ�Ŀ¼
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1������ְ���Ž�����������" << endl;
		cout << "2������ְ���Ž��н�������" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;//������Сֵ �� ���ֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1) //����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else if(select==2)  //����
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "������������������" << endl;
				}
			}
			//�ж�һ��ʼ�϶� ��Сֵ�����ֵ �ǲ��� �������Сֵ�����ֵ��������� ��������
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save();   //�����Ľ�����浽�ļ���
		this->Show_Emp();
	}
}

//7.����ļ�
void WorkerManager::Clean_File()
{
	cout << "��ȷ��Ҫ����ļ���" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin>>select;

	if (select == 1)
	{
		//����ļ�
		ofstream ofs("empFile.txt", ios::trunc);  //ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete[]this->m_EmpArray;
				this->m_EmpArray = NULL;
			}
			//ɾ������������ָ��
			delete[]this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	else if (select == 2)
	{
	
	}
	else
	{
		cout << "������������������" << endl;
	}
	//��������� ������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}