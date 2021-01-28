#define _CRT_SECURE_NO_WARNINGS 1

/*1.问题描述：程序死循环解释*/
//#include <stdio.h>
//int main()
//{
/*由于局部变量i和ar[10]都存放在内存的栈上，栈区的内存分配是：先使用高位地址处的空间，在使用低位处的空间。
当先创建的是i在创建数组时，只要数组适当的越界就会导致循环变量被数组越界访问，从而循环变量（i）被改变，就会导致死循环
也就是说arr[12]处的地址是用来存放局部变量i的，一旦改为arr[12]=0也就是等于i=0，将从0开始循环继续下一次循环，造成了死循环的现象
*/
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };           
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}


/*2.问题描述：模拟实现库函数strlen*/
//#include<stdio.h>
//int my_strlen(const char* str)
//{
//	int count = 0;
//	while (*str++ != '\0')
//	{
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[10] = "asdsad";
//	printf("%d", my_strlen(arr));
//	return  0;
//}


/*3.问题描述：模拟实现库函数strcpy*/
//#include<stdio.h>
//char* my_strcpy(char *destination,const char *str)
//{
//	char* temp = destination;
//	while (*destination++ = *str++)
//	{
//
//	}
//	return  temp;
//}
//int main()
//{
//	char arr1[20] ="abcdefg";
//	char arr2[20]="abcd123";
//	printf("%s", my_strcpy(arr2,arr1));
//	return 0;
//}


/*4.作业标题：调整数组使奇数全部都位于偶数前面。
题目：输入一个整数数组，实现一个函数，
来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
所有偶数位于数组的后半部分。*/
//#include<stdio.h>
//void Adjust_array(int *arr,int len)
//{
//	int frist=0, end=len-1,temp=0;
//	while (frist < end)
//	{
//		while ((frist < end)&& (arr[frist] % 2 != 0))
//		{
//				frist++;
//		}
//		while ((frist < end) &&(arr[end] % 2 == 0))
//		{
//			end--;
//		}
//		if (frist < end)
//		{
//			temp = arr[frist];
//			arr[frist] =arr[end];
//			arr[end] =temp;
//		}
//	}
//
//}
//int main()
//{
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	Adjust_array(arr, len);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


/*5.题目描述:功能:等差数列 2，5，8，11，14。。。。
输入:正整数N >0    输出:求等差数列前N项和
本题为多组输入，请使用while(cin>>)等形式读取数据
输入描述:输入一个正整数。
输出描述:输出一个相加后的整数。*/
//#include<stdio.h>
//int sumAsq(int m)
//{
//    return m * (4 + (m - 1) * 3) / 2;
//}
//int main()
//{
//    int m = 0;
//    while (scanf("%d", &m) != EOF)
//    {
//        printf("%d\n", sumAsq(m));
//    }
//
//    return 0;
//}


/*6.题目描述:找出给定字符串中大写字符(即'A' - 'Z')的个数。
输入描述 :本题含有多组样例输入,对于每组样例，输入一行，代表待统计的字符串
输出描述 :对于每组样例，输出一个整数，代表字符串中大写字母的个数*/
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    char c[10000] = { '\0' };
//    while (gets(c) != NULL)    //gets没有接受到字符串时返回值----------NULL
//    {
//        int count = 0;
//        int n = strlen(c);
//        for (int i = 0; i < n; i++)
//        {
//            if (c[i] >= 'A' && c[i] <= 'Z')
//            {
//                count++;
//            }
//        }
//        printf("%d\n", count);
//    }
//    return 0;
//}


/*7.题目描述：输入一个整数，将这个整数以字符串的形式逆序输出
程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
输入描述:输入一个int整数
输出描述:将这个整数以字符串的形式逆序输出*/
//#include<stdio.h>
//void print(char* c)
//{
//    if (*c != '\0')
//    {
//        print(c + 1);
//    }
//    if (*c != '\0')
//    {
//        printf("%c", *c);
//    }
//        
//}
//int main()
//{
//    char c[20];
//    scanf("%s", &c);
//    print(c);
//    return 0;
//}


/*8.题目描述：接受一个只包含小写字母的字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）
输入描述 :输入一行，为一个只包含小写字母的字符串。
输出描述 :输出该字符串反转后的字符串。*/
//#include<stdio.h>
//#include<string.h>
//void print(char* ch)
//{
//    int len = strlen(ch);
//    for (int i = len - 1; i >= 0; i--)
//    {
//        printf("%c", ch[i]);
//
//    }
//}
//int main()
//{
//    char arr[1000];
//    gets(arr);   //gets()读取一行字符串
//    print(arr);
//    return 0;
//}


/*9.题目描述：用户登录网站，通常需要注册，一般需要输入两遍密码。请编程判断输入的两次密码是否一致，一致输出“same”，不一致输出“different”
输入描述:每行有两个用空格分开的字符串，第一个为密码，第二个为重复密码。
输出描述:每组输出一个字符串（“same”或“different”）。*/
//#include<stdio.h>
//int main()
//{
//    char s1[100], s2[100];
//    scanf("%s %s", &s1, &s2);
//    if (strcmp(s1, s2) == 0)
//    {
//        printf("same\n");
//    }
//    else
//    {
//        printf("different\n");
//    }
//    return 0;
//}


/*10.题目描述：写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。
输入描述:输入一个正浮点数值
输出描述:输出该数值的近似整数值*/
//#include<stdio.h>
//int main()
//{
//    float f;
//    scanf("%f", &f);
//    int a = (int)f;    //得到整数部位
//
//    if ((f - a) >= 0.5)
//    {
//        printf("%d", a + 1);
//    }
//    else
//    {
//        printf("%d", a);
//    }
//    return 0;
//}


/*11.题目描述：输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。
输入描述:输入一个整数（int类型）
输出描述:这个数转换成2进制后，输出1的个数*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    scanf("%d", &num);
//    int count = 0;
//    while (num)
//    {
//        count++;
//        num = num & (num - 1);
//    }
//    printf("%d", count);
//    return 0;
//}


/*12.题目描述:计算字符串最后一个单词的长度，单词以空格隔开。
输入描述:输入一行，代表要计算的字符串，非空，长度小于5000。
输出描述:输出一个整数，表示输入字符串最后一个单词的长度。*/
//#include<stdio.h>
//#include<string.h>
//int str(char* str1)
//{
//    int  len = strlen(str1);
//    int count = 0;
//    while ((str1[len - 1]) != ' ')
//    {
//        if (len-1>= 0)
//        {
//            count++;
//            len--;
//        }
//        else
//        {
//            break;
//        }
//    }
//    return count;
//}
//int main()
//{
//    char arr[5000];
//    gets(arr);
//    printf("%d", str(arr));
//    return 0;
//}


/*13.题目描述输入10个整数，要求按输入时的逆序把这10个数打印出来。逆序输出，就是按照输入相反的顺序打印这10个数。
输入描述 :一行，输入10个整数（范围 - 231~231 - 1），用空格分隔。
输出描述 :一行，逆序输出输入的10个整数，用空格分隔。*/
//#include<stdio.h>
//int main()
//{
//    int arr[10];
//    for (int i = 0; i < 10; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (int i = 9; i >= 0; i--)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}