#define _CRT_SECURE_NO_WARNINGS 1

/*1.改写strlen函数*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	const char* frist = str;
//	while (*str != '\0')        
//	{
//		str++;
//	}
//	return str - frist;         //运用指针-指针的方法得到字符的个数
//}
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n",my_strlen(arr));
//	system("pause");
//	return 0;
//}


/*2.运用递归的方法，把字符串逆序，并输出 */
//#include<stdio.h>
//#include<string.h>
//void reverse_string(char* arr)
//{
//	int len = strlen(arr);
//	char tmp = *arr;
//	*arr = *(arr + len - 1);
//	*(arr + len - 1) = '\0';
//	if (strlen(arr + 1) >= 2)
//	{
//		reverse_string(arr + 1);
//	}
//	*(arr + len - 1) = tmp;
//}
//
//int main()
//{
//	char arr[100];
//	gets(arr);   //gets()读取一行字符串
//	reverse_string(arr);
//	printf("%s", arr);
//	return 0;
//}


/*3.题目描述：有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”
答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。
然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
输入描述:输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=100），表示小张手上的空汽水瓶数。n=0表示输入结束，你的程序不应当处理这一行。
输出描述:对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。*/
//#include<stdio.h>
//int main()
//{
//    int empty_bottle;
//    while (scanf("%d", &empty_bottle) && (empty_bottle != 0))
//    {
//        int sum = 0;
//        while (empty_bottle >= 3)
//        {
//            sum += empty_bottle / 3;
//            empty_bottle = empty_bottle / 3 + empty_bottle % 3;
//            if (empty_bottle + 1 == 3)    //当有2空瓶时，向老板借一瓶，喝完就有3个空瓶，就可以在换一瓶，并还给老板
//            {
//                sum += 1;
//            }
//        }
//
//        printf("%d\n", sum);
//    }
//}


/*4.题目描述：有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？
本题有多组数据。输入描述:输入int型表示month
输出描述:输出兔子总数int型*/
//#include<stdio.h>
//int fib(int month)                             //斐波那契数列又称兔子数列
//{
//    int a = 1, b = 1, c = 1;
//    while (month > 2)
//    {
//        c = a + b;
//        a = b;
//        b = c;
//        month--;
//    }
//    return c;
//}
//int main()
//{
//    int month;
//    while (scanf("%d", &month) != EOF)
//    {
//        printf("%d\n", fib(month));
//    }
//    return 0;
//}


//拓展
//求出整个斐波那契数列
//#include<stdio.h>
//#include<stdlib.h>
//long long fib(size_t n)
//{
//	long long* fibArray =malloc(sizeof(long long) * (n + 1));
//	fibArray[0] = 0;
//	if (0 == n)
//	{
//		return fibArray;
//	}
//	fibArray[1] = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	long long*arr=fib(n);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ",arr[i] );
//	}
//	system("pause");
//	return 0;
//}



/*5.题目描述:根据输入的日期，计算是这一年的第几天。。
测试用例有多组，注意循环输入
输入描述:输入多行，每行空格分割，分别是年，月，日
输出描述:成功:返回outDay输出计算后的第几天;
失败:返回-1*/
//#include<stdio.h>
//int Calculation_day(int year, int month, int day)
//{
//    int sum = 0;
//    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//    {
//        days[1] += 1;
//    }
//    if (day > days[month - 1])
//    {
//        return -1;
//    }
//    else
//    {
//        for (int i = 0; i < month - 1; i++)
//        {
//            sum += days[i];
//        }
//        sum += day;
//    }
//    return sum;
//}
//int main()
//{
//    int year, month, day;
//    while (~scanf("%d%d%d", &year, &month, &day))
//    {
//        printf("%d\n", Calculation_day(year, month, day));
//    }
//    return 0;
//}


