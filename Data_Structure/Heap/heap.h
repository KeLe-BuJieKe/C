#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
typedef int HPDataType;
typedef struct Heap
{
    HPDataType* _array;     //��̬���ٵ�����
    int _size;              //Ԫ�ظ���
    int _capacity;          //����
}Heap;


void swap(HPDataType* x, HPDataType* y);


//�������µ���
//����һ��array--------���������������
//��������parent-------���׽��
//��������size---------������Ԫ�صĸ���
//������
void adjustBigHeap(HPDataType* array, int parent, int size);
//����С��
void adjustSmallHeap(HPDataType* array, int parent, int size);



//����ʱ�������ϵ���
//����һ��array--------���������������
//��������child--------�������ڵ�λ��
void adjustUp(HPDataType* array, int child);



// ��������ж�����
//����һ��array--------���������������
//��������size---------������Ԫ�صĸ���
void heapSort(HPDataType* array, int size);



// �ѵĹ���
//����һ��hp-----------ָ��ṹ������ָ��
//��������array--------������������
//��������size---------������Ԫ�صĸ���
void HeapInit(Heap* hp, HPDataType* array, int size);



// �ѵ�����
/*����һ��hp-----------ָ��ṹ������ָ��*/
void HeapDestory(Heap* hp);


// �ѵĲ���
//����һ��hp-----------ָ��ṹ������ָ��
//��������x------------�����������
void HeapPush(Heap* hp, HPDataType x);



// �ѵ�ɾ��
/*����һ��hp-----------ָ��ṹ������ָ��*/
void HeapPop(Heap* hp);



// ȡ�Ѷ�������
/*����һ��hp-----------ָ��ṹ������ָ��*/
HPDataType HeapTop(Heap* hp);



// �ѵ����ݸ���
//�������-1�����ΪNULL
/*����һ��hp-----------ָ��ṹ������ָ��*/
int HeapSize(Heap* hp);



// �ѵ��п�
/*����һ��hp-----------ָ��ṹ������ָ��*/
bool HeapEmpty(Heap* hp);


//��ӡ��
/*����һ��hp-----------ָ��ṹ������ָ��*/
void HeapPrint(Heap* hp);