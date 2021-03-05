#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DListDataType;
//双向循环单链表
struct DList
{
	struct DList* next;
	struct DList* prev;
	DListDataType data;
};


//创建新结点
struct DList* CreatDListNode(const DListDataType x);

//初始化
struct DList* InitDList();

//清理
void DListClear(struct DList* phead);

//销毁
void DListDestory(struct DList** phead);

//遍历链表
void DListPrint(const struct DList* phead);

//尾插
void DListPushBack(struct DList* phead,const DListDataType x);

//尾删
void DListPopBack(struct DList* phead);

//头插
void DListPushFront(struct DList* phead, const DListDataType x);

//头删
void DListPopFront(struct DList* phead);

//查找
struct DList* DListFind(struct DList* phead, const DListDataType x);

//在x的前面插入
void DListInsert(struct DList* phead, const DListDataType y, const DListDataType x);

//删除x的位置	
void DListErase(struct DList* phead,const DListDataType x);