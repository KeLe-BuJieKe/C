#pragma once
#include"SeqList.h"

//初始化
void SeqListInit(struct SeqList*ps)
{
	assert(NULL != ps);
	ps->array =(DataType*)malloc(sizeof(DataType)*4);
	if (NULL == ps->array)
	{
		printf("初始化申请内存失败\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

//检查是否要扩容
void SeqListCheckCapacity(struct SeqList*ps)
{
	assert(NULL != ps);
	//如果满了，就需要增容
	if (ps->size == ps->capacity)
	{
		ps->capacity = 2 * ps->capacity;
		DataType* pp = (DataType*)realloc(ps->array, sizeof(DataType) * ps->capacity);
		if (NULL == pp)
		{
			printf("扩容失败\n");
			//粗暴做法
			exit(-1);
		}
		ps->array = pp;
	}
}

//打印数组
void SeqListPrint(const struct SeqList* ps)
{
	assert(NULL != ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%2d ", ps->array[i]);
	}
	printf("\n");
}

//尾插
void SeqListPushBack(struct SeqList* ps, DataType x)
{
	assert(NULL != ps);

	SeqListCheckCapacity(ps);
	ps->array[ps->size] = x;
	ps->size++;
}

//尾删
void SeqListPopBack(struct SeqList* ps)
{
	assert(NULL != ps);
	ps->size--;
}

//头插
void SeqListPushFront(struct SeqList* ps, DataType x)
{
	assert(NULL!= ps);
	SeqListCheckCapacity(ps);
	int i =ps->size-1;
	while (i>=0)
	{
		ps->array[i+1] = ps->array[i];
		i--;
	}
	ps->array[0] = x;
	ps->size++;
}

//头删
void SeqListPopFront(struct SeqList* ps)
{
	assert(NULL != ps);
	for (int i = 0; i < ps->size; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}


//任意位置的插入
void SeqListInsert(struct SeqList* ps, int pos, DataType x)
{
	assert(NULL != ps&&(pos>=1&&pos<=ps->size));
	SeqListCheckCapacity(ps);
	for (int i = ps->size; i>=pos; i--)
	{
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[pos-1] = x;
	ps->size++;
}

//任意位置的删除
void SeqListErase(struct SeqList* ps, int pos)
{
	assert(NULL != ps&&(pos>=1&&pos<ps->size));
	for (int i = pos - 1; i < ps->size-1; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}


//顺序表查找
int SeqListFind(const struct SeqList* ps, DataType x)
{
	assert(NULL != ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}