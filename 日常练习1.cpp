#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdio.h>
#include<time.h>

//判断100-200之间的素数
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

//编写函数不允许创建临时变量，求字符串的长度

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
	bool sign = true;      // 假设这一趟要排序的数据已经有序
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				sign = false;       //当sign为false时，则证明本趟排序的数据不完全有序
			}
		}
		//当这一趟要排序的数据没有一次交换时，就说明有序，则跳出循环
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
	//1.判断100-200之间的素数
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

	//2.链式访问
	//由于printf范围类型为int型，返回的是打印的字符个数
	//printf("%d", printf("%d", printf("%d", 43)));   //输出结果4321

	//3.编写函数不允许创建临时变量，求字符串的长度
	//char arr[] = { "bit" };
	////arr是数组，传参过去传过去的是第一个元素的地址，不是整个数组
	//cout << "长度为："<<my_strlen(arr) << endl;


	//递归的俩个条件 
	//（1）存在限制条件，当满足这个限制条件的时候，递归不在继续
	//(2)每次递归调用之后越来越接近这个限制条件
	//4.求第n个斐波那契数
	//方法1,递归方式
	//int n1;
	//cin >> n1; 
	////递归方式
	//int ret1=fib1(n1);
	//cout << "第" << n1 << "个斐波那契数为" << ret1 << endl;
	//此题用递归方式求，当n的数字过大时，时间效率低，所以不建议使用递归，应用循环
	//方法2,循环方式
	//long  n2;
	//cin >> n2;
	//long ret2 = fib2(n2);
	//cout << "第" << n2 << "个斐波那契数为" << ret2 << endl;


	//5.冒泡排序
	//int arr[] = {10,9,8,7,6,5,4,3,2,1,0};

	//int len = sizeof(arr) / sizeof(arr[0]);
	//bubble_sort(arr, len);

	//6.输出100以内能被3整除且个位数为6的所有整数
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

	//7.摄氏温度与华氏温度的转换
	/*\
	（1）华氏温度转为摄氏温度
	int c, f;
	cin >> f;
	c = (5 / 9.0) * (f - 32);
	cout << c;*/

	/*(2)摄氏温度转为华氏温度*/
	/*int c, f;
	cin >> c;
	f = (9 / 5.0) * c + 32;
	cout << f;*/

	//8.用三目运算符求3个数x、y、z的最大值
	//int x, y, z;
	//cin >> x >> y >> z;
	//max(x, y, z);
	return 0;
}