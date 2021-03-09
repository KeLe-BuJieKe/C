#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QueueDataType;
typedef struct QueueNode
{
	//数据域
	QueueDataType _data;

	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	//队头指针
	QueueNode* _head;

	//队尾指针
	QueueNode* _tail;
}Queue;

//初始化
void QueueInit(Queue* pQ);

//销毁
void QueueDestory(Queue* pQ);

//入队
void QueuePush(Queue* pQ, const QueueDataType x);

//出队
void QueuePop(Queue* pQ);

//取队头元素
QueueDataType QueueFront(Queue* pQ);

//取队尾元素
QueueDataType QueueBack(Queue* pQ);

//判断队是否为空，true表示队为空，false表示队不空
bool QueueEmpty(Queue* pQ);

//队中元素得个数
int QueueSize(Queue* pQ);