#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// 1����ͷ+����+��ѭ��������ɾ���ʵ��
typedef int SListDataType;


struct SListNode
{
	SListDataType data;
	struct SListNode* next;
};


//�������ӡ	
void SListPrint(const struct SListNode**pplist);

//�����½��
struct SListNode* CreatSListNode(const SListDataType x);
//������β��
void SListPushBack(struct SListNode**pplist,const SListDataType x);

//�������ͷ��
void SListPushFront(struct SListNode**pplist,const SListDataType x);

//�������βɾ
void SListPopBack(struct SListNode**pplist);

//������ͷɾ
void SListPopFront(struct SListNode** pplist);

//���������
struct SListNode* SListFind(struct SListNode*plist, const SListDataType x);

//�������޸�
void SListModify(struct SListNode** plist, const SListDataType Modify_value, const SListDataType target_value);

// ��������posλ��֮�����x
void SListInsertAfter(struct SListNode* pos, const SListDataType x);

//������ɾ��posλ��֮���ֵ
void SListEraseAfter(struct SListNode* pos);
