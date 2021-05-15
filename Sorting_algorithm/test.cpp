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
	int array[] = { 9,8,7,6,5,4,3,2,1,0};
	int size = sizeof(array) / sizeof(array[0]);
	InsertSort(array, size);
	printf(array, size);
}


void testShellSort()
{
	int array[] = { 9,8,7,6,5,4,3,2,1,0};
	int size = sizeof(array) / sizeof(array[0]);

	ShellSort(array, size);
	printf(array, size);
}


void testSelectSort()
{
	int array[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(array) / sizeof(array[0]);
	SelectSort(array, size);
	printf(array, size);
}

void testHeapSort()
{
	int array[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(array) / sizeof(array[0]);
	HeapSort(array, size);
	printf(array, size);
}


void testBubbleSort()
{
	int array[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(array) / sizeof(array[0]);
	BubbleSort(array, size);
	printf(array, size);
}


void testQuickSort()
{
	int array[] = { 9,2,0,6,4,5,3,8,1,7,9,2,0,6,4,5,3,8,1,7 ,9,2,0,6,4,5,3,8,1,7 };
	int size = sizeof(array) / sizeof(array[0]);
	QuickSort(array,0, size-1);
	//QuickSortNonR(array, 0, size - 1);
	printf(array, size);

}

void testMergeSort()
{
	int array[] = { 9,1,4,8,4,3,2,5,7};
	int size = sizeof(array) / sizeof(array[0]);
	//MergeSort(array, size);
	MergeSortNonR(array, size);
	printf(array, size);
}

void testCountSort()
{
	int array[] = { 9,1,4,8,4,3,2,5,7,2,7,9,8,5 };
	int size = sizeof(array) / sizeof(array[0]);
	CountSort(array, size);
	printf(array, size);

}
int main()
{
	//testInsertSort();
	//testShellSort();
	//testSelectSort();
	//testHeapSort();
	//testBubbleSort();
	//testQuickSort();
	//testMergeSort();
	testCountSort();
	system("pause");
	return 0;
}