#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DListDataType;
//˫��ѭ��������
struct DList
{
	struct DList* next;
	struct DList* prev;
	DListDataType data;
};


//�����½��
struct DList* CreatDListNode(const DListDataType x);

//��ʼ��
struct DList* InitDList();

//����
void DListClear(struct DList* phead);

//����
void DListDestory(struct DList** phead);

//��������
void DListPrint(const struct DList* phead);

//β��
void DListPushBack(struct DList* phead,const DListDataType x);

//βɾ
void DListPopBack(struct DList* phead);

//ͷ��
void DListPushFront(struct DList* phead, const DListDataType x);

//ͷɾ
void DListPopFront(struct DList* phead);

//����
struct DList* DListFind(struct DList* phead, const DListDataType x);

//��x��ǰ�����
void DListInsert(struct DList* phead, const DListDataType y, const DListDataType x);

//ɾ��x��λ��	
void DListErase(struct DList* phead,const DListDataType x);