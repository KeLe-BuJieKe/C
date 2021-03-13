#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//�������ݵ��������
enum Max
{
	Name_Max = 20,
	Sex_Max = 6,
	Tele_Max=12,
	Addr_Max=30,
	Data_Max=1000
};

//��ϵ����Ϣ�ṹ��
struct PeoInfo
{
	char _name[Name_Max];		//����
	int _age;					//����
	char _sex[Sex_Max];			//�Ա�
	char _tele[Tele_Max];		//�绰
	char _addr[Addr_Max];		//��ַ
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	struct PeoInfo _data[Data_Max];		//��̬ͨѶ¼
	int _size;							//��¼��ǰ���ж��ٸ���ϵ��
};

//��ʼ��
void InitPerson(struct Addressbooks* Pabs);

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1��ͨѶ��  ����2�ǶԱ�����
int isExist(struct Addressbooks* Pabs, char name[]);

//�����ϵ��
void addPerson(struct Addressbooks* Pabs);

//��ʾ������ϵ��
void showPerson(const struct Addressbooks* Pabs);

//ɾ����ϵ��
void deletePerson(struct Addressbooks* Pabs);

//������ϵ��
void findPerson(const struct Addressbooks* Pabs);

//�޸�ָ������ϵ��
void modifyPerson(struct Addressbooks* Pabs);

//���������ϵ��
void cleanPerson(struct Addressbooks* Pabs);

//������ϵ��
void sortPerson(struct Addressbooks* Pabs);