/*6.题目描述:输入10个整数，分别统计输出正数、负数的个数。
输入描述:输入10个整数（范围-231~231-1），用空格分隔。
输出描述:两行，第一行正数个数，第二行负数个数，具体格式见样例。
示例1
输入:-1 2 3 -6 7 8 -1 6 8 10
输出:positive:7
negative:3*/
//#include<stdio.h>
//int main()
//{
//    int arr[10];
//    int Positive = 0;
//    int negative = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        scanf("%d", &arr[i]);
//        if (arr[i] > 0)
//        {
//            Positive++;
//        }
//        if (arr[i] < 0)
//        {
//            negative++;
//        }
//    }
//    printf("positive:%d\n", Positive);
//    printf("negative:%d\n", negative);
//    return 0;
//}


/*7.题目描述:KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用数字组成的数字三角形图案。
输入描述:多组输入，一个整数（3~20），表示数字三角形边的长度，即数字的数量，也表示输出行数。
输出描述:针对每行输入，输出用数字组成的对应长度的数字三角形，每个数字后面有一个空格。
示例：输入:4
输出:1
1 2
1 2 3
1 2 3 4*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    while (~scanf("%d", &num))
//    {
//        for (int i = 1; i <= num; i++)
//        {
//            for (int j = 1; j <= i; j++)
//            {
//                printf("%d ", j);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}


/*8.题目描述：输入NxM矩阵，矩阵元素均为整数，计算其中大于零的元素之和。
输入描述:第一行为N M(N: 矩阵行数；M: 矩阵列数,且M,N<=10)，接下来的N行为矩阵各行。
输出描述:一行，其中大于零的元素之和。*/
//#include<stdio.h>
//int main()
//{
//    int arr[10][10], m, n, sum = 0;
//    scanf("%d%d", &m, &n);
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            scanf("%d", &arr[i][j]);
//            if (arr[i][j] > 0)
//            {
//                sum += arr[i][j];
//            }
//        }
//
//    }
//    printf("%d", sum);
//    return 0;
//}


/*9.题目描述：输入一个整数序列，判断是否是有序序列，有序，指序列中的整数从小到大排序或者从大到小排序。
输入描述:第一行输入一个整数N(3≤N≤50)。
第二行输入N个整数，用空格分隔N个整数。
输出描述:输出为一行，如果序列有序输出sorted，否则输出unsorted。*/
//#include<stdio.h>
//int main()
//{
//    int num, arr[50];
//    scanf("%d", &num);
//    for (int i = 0; i < num; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (int j = 2; j < num; j++)
//    {
//        if (arr[0] < arr[1])    //升序
//        {
//            if (arr[j - 1] > arr[j])
//            {
//                printf("unsorted\n");
//                break;
//            }
//            else if (j == num - 1)
//            {
//                printf("sorted\n");
//            }
//        }
//        else                  //降序
//        {
//            if (arr[j - 1] < arr[j])
//            {
//                printf("unsorted\n");
//                break;
//            }
//            else if (j == num - 1)
//            {
//                printf("sorted\n");
//            }
//        }
//    }
//    return 0;
//}


/*10.题目描述：有一个整数序列（可能有重复的整数），现删除指定的某一个整数，输出删除指定数字之后的序列，序列中未被删除数字的前后位置没有发生改变。
输入描述:第一行输入一个整数(0≤N≤50)。
第二行输入N个整数，输入用空格分隔的N个整数。
第三行输入想要进行删除的一个整数。
输出描述:输出为一行，删除指定数字之后的序列。*/
//#include<stdio.h>
//int main()
//{
//    int n, k, arr1[50], arr2[50];
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr1[i]);
//    }
//    scanf("%d", &k);
//    int q = 0;
//    for (int j = 0; j < n; j++)
//    {
//        if (arr1[j] != k)
//        {
//            arr2[q++] = arr1[j];
//        }
//    }
//    for (int m = 0; m < q; m++)
//    {
//        printf("%d ", arr2[m]);
//    }
//    return 0;
//}