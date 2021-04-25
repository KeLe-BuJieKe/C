#include"heap.h"

int main()
{
	Heap h;
	int arr[] = { 65,37,49,34,27,19,28,25,15,18 };
	int n = sizeof(arr) / sizeof(arr[0]);
	HeapInit(&h,arr,n);
	HeapPrint(&h);

	HeapPush(&h,88);
	//heapSort(h._array, n);
	HeapPrint(&h);

	HeapPop(&h);
	HeapPrint(&h);

	if (HeapEmpty(&h))
	{
		printf("堆中已空，没有元素\n");
	}
	else
	{
		printf("堆不空,元素个数为：%d\n", HeapSize(&h));
	}
	HeapDestory(&h);
	int temp=HeapTop(&h);
	printf("%d", temp);
	return 0;
}