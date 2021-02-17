#define _CRT_SECURE_NO_WARNINGS 1


//下面程序执行后，n的值等于？
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char a[20];
//	char* p1 = (char*)a;
//	char* p2 = (char*)(a + 5);
//	int  n = p2 - p1;
//	printf("%d", n);			//n==5
//	system("pause");
//	return 0;
//}



//下面程序执行后，输出的值结果为？
//#include<stdio.h>
//#pragma pack(4)
//int main()
//{
//	struct t1
//	{
//		short a;
//		char d;
//		long b;
//		long c;
//	};
//	struct t2
//	{
//		long b;
//		short c;
//		char d;
//		long a;
//	};
//	struct t3
//	{
//		short c;
//		long b;
//		char d;
//		long a;
//	};
//	struct t1 t1;
//	struct t2 t2;
//	struct t3 t3;
//	//					  12		  12		  16
//	printf("%d %d %d", sizeof(t1), sizeof(t2), sizeof(t3));
//	return 0；
//}
//#pragma pack()



//算法题
/*写一个函数求unsigned int型变量x在内存中二进制1的个数*/
#include<stdio.h>
int find_1(size_t x)
{
	int count = 0;
	while (x)
	{
		x=x&(x - 1);
		count++;
	}
	return count;
}

/*---------------------测试代码-----------------------*/
int main()
{
	size_t x;
	scanf("%d", &x);
	printf("%d",find_1(x));
	return 0;
}



//智力题
//用数字5，5，5，1，进行四则运算，每个数字当且仅当用一次，要求运算结果值为24
/*  
5*(5-1/5)=24
*/