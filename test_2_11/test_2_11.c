#define _CRT_SECURE_NO_WARNINGS 1


//下面的程序，输出结果是多少
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int a = 5;
//	if (a = 0)			//这里把a赋值为0，不是判断a是否等于0，因用==
//	{
//		printf("%d", a - 10);
//	}
//	else
//	{
//		printf("%d", a++);		//先打印a为0，然后在自增
//	}
//	system("pause");
//	return 0;
//}



//有如下代码
//#include<string.h>
//#include<stdio.h>
//int main()
//{
//	char acHello[] = "hello\0world";
//	char acNew[15] = { 0 };
//	strcpy(acNew, acHello);
//
//	/*输出多少*/
//	int len = strlen(acNew);
//	int size = sizeof(acHello);
//	printf("%d %d", len, size);			//len==5   size==12
//	return 0;	
//}



//算法题
//编写函数，求第n个斐波那契数列的值非递归
//#include<stdio.h>
//long long fib(long long n)
//{
//	long long a = 1;
//	long long b = 1;
//	long long c = 1;
//	while(n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n;
//	printf("请输入第想知道几个斐波那契数为：");
//	scanf("%d", &n);
//	printf("%lld\n",fib(n));
//	return 0;
//}



//智力题
/*有50家人家，每家一条狗。有一天警察通知，50条狗当中有病狗，行为和正常狗不一样*/

//后期填坑