#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QueueDataType;
typedef struct QueueNode
{
	//������
	QueueDataType _data;

	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	//��ͷָ��
	QueueNode* _head;

	//��βָ��
	QueueNode* _tail;
}Queue;

//��ʼ��
void QueueInit(Queue* pQ);

//����
void QueueDestory(Queue* pQ);

//���
void QueuePush(Queue* pQ, const QueueDataType x);

//����
void QueuePop(Queue* pQ);

//ȡ��ͷԪ��
QueueDataType QueueFront(Queue* pQ);

//ȡ��βԪ��
QueueDataType QueueBack(Queue* pQ);

//�ж϶��Ƿ�Ϊ�գ�true��ʾ��Ϊ�գ�false��ʾ�Ӳ���
bool QueueEmpty(Queue* pQ);

//����Ԫ�صø���
int QueueSize(Queue* pQ);