#include"Student_management_system.h"

//�½�һ��ѧ�����
Student* CreateStuent(const char *_Department,const char *_name,const char *_class)
{
	Student* newNode = (Student*)malloc(sizeof(Student));
	if (newNode == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	strcpy(newNode->_Department,_Department);
	strcpy(newNode->_name , _name);
	strcpy(newNode->_class ,_class);
	newNode->next = NULL;
	return newNode;
}

//����
void DestoryStudent(Student** pps)
{
	if (*pps != NULL)
	{
		while (*pps != NULL)
		{
			Student* To_delete = *pps;
			*pps = (*pps)->next;
			free(To_delete);
			To_delete = NULL;
		}
		printf("��ճɹ�\n");
		FILE* pf = fopen("data.txt", "w");
		fclose(pf);
	}

}

//���ѧ��
void AddStudent(Student** pps)
{
	char Department[_Department_Max];	//�洢ѧԺ��Ϣ
	printf("������ѧԺ\n");
	scanf("%s", Department);


	char name[_Name_Max];				//�洢ѧ������
	printf("����������\n");
	scanf("%s", name);


	char Class[_Class_Max];				//�洢ѧ���༶
	printf("������༶\n");
	scanf("%s", Class);

	//ͷ��
	Student* newNode = CreateStuent(Department, name, Class);
	if (*pps == NULL)
	{
		*pps = newNode;
	}
	else
	{
		newNode->next = *pps;
		*pps = newNode;
	}
	saveStudent(pps);
	printf("��ӳɹ�\n");
	system("pause");
	system("cls");
}

//��ʾѧ��
void ShowStudent(const Student** pps)
{
	Student* cur = *pps;
	if (cur == NULL)
	{
		printf("����ΪNULL\n");
	}
	while (cur != NULL)
	{
		printf("������%-20s �༶:%-20s ѧԺ:%-30s\n", cur->_name, cur->_class, cur->_Department);
		cur = cur->next;
	}
	system("pause");
	system("cls");
}

//�жϸ�ѧ���Ƿ����
Student* is_Exist(Student** pps, char name[])
{
	if (*pps!= NULL)
	{
		Student* cur = *pps;
		while (cur != NULL)
		{
			if (strcmp(cur->_name, name) == 0)
			{
				return cur;
			}
			cur = cur->next;
		}
	}
	else
	{
		return NULL;
	}
}


//��ʾ���ҵ������˵���Ϣ
void show_SingleStudent(const Student* pps)
{
	if (pps == NULL)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("������%-20s �༶:%-20s ѧԺ:%-30s\n", pps->_name, pps->_class, pps->_Department);
	}
	system("pause");
	system("cls");
}

//�����ֲ���
Student* SearchStudent(Student** pps)
{
	printf("��������Ҫ���ҵ�����\n");
	char name[20];
	scanf("%s", name);
	Student* cur = *pps;
	while (cur != NULL)
	{
		if (strcmp(cur->_name, name) == 0)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//�޸�
void ModifyStudent(Student** pps)
{
	printf("��������Ҫ�޸ĵ�������\n");
	char name[20];
	scanf("%s", name);
	Student* Target = is_Exist(pps, name);
	if (Target == NULL)
	{
		printf("��Ҫ�޸ĵ��˲�����\n");
	}
	else
	{	
		//�޸�ѧԺ��Ϣ
		printf("��Ҫ�޸�ѧԺ\n");
		scanf("%s", Target->_Department);


		//�޸�ѧ������
		printf("��Ҫ�޸�����\n");
		scanf("%s", Target->_name);


		//�޸�ѧ���༶
		printf("��Ҫ�޸İ༶\n");
		scanf("%s", Target->_class);
		saveStudent(pps);
		printf("�޸ĳɹ�\n");
		system("pause");
		system("cls");
	}
}

//����
void saveStudent(Student** pps)
{
	FILE* pf = fopen("data.txt", "w");
	if (pf == NULL)
	{
		printf("Save::%s\n", strerror(errno));
		return;
	}
	else
	{
		fprintf(pf, "%s %s %s ",(*pps)->_Department, (*pps)->_class, (*pps) ->_name );
	}
	fclose(pf);
}