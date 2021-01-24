#include<iostream>
using namespace std;
typedef int KeyType;    	//定义关键字类型
typedef struct          	//记录类型
{
    KeyType key;         	//关键字项
}RecType;

//排序的记录类型定义
//直接插入排序
void InsertSort(RecType R[], int n)
{
    //在此处填写直接插入排序算法代码
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = R[i].key;
        for (j = i - 1; j >= 0 && temp < R[j].key; j--)
        {
            R[j + 1].key = R[j].key;
        }
        R[j + 1].key = temp;
    }
}

//希尔排序
void ShellSort(RecType R[], int n)
{
    int d, i, j, temp;
    for (d = n / 2; d >= 1; d = d / 2)
    {
        for (i = d; i < n; i++)
        {
            temp = R[i].key;
            for (j = i - d; j >= 0 && temp < R[j].key; j = j - d)
            {
                R[j + d].key = R[j].key;
            }
            R[j + d].key = temp;
        }
    }
}

int partition(RecType R[], int frist, int last)  //一趟划分
{
    //在此处填写利用快速排序算法进行一趟排序的代码
    int i = frist;   int j = last; int temp;
    while (i < j)
    {
        while (i < j && R[i].key <= R[j].key)      //右侧扫描
        {
            j--;
        }
        if (i < j)
        {
            temp = R[i].key;
            R[i].key = R[j].key;
            R[j].key = temp;
            i++;
        }

        while (i < j && R[i].key <= R[j].key)      //右侧扫描
        {
            i++;
        }
        if (i < j)
        {
            temp = R[i].key;
            R[i].key = R[j].key;
            R[j].key = temp;
            j--;
        }
    }
    return i;
}

//快速排序
void QuickSort(RecType R[], int first, int last)
//对R[frist..last]的元素进行快速排序
{
    if (first >= last)
    {
        return;
    }
    else
    {
        int pivot = partition(R, first, last);
        QuickSort(R, first, pivot - 1);             //对左侧子序列进行快速排序
        QuickSort(R, pivot + 1, last);              //对右边侧子序列进行快速排序
    }
    //在此处填写快速排序算法代码
}

//冒泡排序
void BubbleSort(RecType R[], int n)          //n是数组长度
{
    //在此处填写冒泡排序算法代码
    bool exchange = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (R[j].key > R[j + 1].key)
            {
                int temp = R[j].key;
                R[j].key = R[j + 1].key;
                R[j + 1].key = temp;
                exchange = true;
            }
        }
        if (!exchange)
        {
            return;
        }
    }
}

void output(RecType R[])//输出排序后的结果
{
    for (int i = 0; i < 10; i++)
        cout << R[i].key << "  ";
    cout << endl;
}

void function(int num, RecType R[], int length)
{
    switch (num)
    {
    case 1:
        cout << "调用直接插入排序算法后，关键字序列为:" << endl;
        InsertSort(R, length);
        output(R);
        break;
    case 2:
        cout << "调用直接插入排序算法后，关键字序列为:" << endl;
        ShellSort(R, length);
        output(R);
        break;
    case 3:
        cout << "调用快速排序算法后，关键字序列为:" << endl;
        QuickSort(R, 0, 9);
        output(R);
        break;
    case 4:
        cout << "调用冒泡排序算法后，关键字序列为:" << endl;
        BubbleSort(R, length);
        output(R);
        break;
    default:
        exit(0);
    }
}

int main()
{

    RecType R[10]; int x = 0, i;
    cout << "请输入10个待排序记录的关键字：" << endl;
    for (i = 0; i < 10; i++)
    {
        cin >> R[i].key;
    }
    cout << "请输入1~3的序号，执行相应的排序算法：" << endl;
    cout << "1.直接插入排序" << endl;
    cout << "2.希尔排序" << endl;
    cout << "3.快速排序" << endl;
    cout << "4.冒泡排序" << endl;
    int num;
    int length = sizeof(R) / sizeof(R[0]);
    while (true)
    {
        cin >> num;
        function(num, R, length);
    }
    return 0;
}
