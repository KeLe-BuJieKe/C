#define _CRT_SECURE_NO_WARNINGS 1


//模拟实现atoi 
//#include<stdio.h>
//#include<limits.h>
//#include<ctype.h>
////特殊情况：
///*
//1.传进来的是空字符串
//2.传进来的是空指针
//*/
//enum State
//{
//	VALID,		//合法的状态
//	NOVALID		//不合法的状态
//};
//
//enum State state = NOVALID;
//
//int  my_atoi(const char*str)
//{
//	//1.传进来的是空字符串
//	if (str == NULL)
//	{
//		return 0;
//	}
//	//2.传进来的是空指针
//	else if (*str == '\0')
//	{
//		return 0;
//	}
//	//3.一进来，前几个字符是空格，则跳过空格
//	while (*str== ' ')
//	{
//		str++;
//	}
//
//	//判断是正数还是负数
//	int flag = 1;
//	if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	else if(*str == '+')
//	{
//		flag = 1;
//		str++;
//	}
//	int num = 0;
//	while (*str!='\0')
//	{
//		//isdigit是一个判断是否是数字的函数
//		if (isdigit(*str))
//		{
//			num = num * 10 + flag*(*str- '0');
//			//判断是否溢出
//			if (num > INT_MAX || num < INT_MIN)
//			{
//				return 0;
//			}
//		}
//		else
//		{
//			return 0;
//		}
//
//		str++;
//	}
//	state = VALID;
//	return num;
//}
////--------------测试代码--------------------
//int main()
//{
//	int ret = my_atoi("0");
//	if (state == VALID)
//	{
//		printf("合法:%d\n", ret);
//	}
//	else
//	{
//		printf("不合法\n");
//	}
//	
//	return 0;
//}




//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。
#include<stdio.h>
#define SWAP(X) (((X&0x55555555)<<1)|(X&0xaaaaaaaa)>>1)

int main()
{
	int temp = SWAP(100);
	//1.把这个数所有的偶数位保留，奇数为0
	//	把得到的数字，向左移动一位
	//2.把这个数所有的奇数位保留，偶数为0
	//  把得到的数字，向右移动一位
	//3.把前面得到的2个数字按位或
	printf("%d\n", temp);
	return 0;
}