#define _CRT_SECURE_NO_WARNINGS 1
/*
��ָ Offer 40. ��С��k����
������������ arr ���ҳ�������С�� k ���������磬����4��5��1��6��2��7��3��8��8�����֣�����С��4��������1��2��3��4��
ʾ�� 1��
���룺arr = [3,2,1], k = 2
�����[1,2] ���� [2,1]

ʾ�� 2��
���룺arr = [0,1,2,1], k = 1
�����[0]

���ƣ�
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
���ӣ�https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
*/

/*
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


//����Ϊ���
void adjustBigHeap(int* array, int parent, int size)
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

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
    //0 <= k <= arr.length <= 10000��k�Ǵ���0�ģ�������ֻ��Ҫ�жϵ���0ʱ���������
    if(k==0)
    {
        *returnSize=k;
        return NULL;
    }

     //˼·
    //1.�Ȱ�������ǰK�����ݣ����ɴ��
    //2.Ȼ��ʣ�µ�N-K��������Ѷ������ݱȽϣ�����ȶѶ�������ҪС�����滻�Ѷ�����������Ϊ���
    int*tempArray=(int *)malloc(sizeof(int)*k);


    //�������е�ǰk�����������ٵ�����
    for(int i=0;i<k;i++)
    {
        tempArray[i]=arr[i];
    }

    //�����ٵ����鹹���ɴ�ѣ������һ����֧��㿪ʼ
    for(int j=(k-1)/2;j>=0;--j)
    {
        adjustBigHeap(tempArray,j,k);
    }

    //ʣ�µ�N-K������Ѷ������ݱȽϣ�����ȶѶ�������ҪС�����滻�Ѷ�����������Ϊ���
    for(int i=k;i<arrSize;i++)
    {
        if(tempArray[0]>arr[i])
        {
            tempArray[0]=arr[i];
            adjustBigHeap(tempArray,0,k);
        }
    }
    *returnSize=k;
    return tempArray;
}
*/