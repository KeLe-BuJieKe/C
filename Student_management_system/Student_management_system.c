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

//ɾ��ѧ��
void DeleteStudent(Student** pps)
{

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

}

//����
void saveStudent(Student* ps)
{

}