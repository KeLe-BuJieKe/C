#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
typedef int HPDataType;
typedef struct Heap
{
    HPDataType* _array;     //动态开辟的数组
    int _size;              //元素个数
    int _capacity;          //容量
}Heap;


void swap(HPDataType* x, HPDataType* y);


//从上往下调整
//参数一：array--------待排序的整形数组
//参数二：parent-------父亲结点
//参数三：size---------数组中元素的个数
//构造大堆
void adjustBigHeap(HPDataType* array, int parent, int size);
//构造小堆
void adjustSmallHeap(HPDataType* array, int parent, int size);



//插入时从下往上调整
//参数一：array--------待排序的整形数组
//参数二：child--------孩子所在的位置
void adjustUp(HPDataType* array, int child);



// 对数组进行堆排序
//参数一：array--------待排序的整形数组
//参数二：size---------数组中元素的个数
void heapSort(HPDataType* array, int size);



// 堆的构建
//参数一：hp-----------指向结构体对象的指针
//参数二：array--------传进来的数组
//参数三：size---------数组中元素的个数
void HeapInit(Heap* hp, HPDataType* array, int size);



// 堆的销毁
/*参数一：hp-----------指向结构体对象的指针*/
void HeapDestory(Heap* hp);


// 堆的插入
//参数一：hp-----------指向结构体对象的指针
//参数二：x------------待插入的数据
void HeapPush(Heap* hp, HPDataType x);



// 堆的删除
/*参数一：hp-----------指向结构体对象的指针*/
void HeapPop(Heap* hp);



// 取堆顶的数据
/*参数一：hp-----------指向结构体对象的指针*/
HPDataType HeapTop(Heap* hp);



// 堆的数据个数
//如果返回-1代表堆为NULL
/*参数一：hp-----------指向结构体对象的指针*/
int HeapSize(Heap* hp);



// 堆的判空
/*参数一：hp-----------指向结构体对象的指针*/
bool HeapEmpty(Heap* hp);


//打印堆
/*参数一：hp-----------指向结构体对象的指针*/
void HeapPrint(Heap* hp);