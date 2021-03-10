#include"Contact.h"

//��ʼ��
void InitPerson(struct Addressbooks* Pabs)
{
	Pabs->_size = 0;
	memset(Pabs->_data, 0, sizeof(Pabs->_data));
}


//�����ϵ��
void addPerson(struct Addressbooks* Pabs)
{
	//�жϵ绰ͨѶ¼�Ƿ�����
	if (Pabs->_size==Data_Max)
	{
		printf("ͨѶ¼���������ʧ��\n");
		return;
	}
	else
	{
		//����
		printf("���������֣�\n");
		scanf("%s", Pabs->_data[Pabs->_size]._name);

		//�Ա�
		printf("�������Ա�: �� or Ů \n");
		while (true)
		{
			scanf("%s", Pabs->_data[Pabs->_size]._sex);
			if (strcmp(Pabs->_data[Pabs->_size]._sex, "��") == 0)
			{
				break;
			}
			else if (strcmp(Pabs->_data[Pabs->_size]._sex, "Ů") == 0)
			{
				break;
			}
			printf("�����������������\n");
		}

		//����
		printf("����������: \n");
		scanf("%d", &Pabs->_data[Pabs->_size]._age);


		//�绰
		printf("��������ϵ�绰��\n");
		scanf("%s", Pabs->_data[Pabs->_size]._tele);

		//סַ
		printf("�������ͥסַ��\n");
		scanf("%s", Pabs->_data[Pabs->_size]._addr);

		//����ͨѶ¼������
		Pabs->_size++;
		printf("��ӳɹ�\n");
		system("pause");     //�밴���������
		system("cls");      //��������
	}
}

//��ʾ������ϵ��
void showPerson(const struct Addressbooks* Pabs)
{
	if (Pabs->_size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		for (i = 0; i < Pabs->_size; i++)
		{
			printf("������%s\t", Pabs->_data[i]._name);
			printf("���䣺%-2d\t",  Pabs->_data[i]._age);
			printf("�Ա�%-5s\t", Pabs->_data[i]._sex);
			printf("�绰��%-10s\t", Pabs->_data[i]._tele);
			printf("��ַ��%-10s\t", Pabs->_data[i]._addr);
			printf("\n");
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1��ͨѶ��  ����2�ǶԱ�����
int isExist(struct Addressbooks* Pabs, char name[])
{
	for (int i = 0; i < Pabs->_size; i++)
	{
		if (strcmp(Pabs->_data[i]._name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ��
void deletePerson(struct Addressbooks* Pabs)
{
	char name[Name_Max];
	printf("��������Ҫɾ������ϵ������:\n");
	scanf("%s", name);
	int pos = isExist(Pabs, name);
	if (pos == -1)
	{
		printf("��Ҫɾ������ϵ�˲�����\n");
	}
	else
	{
		int i = 0;
		for (i = pos;i < Pabs->_size-1; i++)
		{
			Pabs->_data[i] = Pabs->_data[i + 1];
		}
		Pabs->_size--;
		printf("ɾ���ɹ�\n");
	}
	
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(const struct Addressbooks* Pabs)
{
	char name[Name_Max];
	printf("��������Ҫ���ҵ���ϵ������:\n");
	scanf("%s", name);
	int pos = isExist(Pabs,name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("������%s\t", Pabs->_data[pos]._name);
		printf("���䣺%-2d\t", Pabs->_data[pos]._age);
		printf("�Ա�%-5s\t", Pabs->_data[pos]._sex);
		printf("�绰��%-10s\t", Pabs->_data[pos]._tele);
		printf("��ַ��%-10s\t", Pabs->_data[pos]._addr);
	}
	system("pause");
	system("cls");
}

//�޸�ָ������ϵ��
void modifyPerson(struct Addressbooks* Pabs)
{
	char name[Name_Max];
	printf("��������Ҫ�޸ĵ���ϵ������:\n");
	scanf("%s", name);
	int pos = isExist(Pabs, name);
	if (pos == -1)
	{
		printf("�޸ĵ���ϵ�˲�����\n");
	}
	else
	{		//����
		printf("���������֣�\n");
		scanf("%s", Pabs->_data[pos]._name);

		//�Ա�
		printf("�������Ա�: �� or Ů \n");
		while (true)
		{
			scanf("%s", Pabs->_data[pos]._sex);
			if (strcmp(Pabs->_data[pos]._sex, "��") == 0)
			{
				break;
			}
			else if (strcmp(Pabs->_data[pos]._sex, "Ů") == 0)
			{
				break;
			}
			printf("�����������������\n");
		}

		//����
		printf("����������: \n");
		scanf("%d", &Pabs->_data[pos]._age);

		//�绰
		printf("��������ϵ�绰��\n");
		scanf("%s", Pabs->_data[pos]._tele);

		//סַ
		printf("�������ͥסַ��\n");
		scanf("%s", Pabs->_data[pos]._addr);

		printf("�޸ĳɹ�\n");
		system("pause");     //�밴���������
		system("cls");      //��������
	}
}

//���������ϵ��
void cleanPerson(struct Addressbooks* Pabs) 
{
	printf("��ȷ���Ƿ�Ҫ���������ϵ��\n");
	int select = 0;
	printf("1---Yes\n");
	printf("0---No\n");

	scanf("%d", &select);
	if (select == 1)
	{
		Pabs->_size = 0;	//����ǰ��¼��ϵ��������Ϊ0�����߼��ϵ����
		printf("ͨѶ�������\n");
	}
	else
	{
		printf("����ȡ�������ϵ��\n");
	}
	system("pause");
	system("cls");
}
