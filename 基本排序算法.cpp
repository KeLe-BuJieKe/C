#include<iostream>
using namespace std;
typedef int KeyType;    	//����ؼ�������
typedef struct          	//��¼����
{
    KeyType key;         	//�ؼ�����
}RecType;

//����ļ�¼���Ͷ���
//ֱ�Ӳ�������
void InsertSort(RecType R[], int n)
{
    //�ڴ˴���дֱ�Ӳ��������㷨����
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

//ϣ������
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

int partition(RecType R[], int frist, int last)  //һ�˻���
{
    //�ڴ˴���д���ÿ��������㷨����һ������Ĵ���
    int i = frist;   int j = last; int temp;
    while (i < j)
    {
        while (i < j && R[i].key <= R[j].key)      //�Ҳ�ɨ��
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

        while (i < j && R[i].key <= R[j].key)      //�Ҳ�ɨ��
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

//��������
void QuickSort(RecType R[], int first, int last)
//��R[frist..last]��Ԫ�ؽ��п�������
{
    if (first >= last)
    {
        return;
    }
    else
    {
        int pivot = partition(R, first, last);
        QuickSort(R, first, pivot - 1);             //����������н��п�������
        QuickSort(R, pivot + 1, last);              //���ұ߲������н��п�������
    }
    //�ڴ˴���д���������㷨����
}

//ð������
void BubbleSort(RecType R[], int n)          //n�����鳤��
{
    //�ڴ˴���дð�������㷨����
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

void output(RecType R[])//��������Ľ��
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
        cout << "����ֱ�Ӳ��������㷨�󣬹ؼ�������Ϊ:" << endl;
        InsertSort(R, length);
        output(R);
        break;
    case 2:
        cout << "����ֱ�Ӳ��������㷨�󣬹ؼ�������Ϊ:" << endl;
        ShellSort(R, length);
        output(R);
        break;
    case 3:
        cout << "���ÿ��������㷨�󣬹ؼ�������Ϊ:" << endl;
        QuickSort(R, 0, 9);
        output(R);
        break;
    case 4:
        cout << "����ð�������㷨�󣬹ؼ�������Ϊ:" << endl;
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
    cout << "������10���������¼�Ĺؼ��֣�" << endl;
    for (i = 0; i < 10; i++)
    {
        cin >> R[i].key;
    }
    cout << "������1~3����ţ�ִ����Ӧ�������㷨��" << endl;
    cout << "1.ֱ�Ӳ�������" << endl;
    cout << "2.ϣ������" << endl;
    cout << "3.��������" << endl;
    cout << "4.ð������" << endl;
    int num;
    int length = sizeof(R) / sizeof(R[0]);
    while (true)
    {
        cin >> num;
        function(num, R, length);
    }
    return 0;
}
