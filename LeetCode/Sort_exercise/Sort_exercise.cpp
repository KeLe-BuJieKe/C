#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using  namespace std;
/*
912. ��������
����һ���������� nums�����㽫�������������С�
ʾ�� 1��
���룺nums = [5,2,3,1]
�����[1,2,3,5]

ʾ�� 2��
���룺nums = [5,1,1,2,0,0]
�����[0,0,1,1,2,5]
��ʾ��
1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000
*/

/*
//����һ����������
void Swap(int*x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int GetMinIndex(int* array, const int left, const int right)
{
    int mid= (left + right) >> 1;
    if (array[left] < array[mid])
    {
        if (array[mid] < array[right])
        {
            return mid;
        }
        else if(array[left]>array[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
    else
    {
        if (array[mid] > array[right])
        {
            return mid;
        }
        else if (array[left] < array[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}

int partition(int*array,int left,int right)
{
    int mid=GetMinIndex(array,left,right);
    Swap(&array[mid],&array[left]);
    int keyi=left;
    while(left<right)
    {
        while(left<right&&array[right]>=array[keyi])
        {
            right--;
        }
        while(left<right&&array[left]<=array[keyi])
        {
            left++;
        }
        Swap(&array[left],&array[right]);
    }
     Swap(&array[left],&array[keyi]);
     return left;
}

void QucikSort(int *array,int begin,int end)
{
    if(begin>=end)
    {
        return;
    }
    int key=partition(array,begin,end);
    QucikSort(array,begin,key-1);
    QucikSort(array,key+1,end);
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    int *array=(int *)malloc(sizeof(int)*numsSize);
    QucikSort(nums,0,numsSize-1);
    memcpy(array,nums,sizeof(int)*numsSize);
    *returnSize=numsSize;
    return nums;
}
*/