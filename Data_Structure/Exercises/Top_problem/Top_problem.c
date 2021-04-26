#define _CRT_SECURE_NO_WARNINGS 1
/*
剑指 Offer 40. 最小的k个数
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]

限制：
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
*/

/*
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


//调整为大堆
void adjustBigHeap(int* array, int parent, int size)
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

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
    //0 <= k <= arr.length <= 10000，k是大于0的，故我们只需要判断等于0时的特殊情况
    if(k==0)
    {
        *returnSize=k;
        return NULL;
    }

     //思路
    //1.先把数组中前K个数据，构成大堆
    //2.然后剩下的N-K个数，与堆顶的数据比较，如果比堆顶的数据要小，则替换堆顶，继续调整为大堆
    int*tempArray=(int *)malloc(sizeof(int)*k);


    //把数组中的前k个数赋给开辟的数组
    for(int i=0;i<k;i++)
    {
        tempArray[i]=arr[i];
    }

    //将开辟的数组构建成大堆，从最后一个分支结点开始
    for(int j=(k-1)/2;j>=0;--j)
    {
        adjustBigHeap(tempArray,j,k);
    }

    //剩下的N-K个数与堆顶的数据比较，如果比堆顶的数据要小，则替换堆顶，继续调整为大堆
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