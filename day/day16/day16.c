#define _CRT_SECURE_NO_WARNINGS 1


//1.下面的代码执行后，sht的值是
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	unsigned short sht = 0;
//	sht--;
//	//sht是无符号短整型，它不可能为负值，-1在内存中的补码为全1，因为是short类型，只含有16个1
//	//在打印的时，由于要打印有符号整形，则要发生整形提升，前面补充符号位，又因为它是无符号数，直接补充0
//	//0000 0000 0000 0000 1111 1111 1111 1111 
//	printf("%d\n", sht);	//65535
//	system("pause");
//	return 0;
//}



//2.如下代码输出的结果是
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int* prr = (&arr + 1);	//&arr取出整个数组的地址+1，直接跳过整个数组，指向5元素后面的元素
//	//arr+1，这里的arr是首元素的地址+1，此时指向2这个元素的地址
//	printf("%d %d\n", *(arr + 1), *(prr - 1));		//2			5
//	return 0;	
//}



//3.计算下列表达式
//#include<stdio.h>
//int main()
//{
//	printf("%c\n", 'B' + '8' - '3');	//G
//	return 0;
//}



//算法题
/*模拟实现函数pow(x,y),即实现运算x^y(x的y次方)，这里x和y都为整数*/
//#include<stdio.h>
//double my_pow(double x, double y)
//{
//	if (x == 0.0||x==1.0)
//	{
//		return x;
//	}
//	else if (y == 0.0)
//	{
//		return 1.0;
//	}
//	double result = 1.0;
//	if (y > 0)
//	{
//		while (y--)
//		{
//			result *= x;
//		}
//	}
//	else
//	{
//		while (y++<0)
//		{
//			result *= (1.0/x);
//		}
//	}
//	return result;
//}
////------------测试代码-------------
//int main()
//{
//	double temp=my_pow(1,5);
//	printf("%lf\n", temp);
//	return 0;
//}




//智力题
/*1000!有几位数，为什么？*/
/*解析：用科学计数法表示 b = a * 10^X，其中 1 < a <10，x 为整数，则 b 有 a + Y 位数
比如：1509=1.509 * 10^3，则 1509 有 1 + 3（Y） = 4 位数。
当 1 < a <10，0 < lg(a) < 1，即 lg（a * 10^X）= lg（a）+ X  的整数部分就是 Y
那么求 1000！有几位数就转化为求 lg（1000！）+ 1
lg（1000！）= lg（1000 * 999 *……*1）= lg（1000）+ lg（999）+ ……+ lg（1）
（为保证 1000 个小数相加数值精确，采用 floatdouble也可以存储结果若使用int会导致结果偏差较大）
*/
//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//int main() 
//{
//	int a = 0;
//	double num = 0.0;
//	scanf("%d", &a);
//	for (int i = 1; i <= a; i++) 
//	{
//		//求多个数相乘的位数只要求它的常用对数和就可以。
//		num += log10(i);
//	}
//	printf("%d\n", (int)num + 1);		//2568位
//	system("pause");
//	return 0;
//}