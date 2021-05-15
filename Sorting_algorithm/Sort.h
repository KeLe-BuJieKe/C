#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using  namespace std;


//ֱ�Ӳ�������
void InsertSort(int* array, int size);

//ϣ������
void ShellSort(int* array, int size);

//��������
void Swap(int& x, int& y);

//ѡ������
void SelectSort(int* array, int size);

//������
void adjustBigHeap(int*array, int parent, const int size);
void HeapSort(int*array, const int size);

//ð��
void BubbleSort(int* array, const int size);


//����ȡ��
int GetMinIndex(int* array, const int left, const int right);
//��������
//����ָ�뷨
/*˼·��
��right�ұ߿�ʼ ���ҵ�һ����keyλ�õ�ֵС�ľ�ֹͣѭ��
��left����߿�ʼ���ҵ�һ����keyλ�õ�ֵ��ľ�ֹͣѭ��
�ٽ���left��rightλ�õ�ֵ��ֱ��ѭ��������
�ٰ�left��right����������keyiλ�õ�ֵ����
*/
int PartSort1(int* array, int left, int right);
//�ڿӷ�
int PartSort2(int* array, int left, int right);
//ǰ��ָ�뷨
/*˼·��
cur��prev��ʼһǰһ��
curȥ�ұ�keyλ��С��ֵ
�ҵ�С֮��++prev���ٽ���prev��curλ�õ�ֵ
*/
int PartSort3(int* array, int left, int right);
// ��������ݹ�ʵ��
void QuickSort(int* array, int begin, int end);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* array, int left, int right);


//�鲢����ݹ�ʵ��
void MergeSort(int* array, int size);

//�鲢����ǵݹ�ʵ��
void _MergeSortNonR(int* array, int* tempArr, int begin1, int end1, int begin2, int end2);

void MergeSortNonR(int* array, int size);

//��������
void CountSort(int* array, int size);