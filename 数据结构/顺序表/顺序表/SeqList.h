#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DataType;
//顺序表的动态存储
struct SeqList
{
	DataType* array;		//指向动态开辟的数组
	int size;				//有效数据的个数
	int capacity;			//数组的容量大小
};	

//初始化
void SeqListInit(struct SeqList* ps);

//检查是否要扩容
void SeqListCheckCapacity(struct SeqList* ps);

//打印数组
void SeqListPrint(const struct SeqList* ps);

//尾插
void SeqListPushBack(struct SeqList* ps, DataType x);

//尾删
void SeqListPopBack(struct SeqList* ps);

//头插
void SeqListPushFront(struct SeqList* ps,DataType x);

//头删
void SeqListPopFront(struct SeqList* ps);

//任意位置的插入
void SeqListInsert(struct SeqList* ps, int pos, DataType x);

//任意位置的删除
void SeqListErase(struct SeqList* ps, int pos);

//顺序表查找
int SeqListFind(const struct SeqList* ps, DataType x);