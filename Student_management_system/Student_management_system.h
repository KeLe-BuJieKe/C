#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
enum Max
{
	_Department_Max = 30,
	_Name_Max = 20,
	_Class_Max=20
};

typedef struct Student
{
	char _Department[_Department_Max];	//�洢ѧԺ��Ϣ
	char _name[_Name_Max];				//�洢ѧ������
	char _class[_Class_Max];			//�洢ѧ���༶
	struct Student* next;				//ָ����һ��ѧ��
}Student;

//�½�һ��ѧ�����
Student* CreateStuent(const char* _Department, const char* _name, const char* _class);

//����
void DestoryStudent(Student** ps);

//���ѧ��
void AddStudent(Student**pps);

//��ʾѧ��
void ShowStudent(const Student** pps);

//�жϸ�ѧ���Ƿ����
Student* is_Exist(Student** pps, char  name[]);


//��ʾ���ҵ������˵���Ϣ
void show_SingleStudent(const Student* pps);

//����
Student* SearchStudent(Student** pps);

//�޸�
void ModifyStudent(Student** pps);

//����
void saveStudent(Student** pps);

