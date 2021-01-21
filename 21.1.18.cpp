#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdio.h>
#include<time.h>
#include<math.h>
//汉诺塔问题
void move(char c1, char c2)
{
	static int count = 1;
	cout << count << "." << c1 << "->" << c2 << endl;
	count++;
}
void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
	{
		move(x, z);
	}
	else
	{
		hanoi(n - 1, x, z, y);
		move(x, z);
		hanoi(n - 1, y, x, z);
	}

}

void swap1(int& a, int& b)
{
	//这种当数字过大时，会造成溢出
	a = a + b;
	b = a - b;
	a = a - b;
}

void swap2(int& a, int& b)
{
	//a和b按位异或   例如a为1---相当于001   b为2---相当于010  相同为0，相异为1
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//判断三角形的类型
void iftge()
{
	int  a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) != EOF)
	{
		if (a + b > c && a + c > b && c + b > a)
		{
			if (a == b && b == c)
			{
				printf("Equilateral triangle!\n"); //等边
			}
			else if ((a == b && b != c) || (a == c && c != b) || (b == c && c != a))
			{
				printf("Isosceles triangle!\n");//等腰
			}
			else
			{
				printf("Ordinary triangle!\n");//普通
			}
		}
		else
		{
			//不是
			printf("Not a triangle!\n");
		}
	}

}

int max(int x, int y)
{
	return x > y ? x : y;
}

//求1-N内有几个偶数，几个奇数
void base_evennumber()
{
	int N;
	int base = 0;
	int evennumber = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		if (i % 2 != 0)
		{
			base++;
		}
		else
		{
			evennumber++;
		}
	}
	printf("奇数个数为：%d 偶数个数为：%d", base, evennumber);
}

//求三角形的周长和面积
void area_per()
{
	int a = 0, b = 0, c = 0;
	scanf("%d%d%d", &a, &b, &c);
	float len = a + b + c;
	float p = (a + b + c) / 2.0;
	float area = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("circumference=%.2f area=%.2f", len, area);
}

//6
void max_min(int a, int b, int c)
{
	if (a < b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	if (a < c)
	{
		a = a ^ c;
		c = a ^ c;
		a = a ^ c;
	}
	if (b < c)
	{
		b = b ^ c;
		c = b ^ c;
		b = b ^ c;
	}
	printf("max=%d second=%d min=%d", a, b, c);
}

void Common_divisor(int a, int b)
{
	int temp = 0;
	while (a % b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	if (a == b)    //如果a与b相等，那么它们本身就是最大公约数
	{
		goto again;
	}
again:	printf("最大公约数=%d", b);
}

void _9num()
{
	int count = 0;
	int a = 100;
	while (a--)
	{
		if (a % 10 == 9)
		{
			count++;
		}
		if (a / 10 == 9)
		{
			count++;
		}
	}
	printf("9的个数为：%d", count);
}

void _3_multiple()
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			printf("%d ", i);
		}
	}
}

void _max(int arr[], int len)
{
	int max = arr[0];   //先把数组的第一个元素当成最大值
	for (int i = 0; i < len; i++)
	{
		if (arr[0] < arr[i])
		{
			max = arr[i];
		}
	}
	printf("最大值为：%d", max);
}

void _99multiplication()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d\t", i, j, i * j);
		}
		printf("\n");
	}
}

void leap_year()
{
	//判断闰年
	//1.能被4整除并且不能被100整除是闰年
	//2.能被400整除是闰年
	int count = 0;
	int i = 0;
	for (i = 1000; i < 2000; i++)
	{
		if (i % 4 == 0 && i % 100 != 0)
		{
			count++;
			printf("%d ", i);
		}
		else if (i % 400 == 0)
		{
			count++;
			printf("%d ", i);
		}
	}
	printf("总数为：%d", count);
}

void prime_number()
{
	int count = 0;
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		int j = 0;
		//sqrt()是一个数学库函数     头文件math.h
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i) && i != 1)
		{
			count++;
			printf("%d\n", i);
		}
	}
	printf("一共共有%d个素数\n", count);
}

