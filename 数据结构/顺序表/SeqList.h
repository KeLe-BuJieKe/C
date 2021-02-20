#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DataType;
//˳���Ķ�̬�洢
struct SeqList
{
	DataType* array;		//ָ��̬���ٵ�����
	int size;				//��Ч���ݵĸ���
	int capacity;			//�����������С
};	

//��ʼ��
void SeqListInit(struct SeqList* ps);

//����Ƿ�Ҫ����
void SeqListCheckCapacity(struct SeqList* ps);

//��ӡ����
void SeqListPrint(const struct SeqList* ps);

//β��
void SeqListPushBack(struct SeqList* ps, DataType x);

//βɾ
void SeqListPopBack(struct SeqList* ps);

//ͷ��
void SeqListPushFront(struct SeqList* ps,DataType x);

//ͷɾ
void SeqListPopFront(struct SeqList* ps);

//����λ�õĲ���
void SeqListInsert(struct SeqList* ps, int pos, DataType x);

//����λ�õ�ɾ��
void SeqListErase(struct SeqList* ps, int pos);

//˳������
int SeqListFind(const struct SeqList* ps, DataType x);