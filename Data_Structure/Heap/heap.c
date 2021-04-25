#include"heap.h"


void swap(HPDataType* x, HPDataType* y)
{
	HPDataType temp = *x;
	*x = *y;
	*y = temp;
}


//调整为大堆
void adjustBigHeap(HPDataType* array, int parent, int size)
{
	int child = parent * 2 + 1;
	while (child < size)
	{

		//选出左右孩子中大的那个孩子
		if (child+1<size&&array[child]<array[child + 1])
		{
			++child;
		}

		//判断选出的那个大的孩子是否比父亲大，如果大则交换
		if (array[child] > array[parent])
		{
			swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//当孩子结点比父亲小，则退出
		else
		{
			break;
		}
	}
}

//调整为小堆
void adjustSmallHeap(HPDataType* array, int parent, int size)
{
	int child = parent * 2 + 1;
	while (child < size)
	{

		//选出左右孩子中小的那个孩子
		if (child + 1 < size && array[child] > array[child + 1])
		{
			++child;
		}

		//判断选出的那个小的孩子是否比父亲小，如果小则交换
		if (array[child] < array[parent])
		{
			swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//当孩子结点比父亲小，则退出
		else
		{
			break;
		}
	}
}

//插入时向上调整
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
		//从最后一个分支结点至根结点调整
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

	//把传进来的数组赋值给堆中的数组
	memcpy(hp->_array, array, sizeof(HPDataType)*size);
	hp->_capacity = size;
	hp->_size = size;


	//把该数组调整为堆
	for (int i = (size - 1) / 2; i >= 0; i--)
	{
		//从最后一个分支结点至根结点调整
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
		printf("堆为空\n");
		return;
	}
	//判断是否已满，满了则需要扩容
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


//删除堆顶元素
void HeapPop(Heap* hp)
{
	//当size为0时，则表明堆中已无元素
	if (hp->_size<0)
	{
		printf("堆已空，不能删除\n");
		return;
	}
	//让堆顶与堆底进行交换，交换完之后让堆从小构建堆
	swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;
	adjustBigHeap(hp->_array, 0, hp->_size - 1);


}

HPDataType HeapTop(Heap* hp)
{
	if (hp->_size < 0||hp->_array==NULL)
	{
		return;		//如果为空，返回一个随机值
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
