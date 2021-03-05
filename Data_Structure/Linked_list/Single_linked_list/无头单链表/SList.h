#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// 1、无头+单向+非循环链表增删查改实现
typedef int SListDataType;


struct SListNode
{
	SListDataType data;
	struct SListNode* next;
};


//单链表打印	
void SListPrint(const struct SListNode**pplist);

//创建新结点
struct SListNode* CreatSListNode(const SListDataType x);
//单链表尾插
void SListPushBack(struct SListNode**pplist,const SListDataType x);

//单链表的头插
void SListPushFront(struct SListNode**pplist,const SListDataType x);

//单链表的尾删
void SListPopBack(struct SListNode**pplist);

//单链表头删
void SListPopFront(struct SListNode** pplist);

//单链表查找
struct SListNode* SListFind(struct SListNode*plist, const SListDataType x);

//单链表修改
void SListModify(struct SListNode** plist, const SListDataType Modify_value, const SListDataType target_value);

// 单链表在pos位置之后插入x
void SListInsertAfter(struct SListNode* pos, const SListDataType x);

//单链表删除pos位置之后的值
void SListEraseAfter(struct SListNode* pos);
