#include"Dynamic_Contact.h"

//�ж��Ƿ�Ҫ����
void increase_capacity(struct Addressbooks*Pabs)
{
	//�жϵ绰ͨѶ¼�Ƿ�����
	if (Pabs->_size == Pabs->capacity)
	{
		Pabs->capacity = Pabs->capacity + 1;
		struct PeoInfo* temp = (struct PeoInfo*) realloc(Pabs->_data, sizeof(struct PeoInfo) * Pabs->capacity);
		if (temp == NULL)
		{
			printf("�ڴ�����ʧ��\n");
			exit(-1);
		}
		printf("�ڴ�����ɹ�\n");
		Pabs->_data = temp;
	}
}

//���浽�ļ�
void SavePerson(struct Addressbooks* Pabs)
{
	FILE* pf = fopen("Contact_data.txt", "w");
	if (pf == NULL)
	{
		printf("Save::%s\n", strerror(errno));
		return;
	}
	
	for (int i = 0; i <Pabs->_size; i++)
	{
		fprintf(pf, "%s %s %d %s %s ", Pabs->_data[i]._name, Pabs->_data[i]._sex, Pabs->_data[i]._age,
			Pabs->_data[i]._tele, Pabs->_data[i]._addr);
	}

	fclose(pf);
	pf = NULL;
}

//��ʼ��
void InitPerson(struct Addressbooks* Pabs)
{
	Pabs->_size = 0;
	Pabs->capacity = 1;
	Pabs->_data = (struct PeoInfo*)malloc(sizeof(struct PeoInfo)*Pabs->capacity);

	FILE* FI = fopen("Contact_data.txt", "r");
	if (FI == NULL)
	{
		printf("Init::%s\n", strerror(errno));
		return;
	}
	while (fscanf(FI, "%s %s %d %s %s ", Pabs->_data[Pabs->_size]._name, Pabs->_data[Pabs->_size]._sex, &Pabs->_data[Pabs->_size]._age,
		Pabs->_data[Pabs->_size]._tele, Pabs->_data[Pabs->_size]._addr)!=EOF)
	{
		increase_capacity(Pabs);
		
		Pabs->_size++;
	}
	
	fclose(FI);
	FI = NULL;

}


//�����ϵ��
void addPerson(struct Addressbooks* Pabs)
{
	increase_capacity(Pabs);
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
	FILE* PF = fopen("Contact_data.txt", "a");
	if (PF == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	fprintf(PF,"%s %s %d %s %s\n", Pabs->_data[Pabs->_size]._name, Pabs->_data[Pabs->_size]._sex, Pabs->_data[Pabs->_size]._age,
		Pabs->_data[Pabs->_size]._tele, Pabs->_data[Pabs->_size]._addr);
	fclose(PF);
	PF = NULL;
	Pabs->_size++;
	printf("��ӳɹ�\n");
	system("pause");     //�밴���������
	system("cls");      //��������
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
			printf("������%-20s\t", Pabs->_data[i]._name);	
			printf("�Ա�%-5s\t", Pabs->_data[i]._sex);
			printf("���䣺%-2d\t", Pabs->_data[i]._age);
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
		for (i = pos; i < Pabs->_size - 1; i++)
		{
			Pabs->_data[i] = Pabs->_data[i + 1];
		}
		Pabs->_size--;
		printf("ɾ���ɹ�\n");
	}
	SavePerson(Pabs);
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(const struct Addressbooks* Pabs)
{
	char name[Name_Max];
	printf("��������Ҫ���ҵ���ϵ������:\n");
	scanf("%s", name);
	int pos = isExist(Pabs, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("������%-20s\t", Pabs->_data[pos]._name);
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
		printf("�������µ����֣�\n");
		scanf("%s", Pabs->_data[pos]._name);

		//�Ա�
		printf("�������µ��Ա�: �� or Ů \n");
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
		printf("�������µ�����: \n");
		scanf("%d", &Pabs->_data[pos]._age);

		//�绰
		printf("��������ϵ�µĵ绰��\n");
		scanf("%s", Pabs->_data[pos]._tele);

		//סַ
		printf("�������µļ�ͥסַ��\n");
		scanf("%s", Pabs->_data[pos]._addr);
		SavePerson(Pabs);

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
		FILE* pf = fopen("Contact_data.txt", "w");
		fclose(pf);
		pf = NULL;
		free(Pabs->_data);
		Pabs->_size = 0;	//����ǰ��¼��ϵ��������Ϊ0�����߼��ϵ����
		Pabs->capacity = 0;

		printf("ͨѶ�������\n");
	}
	else
	{
		printf("����ȡ�������ϵ��\n");
	}
	system("pause");
	system("cls");
}

//������ϵ��
void sortPerson(struct Addressbooks* Pabs)
{
	for (int i = 0; i < Pabs->_size - 1; i++)
	{
		bool  flag = true;
		for (int j = 0; j < Pabs->_size - 1 - i; j++)
		{
			if (strcmp(Pabs->_data[j]._name, Pabs->_data[j + 1]._name) > 0)
			{
				struct PeoInfo temp = Pabs->_data[j];
				Pabs->_data[j] = Pabs->_data[j + 1];
				Pabs->_data[j + 1] = temp;
				bool flag = false;
			}
		}
		if (flag == true)
		{
			break;
		}
	}
	SavePerson(Pabs);
	printf("�����Ľ��Ϊ��\n");
	showPerson(Pabs);
}