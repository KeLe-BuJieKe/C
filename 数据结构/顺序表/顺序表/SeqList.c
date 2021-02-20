#pragma once
#include"SeqList.h"

//��ʼ��
void SeqListInit(struct SeqList*ps)
{
	assert(NULL != ps);
	ps->array =(DataType*)malloc(sizeof(DataType)*4);
	if (NULL == ps->array)
	{
		printf("��ʼ�������ڴ�ʧ��\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

//����Ƿ�Ҫ����
void SeqListCheckCapacity(struct SeqList*ps)
{
	assert(NULL != ps);
	//������ˣ�����Ҫ����
	if (ps->size == ps->capacity)
	{
		ps->capacity = 2 * ps->capacity;
		DataType* pp = (DataType*)realloc(ps->array, sizeof(DataType) * ps->capacity);
		if (NULL == pp)
		{
			printf("����ʧ��\n");
			//�ֱ�����
			exit(-1);
		}
		ps->array = pp;
	}
}

//��ӡ����
void SeqListPrint(const struct SeqList* ps)
{
	assert(NULL != ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%2d ", ps->array[i]);
	}
	printf("\n");
}

//β��
void SeqListPushBack(struct SeqList* ps, DataType x)
{
	assert(NULL != ps);

	SeqListCheckCapacity(ps);
	ps->array[ps->size] = x;
	ps->size++;
}

//βɾ
void SeqListPopBack(struct SeqList* ps)
{
	assert(NULL != ps);
	ps->size--;
}

//ͷ��
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

//ͷɾ
void SeqListPopFront(struct SeqList* ps)
{
	assert(NULL != ps);
	for (int i = 0; i < ps->size; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}


//����λ�õĲ���
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

//����λ�õ�ɾ��
void SeqListErase(struct SeqList* ps, int pos)
{
	assert(NULL != ps&&(pos>=1&&pos<ps->size));
	for (int i = pos - 1; i < ps->size-1; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}


//˳������
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