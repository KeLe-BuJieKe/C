#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using  namespace std;


//直接插入排序
void InsertSort(int* array, int size);

//希尔排序
void ShellSort(int* array, int size);

//交换函数
void Swap(int& x, int& y);

//选择排序
void SelectSort(int* array, int size);

//堆排序
void adjustBigHeap(int*array, int parent, const int size);
void HeapSort(int*array, const int size);

//冒泡
void BubbleSort(int* array, const int size);


//三数取中
int GetMinIndex(int* array, const int left, const int right);
//快速排序
//左右指针法
/*思路：
从right右边开始 ，找到一个比key位置的值小的就停止循环
再left从左边开始，找到一个比key位置的值大的就停止循环
再交换left与right位置的值，直到循环结束后
再把left与right的相遇点与keyi位置的值交换
*/
int PartSort1(int* array, int left, int right);
//挖坑法
int PartSort2(int* array, int left, int right);
//前后指针法
/*思路：
cur跟prev开始一前一后
cur去找比key位置小的值
找到小之后，++prev，再交换prev喝cur位置的值
*/
int PartSort3(int* array, int left, int right);
// 快速排序递归实现
void QuickSort(int* array, int begin, int end);

// 快速排序 非递归实现
void QuickSortNonR(int* array, int left, int right);


//归并排序递归实现
void MergeSort(int* array, int size);

//归并排序非递归实现
void _MergeSortNonR(int* array, int* tempArr, int begin1, int end1, int begin2, int end2);

void MergeSortNonR(int* array, int size);

//计数排序
void CountSort(int* array, int size);