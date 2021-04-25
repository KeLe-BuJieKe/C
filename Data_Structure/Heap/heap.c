#include"heap.h"


void swap(HPDataType* x, HPDataType* y)
{
	HPDataType temp = *x;
	*x = *y;
	*y = temp;
}


//����Ϊ���
void adjustBigHeap(HPDataType* array, int parent, int size)
{
	int child = parent * 2 + 1;
	while (child < size)
	{

		//ѡ�����Һ����д���Ǹ�����
		if (child+1<size&&array[child]<array[child + 1])
		{
			++child;
		}

		//�ж�ѡ�����Ǹ���ĺ����Ƿ�ȸ��״�������򽻻�
		if (array[child] > array[parent])
		{
			swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//�����ӽ��ȸ���С�����˳�
		else
		{
			break;
		}
	}
}

//����ΪС��
void adjustSmallHeap(HPDataType* array, int parent, int size)
{
	int child = parent * 2 + 1;
	while (child < size)
	{

		//ѡ�����Һ�����С���Ǹ�����
		if (child + 1 < size && array[child] > array[child + 1])
		{
			++child;
		}

		//�ж�ѡ�����Ǹ�С�ĺ����Ƿ�ȸ���С�����С�򽻻�
		if (array[child] < array[parent])
		{
			swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//�����ӽ��ȸ���С�����˳�
		else
		{
			break;
		}
	}
}

//����ʱ���ϵ���
void adjustUp(HPDataType* array, int child)
{
	int parent = (child - 1) / 2;
	while (child>=0)
	{
		if (array[child] > array[parent])
		{
			swap(&array[child], &array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


void heapSort(HPDataType* array, int size)
{
	for (int i = (size - 1) / 2; i >= 0; i--)
	{
		//�����һ����֧�������������
		adjustBigHeap(array, i, size);
	}

	int end = size-1;
	while(end >0)
	{

		swap(&array[0], &array[end]);
		adjustBigHeap(array, 0, end);
		--end;
	}
}


void HeapInit(Heap* hp, HPDataType* array, int size)
{
	if (array == NULL || size == 0)
	{
		return;
	}

	hp->_array =(HPDataType*)malloc(sizeof(HPDataType)*size);
	if (hp->_array == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}

	//�Ѵ����������鸳ֵ�����е�����
	memcpy(hp->_array, array, sizeof(HPDataType)*size);
	hp->_capacity = size;
	hp->_size = size;


	//�Ѹ��������Ϊ��
	for (int i = (size - 1) / 2; i >= 0; i--)
	{
		//�����һ����֧�������������
		adjustBigHeap(hp->_array, i, size);
	}

}

void HeapDestory(Heap* hp)
{
	if (hp->_array == NULL)
	{
		return;
	}
	free(hp->_array);
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

void HeapPush(Heap* hp, HPDataType x)
{
	if (hp == NULL)
	{
		printf("��Ϊ��\n");
		return;
	}
	//�ж��Ƿ���������������Ҫ����
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		HPDataType* temp = realloc(hp->_array, hp->_capacity * sizeof(HPDataType));
		if (temp == NULL)
		{
			printf("relloc error\n");
			exit(-1);
		}
		hp->_array = temp;
	}
	hp->_array[hp->_size] = x;
	hp->_size++;
	adjustUp(hp->_array, hp->_size-1);
}


//ɾ���Ѷ�Ԫ��
void HeapPop(Heap* hp)
{
	//��sizeΪ0ʱ���������������Ԫ��
	if (hp->_size<0)
	{
		printf("���ѿգ�����ɾ��\n");
		return;
	}
	//�öѶ���ѵ׽��н�����������֮���öѴ�С������
	swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;
	adjustBigHeap(hp->_array, 0, hp->_size - 1);


}

HPDataType HeapTop(Heap* hp)
{
	if (hp->_size < 0||hp->_array==NULL)
	{
		return;		//���Ϊ�գ�����һ�����ֵ
	}
	return hp->_array[0];
}

int HeapSize(Heap* hp)
{
	if (hp->_array == NULL)
	{
		return -1;	
	}
	return hp->_size;
}

bool HeapEmpty(Heap* hp)
{
	if (hp->_array== NULL)
	{
		return false;
	}
	return hp->_size == 0;
}

void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d  ", hp->_array[i]);
	}
	printf("\n");

	int num = 1;
	int i = 0;
	while (num < hp->_size)
	{
		for (int j = 0; j <num&&i< hp->_size; j++)
		{
			printf("%d   ", hp->_array[i++]);
			
		}
		num*=2;
		printf("\n");
	}
	printf("\n");

}
