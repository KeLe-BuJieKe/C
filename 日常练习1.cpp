#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdio.h>
#include<time.h>

//�ж�100-200֮�������
int is_prime(int i)
{
	int j = 0;
	for (j = 2; j < i; j++)
	{

		if (i % j == 0)
		{
			return 0;
		}
	}
	if (i == j)
	{
		return 1;
	}

}

//��д��������������ʱ���������ַ����ĳ���

int my_strlen(const char* str)
{
	if (*str != '\0')
	{
		return 1 + my_strlen(str + 1);
	}
	else
	{
		return 0;
	}
}

// 1 1 2 3 5 8 13 21 34 55
int fib1(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return fib1(n - 1) + fib1(n - 2);
	}
}

long fib2(long n)
{
	long a = 1, b = 1, c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

void bubble_sort(int arr[], int len)
{
	int i = 0, j = 0;
	bool sign = true;      // ������һ��Ҫ����������Ѿ�����
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				sign = false;       //��signΪfalseʱ����֤��������������ݲ���ȫ����
			}
		}
		//����һ��Ҫ���������û��һ�ν���ʱ����˵������������ѭ��
		if (sign == true)
		{
			break;
		}
	}
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "  ";
	}

}

void max(int x, int y, int z)
{
	int max = x >= y && x >= z ? x : (y >= z && y >= x ? y : z);
	cout << max;
}

int main()
{
	//1.�ж�100-200֮�������
	//int i = 0;
	//int count = 0;
	//for (i = 100; i <= 200; i++)
	//{
	//	if (is_prime(i) == 1)
	//	{
	//		printf("%d", i);
	//		count++;
	//		cout << endl;
	//	}
	//	
	//}
	//cout << count;

	//2.��ʽ����
	//����printf��Χ����Ϊint�ͣ����ص��Ǵ�ӡ���ַ�����
	//printf("%d", printf("%d", printf("%d", 43)));   //������4321

	//3.��д��������������ʱ���������ַ����ĳ���
	//char arr[] = { "bit" };
	////arr�����飬���ι�ȥ����ȥ���ǵ�һ��Ԫ�صĵ�ַ��������������
	//cout << "����Ϊ��"<<my_strlen(arr) << endl;


	//�ݹ���������� 
	//��1�����������������������������������ʱ�򣬵ݹ鲻�ڼ���
	//(2)ÿ�εݹ����֮��Խ��Խ�ӽ������������
	//4.���n��쳲�������
	//����1,�ݹ鷽ʽ
	//int n1;
	//cin >> n1; 
	////�ݹ鷽ʽ
	//int ret1=fib1(n1);
	//cout << "��" << n1 << "��쳲�������Ϊ" << ret1 << endl;
	//�����õݹ鷽ʽ�󣬵�n�����ֹ���ʱ��ʱ��Ч�ʵͣ����Բ�����ʹ�õݹ飬Ӧ��ѭ��
	//����2,ѭ����ʽ
	//long  n2;
	//cin >> n2;
	//long ret2 = fib2(n2);
	//cout << "��" << n2 << "��쳲�������Ϊ" << ret2 << endl;


	//5.ð������
	//int arr[] = {10,9,8,7,6,5,4,3,2,1,0};

	//int len = sizeof(arr) / sizeof(arr[0]);
	//bubble_sort(arr, len);

	//6.���100�����ܱ�3�����Ҹ�λ��Ϊ6����������
	//int i, j;
	//for (i = 0; i < 10; i++)
	//{
	//	j = i * 10 + 6;
	//	if (j % 3 != 0)
	//	{
	//		continue;
	//	}
	//	cout << j << endl;;
	//}

	//7.�����¶��뻪���¶ȵ�ת��
	/*\
	��1�������¶�תΪ�����¶�
	int c, f;
	cin >> f;
	c = (5 / 9.0) * (f - 32);
	cout << c;*/

	/*(2)�����¶�תΪ�����¶�*/
	/*int c, f;
	cin >> c;
	f = (9 / 5.0) * c + 32;
	cout << f;*/

	//8.����Ŀ�������3����x��y��z�����ֵ
	//int x, y, z;
	//cin >> x >> y >> z;
	//max(x, y, z);
	return 0;
}