void fraction_sum()
{
	float sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 != 0)
		{
			sum = sum + 1.0 / i;
		}
		else
		{
			sum = sum - 1.0 / i;
		}
	}
	printf("%f", sum);
}

void Half_search(int arr[], int len, int X)
{
	int i = 0;
	int j = len - 1;
	while (i <= j)
	{
		int mid = i+(j-i)/2;
		if (X > arr[mid])
		{
			i = mid + 1;
		}
		else if (X < arr[mid])
		{
			j = mid - 1;
		}
		else
		{
			printf("找到了下标为：%d", mid);
			break;
		}
	}
	if (j < i)
	{
		printf("没找到");
	}
}
int main()
{
	//1.汉诺塔问题
		/*
		hanoi问题
		问题描述：1.有三根杆子X,Y,Z,X杆上有n只碟子
				  2.每次移动 一块碟子，小的只能叠在大的上面
				  3.把所有碟子从X杆经Y杆全部移到Z杆上
		递归求解：1.若只有一个碟子，直接将它从X杆移动到Z杆
				  2.
				  (1)把n-1只碟子按大小递减的次序从X杆经Z杆移动到Y杆；
				  (2)将X杆上第n只碟子移动到Z杆；
				  (3)然后再将n-1只碟子按大小递减的次序从Y杆经X杆移动到Z杆
		*/
		//int n;
		//cout << "请输入多少个碟子" << endl;
		//cin >> n;
		//hanoi(n, 'a', 'b', 'c');

		//2.不使用第三个参数让数据交换
		//int a, b;
		//cin >> a >> b;
		//swap2(a, b);
		//swap1(a, b);
		//cout << "a=" << a << "  b=" << b;

		//3.求俩个数中的最大值
		//int a=0, b=0;
		//scanf("%d%d", &a, &b); 
		//printf("%d", max(a, b));

		//4.想知道已经给出的三条边a，b，c能否构成三角形，如果能构成三角形，判断三角形的类型（等边三角形、等腰三角形或普通三角形）。
		//iftge();

		//5.任意输入一个正整数N，统计1~N之间奇数的个数和偶数的个数，并输出。
		//一行，一个正整数N。（1≤N≤100,000）
		//一行，1~N之间奇数的个数和偶数的个数，用空格分开。
		//base_evennumber();

		//6.写代码将三个数按从大到小输出
		//int a, b, c;
		//scanf("%d%d%d", &a, &b, &c);
		//max_min(a,b,c);

		//7.给定两个数，求这两个数的最大公约数
		//int a,b;
		//scanf("%d%d", &a, &b);
		//Common_divisor(a, b);

		//8.编写程序数一下1到100的所有整数中出现多少个数字9
		//_9num();

		//9.写一个代码打印1-100之间所有3的倍数的数字
		/*_3_multiple();*/

		//10.求10个整数中最大值
		//int arr[10];
		//for (int i = 0; i < 10; i++)
		//{
		//	scanf("%d", &arr[i]);
		//}
		//int len = sizeof arr /sizeof arr[0];
		//_max(arr,len);

		//11.在屏幕上输出9*9乘法口诀表
		/*_99multiplication();*/

		//12.打印1000年到2000年之间的闰年
		//leap_year();


		//13.写一个代码：打印100~200之间的素数
		//prime_number();


		//14.计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
		/*fraction_sum();*/


		//15.编写代码在一个整形有序数组中查找具体的某个数
		//要求：找到了就打印数字所在的下标，找不到则输出：找不到。
		//int arr[10] = {1,2,3,4,5,6,7,8,9,10};
		//int len = 0;
		//len = sizeof arr / sizeof arr[0];
		//int x;
		//printf("输入您想要查找的数字：");
		//scanf("%d",&x);
		//Half_search(arr,len,x);
	return 0;
}