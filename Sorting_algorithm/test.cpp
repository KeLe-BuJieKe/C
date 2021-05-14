#include"Sort.h"

void printf(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
}
void testInsertSort()
{
	int array[10] = { 9,8,7,6,5,4,3,2,1,0};
	int size = sizeof(array) / sizeof(array[0]);
	InsertSort(array, size);
	printf(array, size);
}


void testShellSort()
{
	int array[10] = { 9,8,7,6,5,4,3,2,1,0};
	int size = sizeof(array) / sizeof(array[0]);

	ShellSort(array, size);
	printf(array, size);
}


void testSelectSort()
{
	int array[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(array) / sizeof(array[0]);
	SelectSort(array, size);
	printf(array, size);
}

void testHeapSort()
{
	int array[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(array) / sizeof(array[0]);
	HeapSort(array, size);
	printf(array, size);
}


void testBubbleSort()
{
	int array[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(array) / sizeof(array[0]);
	BubbleSort(array, size);
	printf(array, size);
}


void testQuickSort()
{
	int array[10] = { 9,2,0,6,4,5,3,8,1,7 };
	int size = sizeof(array) / sizeof(array[0]);
	QuickSort(array,0, size-1);
	printf(array, size);

}
int main()
{
	//testInsertSort();
	//testShellSort();
	//testSelectSort();
	//testHeapSort();
	//testBubbleSort();
	testQuickSort();
	system("pause");
	return 0;
}