#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>


//判断i是不是素数，是就返回1，不是返回0
int is_prime(int j)
{
	for (int i = 2; i <= sqrt(j); i++)
	{
		if (i % j == 0)
		{
			return 0;
		}
	}
	return 1;
}


//判断闰年
//1.能被4整除并且不能被100整除是闰年
//2.能被400整除是闰年
void leap_year(int i)
{
	int count = 0;

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
	printf("总数为：%d", count);
}


/*1.问题描述：KiKi想获得某年某月有多少天，请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。
输入描述：多组输入，一行有两个整数，分别表示年份和月份，用空格分隔。
输出描述：针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天*/
//int main()
//{
//    int year = 0;
//    int month = 0;
//    while (scanf("%d %d", &year, &month) != EOF)
//    {
//        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//        {
//            if (month == 2)
//            {
//                printf("%d\n", 29);
//            }
//            else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//            {
//                printf("%d\n", 31);
//            }
//            else
//            {
//                printf("%d\n", 30);
//            }
//        }
//        else
//        {
//            if (month == 2)
//            {
//                printf("%d\n", 28);
//            }
//            else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//            {
//                printf("%d\n", 31);
//            }
//            else
//            {
//                printf("%d\n", 30);
//            }
//        }
//    }
//    return 0;
//}



/*2.问题描述：公务员面试现场打分。有7位考官，从键盘输入若干组成绩，每组7个分数（百分制），去掉一个最高分和一个最低分，输出每组的平均成绩。
输入描述：一行，输入7个整数（0~100），代表7个成绩，用空格分隔。
输出描述：一行，输出去掉最高分和最低分的平均成绩，小数点后保留2位，每行输出后换行。*/
//#include<stdio.h>
//int main()
//{
//    float sum = 0;
//    int score[7] = {};
//    for (int i = 0; i < 7; i++)
//    {
//        scanf("%d ", &score[i]);
//        sum += score[i];
//    }
//
//    int min = 100;
//    int max = 0;
//    for (int j = 0; j < 7; j++)
//    {
//        if (max < score[j])
//        {
//            max = score[j];
//        }
//        if (min > score[j])
//        {
//            min = score[j];
//        }
//    }
//    printf("%.2f", (sum - max - min) / 5.0);
//    return 0;
//}



/*3.问题描述：实现一个函数，判断一个数是不是素数。利用上面实现的函数打印100到200之间的素数。*/
//void is_prime(int n, int m)
//{
//	for (int i = n; i <=m; i++)
//	{
//		bool prime = true;
//		for(int j = 2; j < sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				prime = false;
//				break;
//			}
//		}
//		if (true == prime)
//		{
//			printf("%d ", i);
//		}
//	}
//}
//int main()
//{
//	int a1, a2;
//	printf("请输入一个范围：");
//	scanf("%d %d", &a1, &a2);
//	is_prime(a1, a2);
//	return 0;
//}



/*4.问题描述：函数判断闰年*/
//void is_leap(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		printf("%d是闰年", year);
//	}
//	else
//	{
//		printf("%d不是闰年", year);
//	}
//}
//int main()
//{
//	int year = 0;
//	printf("请输入一个年份：");
//	scanf("%d", &year);
//	is_leap(year);
//	return 0;
//}



/*5.问题描述：实现一个函数来交换两个整数的内容*/
//void swap(int*x, int*y)
//{
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//int main()
//{
//	int x=0,y=0;
//	printf("请输入你要交换的数字：\n");
//	scanf("%d%d", &x, &y);
//	printf("交换前x=%d y=%d\n", x, y);
//	swap(&x, &y);
//	printf("交换后x=%d y=%d\n", x, y);
//	return 0;
//}



/*6.问题描述：实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
如：输入9，输出9*9口诀表，输出12，输出12*12的乘法口诀表。*/
//void _99multiplication(int n)
//{
//	for (int i = 1; i<=n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%-2d*%-2d=%-4d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int m;
//	printf("请输入您想要打印多少阶乘法表：\n");
//	scanf("%d", &m);
//	_99multiplication(m);
//}



/*7.问题描述：KiKi今年5岁了，已经能够认识100以内的非负整数，并且并且能够进行 100 以内的非负整数的加法计算。
不过，BoBo老师发现KiKi在进行大于等于100的正整数的计算时，规则如下：
1.只保留该数的最后两位，例如：对KiKi来说1234等价于34；
2.如果计算结果大于等于 100，那么KIKI也仅保留计算结果的最后两位，如果此两位中十位为0，则只保留个位。
例如：45+80 = 25
要求给定非负整数 a和 b，模拟KiKi的运算规则计算出 a+b 的值。
*/
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("%d", (a + b) % 100);
//	return 0;
//}


/*8.问题描述：给定一个浮点数，要求得到该浮点数的个位数。*/
//#include<stdio.h>
//int main()
//{
//	float f = 0;
//	scanf("%f", &f);
//	printf("%d", (int)f % 10);       //通过强转为int型，让它后面的小数消失，然后对10取余得到个位数
//	return 0;
//}



/*9.问题描述：一年约有3.156×107s，要求输入您的年龄，显示该年龄合多少秒。*/
//#include<stdio.h>
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	printf("%lld",(long long)age * 31560000);   //long long的输入、输出格式为lld  由于int型范围过小，强制装换成long long输出
//	return 0;
//}



/*10.问题描述：给定秒数seconds (0< seconds < 100,000,000)，把秒转化成小时、分钟和秒。
输出描述：一行，包含三个整数，依次为输入整数对应的小时数、分钟数和秒数（可能为零），中间用一个空格隔开。*/
//#include<stdio.h>
//int main()
//{
//	int seconds = 0;
//	scanf("%d", &seconds);
//	printf("%d %d %d", seconds / 3600, seconds % 3600 / 60, seconds % 3600 % 60);
//	return 0;
//}


/*11.问题描述：依次输入一个学生的3科成绩，在屏幕上输出该学生的总成绩以及平均成绩。*/
//#include<stdio.h>
//int main()
//{
//	float a = 0, b = 0, c = 0;
//	scanf("%f%f%f", &a, &b, &c);
//	printf("%.2f %.2f", a + b + c, (a + b + c) / 3);
//	return 0;
//}


/*12.问题描述：BMI指数是用体重公斤数除以身高米数平方得出的数字，是目前国际上常用的衡量人体胖瘦程度以及是否健康的一个标准。
输出描述：一行，BMI指数（保留两位小数）。*/
//int main()
//{
//	int height;
//	int weight;
//	scanf("%d%d", &weight, &height);
//	if (height != 0)
//	{
//		float bmi = weight / ((height / 100.00) * (height / 100.00));
//		printf("%.2f", bmi);
//	}
//
//	return 0;
//}


/*13.问题描述：给定一个球体的半径，计算其体积。其中球体体积公式为 V = 4/3*πr3，其中 π= 3.1415926。
输入描述：一行，用浮点数表示的球体的半径。
输出描述：一行，球体的体积，小数点后保留3位。*/
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	const double PI = 3.1415926;
//	float r = 0;
//	scanf("%f", &r);
//	printf("%.3f", 4 / 3.0 * PI * pow(r, 3));
//	return 0;
//}


/*14.问题描述：实现字母的大小写转换。多组输入输出。
输入描述：多组输入，每一行输入大写字母。
输出描述：针对每组输入输出对应的小写字母。*/
//#include<stdio.h>
//int main()
//{
//	char c = '0';
//	while (scanf("%c", &c) != EOF)
//	{
//		getchar();       //消除\n的影响
//		printf("%c\n", c + 32);
//	}
//	return 0;
//}