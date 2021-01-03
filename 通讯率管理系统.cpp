#include<iostream>
#include<string>
using namespace std;
#define MAX 1000                   //���һ���궨�壬�����´�ά������MAX��ֵ
struct people
{
	string m_Name;               //����
	int m_Sex;                   //�Ա�
	int m_Age;                   //����
	string m_Phone;              //�绰
	string m_Addr;             //��ַ
};
struct Addressbooks
{
	//Ƕ�׽ṹ��
	struct people perspnArray[MAX];       //ͨѶ¼�б������ϵ�ˣ�MAX���ֵΪ1000
	int m_Size;                   //ͨѶ¼�е�ǰ��¼��ϵ�˸���
};
//1�������ϵ�˹���
void addPerson(Addressbooks *abs)   
{
	//�жϵ绰ͨѶ¼�Ƿ�����
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->perspnArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->perspnArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->perspnArray[abs->m_Size].m_Age = age;
		//�绰
		cout << "��������ϵ�绰" << endl;
		string phone;
		cin >> phone;
		abs->perspnArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "�������ͥסַ" << endl;
		string addr;
		cin >> addr;
		abs->perspnArray[abs->m_Size].m_Addr = addr;
		//����ͨѶ¼������
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");     //�밴���������
		system("cls");      //��������
	}
}
//2����ʾ������ϵ��
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰͨѶ��Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "����:" << abs->perspnArray[i].m_Name << "\t";
			cout << "�Ա�:" << (abs->perspnArray[i].m_Sex ==1?"��":"Ů")<< "\t";
			cout << "���䣺" << abs->perspnArray[i].m_Age << "\t";
			cout << "�绰��" << abs->perspnArray[i].m_Phone << "\t";
			cout << "סַ:" << abs->perspnArray[i].m_Addr << endl;
		}
	}
	system("pause");   //�����������
	system("cls");     //����
}
//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1��ͨѶ��  ����2�ǶԱ�����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->perspnArray[i].m_Name==name)
		{
			return i;
		}
	}
	return -1;
}
//3��ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	string name;
	cout << "��������Ҫɾ������ϵ������: " << endl;
	cin >> name;
	//��ret=-1������޴��ˣ���ret=i����鵽��
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		for (int j=ret; j < abs->m_Size; j++)     //���ҵ��ˣ�Ҫ����ɾ������
		{
			abs->perspnArray[j] = abs->perspnArray[j + 1];     //����ǰ�ƣ�������һ��Ԫ�ص�ֵ���Ӷ�ʹ��ɾ������
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//4����ʾ��ϵ��
void findPerson(Addressbooks*abs)
{
	cout << "����������Ҫ���ҵ���ϵ��:" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		cout << "����:" << abs->perspnArray[ret].m_Name << "\t";
		cout << "�Ա�:" << (abs->perspnArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->perspnArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->perspnArray[ret].m_Phone << "\t";
		cout << "סַ:" << abs->perspnArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//5���޸�ָ������ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) 
	{
		//����
		string name;
		cout << "���������֣�" << endl;
		cin >> name;
		abs->perspnArray[ret].m_Name = name;
		//�Ա�
		cout << "�������Ա�: " << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1|| sex == 2)
			{
				abs->perspnArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "������������������" << endl;
			}
		}
		//����
		cout << "����������: " << endl;
		int age = 0;
		cin >>age;
		abs->perspnArray[ret].m_Age = age;
		//��ϵ�绰
		cout << "��������ϵ�绰" << endl;
		string phone;
		cin >> phone;
		abs->perspnArray[ret].m_Phone = phone;
		//��ͥסַ
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->perspnArray[ret].m_Addr = address;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//6�����������ϵ��
void cleanPerson(Addressbooks* abs)
{
	cout << "��ȷ���Ƿ�Ҫ���������ϵ��" << endl;
	int Delete;
	cout << "1---Yes" << endl;
	cout << "2---No" << endl;
	cin >> Delete;
	if (Delete==1)
	{
		abs->m_Size = 0; //����ǰ��¼��ϵ��������Ϊ0�����߼��ϵ����
		cout << "ͨѶ�������" << endl;
	}
	else
	{
		cout << "����ȡ�������ϵ��" << endl;
	}

	system("pause");
	system("cls");
}
void shouMenu()
{
	cout << "***********************" << endl;
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2����ʾ��ϵ��*****" << endl;
	cout << "*****3��ɾ����ϵ��*****" << endl;
	cout << "*****4��������ϵ��*****" << endl;
	cout << "*****5���޸���ϵ��*****" << endl;
	cout << "*****6�������ϵ��*****" << endl;
	cout << "*****0���˳�ͨѶ��*****" << endl;
	cout << "***********************" << endl;
}
//�˵�����
int main()
{
	Addressbooks abs;    //����ͨѶ¼�ṹ�����
	abs.m_Size = 0;      //��ʼ��ͨѶ¼�е�ǰ��Ա����
	int select = 0;     //�����û�ѡ������ı���
	while (true)
	{
		shouMenu();
		cin >> select;
		switch (select)
		{
		case 1:                 //�����ϵ��
			addPerson(&abs);
			break;
		case 2:                 //��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:                 //ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4:                 //������ϵ��
			findPerson(&abs);
			break;
		case 5:                 //�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:                 //�����ϵ��
			cleanPerson(&abs);
			break;
		case 0:                 //�˳�ͨѶ¼
			cout << "�����˳����򣬻�ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	return 0;
}