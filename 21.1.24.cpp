#define _CRT_SECURE_NO_WARNINGS 1


/*1.问题描述：实现一个对整形数组的冒泡排序*/
//#include<stdio.h>
//void Bubble_sort(int *arr,int len)
//{
//	bool flag = true;
//	for (int i = 0; i < len-1; i++)
//	{
//		for (int j = 0; j <len-i- 1; j++)
//		{
//			if (arr[j]>arr[j+1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = temp;
//				flag = false;
//			}
//		}
//		if (true == flag)
//		{
//			return;
//		}
//	}
//}
//int main()
//{
//	int arr[10];
//	int len = sizeof(arr) / sizeof(arr[0]);       //求数组长度
//	for (int i = 0; i < len; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	Bubble_sort(arr,len);
//	printf("排序后");
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}


/*2.问题描述：创建一个整形数组，完成对数组的操作
实现函数init() 初始化数组为全0
实现print()  打印数组的每个元素
实现reverse()  函数完成数组元素的逆置。
要求：自己设计以上函数的参数，返回值。
*/
//#include<stdio.h>
//void init(int *arr,int row,int value)    //针对一维数组的初始化  
//{
//	for (int i = 0; i < row; i++)
//	{
//			arr[i] = value;
//	}
//}
//
//void print(int *arr,int row)            //针对二维数组的打印  
//{
//	for (int j = 0; j <row; j++)
//	{
//		printf("%d ", arr[j]);
//	}
//}
//void Reverse(int *arr, int len)
//{
//	for (int i = 0,j = len - 1; i < j; i++, j--)
//	{
//		int temp = arr[i];
//		arr[i] = arr[j];
//		arr[j] = temp;
//	}
//}
//int main()
//{
//	int arr[5] = {1,2,3,4,5};
//	init(arr, 5, 0);
//	Reverse(arr, 5);
//	print(arr, 5);
//}


/*3.问题描述：将数组A中的内容和数组B中的内容进行交换。（数组一样大）*/
//#include<stdio.h>
//void swap(int* arr1, int* arr2,int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//	}
//}
//int main()
//{
//	int arrA[5] = {1,2,3,4,5};
//	int arrB[5] = {99,88,77,66,55};
//	int len = sizeof(arrA) / sizeof(arrA[0]);
//	swap(arrA, arrB,len);
//	for (int i = 0; i < 5;i++)
//	{
//		printf("%d %d\n", arrA[i],arrB[i]);
//	}
//	return 0;
//}


/*4.题目描述:从键盘输入a, b, c的值，编程计算并输出一元二次方程ax2 + bx + c = 0的根，当a = 0时，输出“Not quadratic equation”，当a ≠ 0时，根据△ = b2 - 4*a*c的三种情况计算并输出方程的根。
输入描述:多组输入，一行，包含三个浮点数a, b, c，以一个空格分隔，表示一元二次方程ax2 + bx + c = 0的系数。
输出描述:针对每组输入，输出一行，输出一元二次方程ax2 + bx +c = 0的根的情况。
如果a = 0，输出“Not quadratic equation”；
如果a ≠  0，分三种情况：
△ = 0，则两个实根相等，输出形式为：x1=x2=...。
△  > 0，则两个实根不等，输出形式为：x1=...;x2=...，其中x1  <=  x2。
△  < 0，则有两个虚根，则输出：x1=实部-虚部i;x2=实部+虚部i，即x1的虚部系数小于等于x2的虚部系数，
实部为0时不可省略。实部= -b / (2*a),虚部= sqrt(-△ ) / (2*a)
所有实数部分要求精确到小数点后2位，数字、符号之间没有空格。*/
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//    float a, b, c;
//    while (scanf("%f %f %f", &a, &b, &c) != EOF)
//    {
//        if (a == 0)
//        {
//            printf("Not quadratic equation\n");
//        }
//        else
//        {
//            float f = b * b - 4 * a * c;
//            if (f == 0)
//            {
//                printf("x1=x2=%.2f\n", -b / (2 * a));
//            }
//            else if (f > 0)
//            {
//                float x1 = (-b - sqrt(f)) / (2 * a);
//                float x2 = (-b + sqrt(f)) / (2 * a);
//                printf("x1=%.2f;x2=%.2f\n", x1, x2);
//            }
//            else
//            {
//                float m =(-b)/ (2 * a);
//                float n =sqrt(-f) /(2 * a);
//                printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi\n", m, n, m, n);
//            }
//        }
//    }
//    return 0;
//}


/*5.题目描述:KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的线段图案。
输入描述:多组输入，一个整数（1~100），表示线段长度，即“*”的数量。
输出描述:针对每行输入，输出占一行，用“*”组成的对应长度的线段。*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    while (scanf("%d,", &num) != EOF)
//    {
//        for (int i = 0; i < num; i++)
//        {
//            printf("*");
//        }
//        printf("\n");
//    }
//    return 0;
//}


/*6.题目描述:KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的正方形图案。
输入描述:多组输入，一个整数（1~20），表示正方形的长度，也表示输出行数。
输出描述:针对每行输入，输出用“*”组成的对应边长的正方形，每个“*”后面有一个空格。*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    while (scanf("%d,", &num) != EOF)
//    {
//        for (int j = 0; j < num; j++)
//        {
//            for (int i = 0; i < num; i++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//
//    }
//    return 0;
//}


/*7.题目描述:KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的直角三角形图案。
输入描述:多组输入，一个整数（2~20），表示直角三角形直角边的长度，即“*”的数量，也表示输出行数。
输出描述:针对每行输入，输出用“*”组成的对应长度的直角三角形，每个“*”后面有一个空格。*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    while (scanf("%d,", &num) != EOF)
//    {
//        for (int j = 0; j < num; j++)
//        {
//            for (int i = 0; i <= j; i++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//
//    }
//    return 0;
//}


/*8.题目描述:新年到来，输出信息迎接新年。
输入描述:无
输出描述:Happy New Year*2019* */
//#include<stdio.h>
//int main()
//{
//    printf("Happy New Year*2019*");
//    return 0;
//}


/*9.题目描述:这是一个非常简单的题目，意在考察你编程的基础能力。千万别想难了哦。输入为一行，
包括了用空格分隔的四个整数a、b、c、d（0 < a, b, c, d < 100,000）。输出为一行，为“(a+b-c)*d”的计算结果。
输入描述:输入为一行，用空格分隔的四个整数a、b、c、d（0 < a, b, c, d < 100,000）。
输出描述:输出为一行，为“(a+b-c)*d”的计算结果。*/
//#include<stdio.h>
//int main()
//{
//    int a, b, c, d;
//    scanf("%d%d%d%d", &a, &b, &c, &d);
//    printf("%d", (a + b - c) * d);
//    return 0;
//}


/*10.题目描述:有个软件系统登录的用户名和密码为（用户名：admin，密码：admin），用户输入用户名和密码，判断是否登录成功。
输入描述:多组测试数据，每行有两个用空格分开的字符串，第一个为用户名，第二个位密码。
输出描述:针对每组输入测试数据，输出为一行，一个字符串（“Login Success!”或“Login Fail!”）。*/
//#include<stdio.h>
//int main()
//{
//    char name[20] = "admin";
//    char password[20] = "admin";
//    char name1[20];
//    char password1[20];
//    while (scanf("%s %s", name1, password1) != EOF)
//    {
//        if (strcmp(name, name1) == 0 && strcmp(password, password1) == 0)
//        {
//            printf("Login Success!\n");
//        }
//        else
//        {
//            printf("Login Fail!\n");
//        }
//    }
//    return 0;
//}


/*11.题目描述
判断一个整数是否能5整除是一个挺简单的问题，懒惰的KiKi还是不想自己做，于是找到你帮他写代码，你就帮帮他吧。
输入描述:输入包括一个整数M（1≤M≤100,000）。
输出描述:输出包括一行，如果M可以被5整除就输出YES，否则输出NO（结果大小写敏感）。*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    scanf("%d", &num);
//    if (num % 5 == 0)
//    {
//        printf("YES\n");
//    }
//    else
//    {
//        printf("NO\n");
//    }
//    return 0;
//}


/*12.题目描述:从键盘输入5个人的身高（米），求他们的平均身高（米）。
输入描述:一行，连续输入5个身高（范围0.00~2.00），用空格分隔。
输出描述:一行，输出平均身高，保留两位小数。*/
//#include<stdio.h>
//int main()
//{
//    float arr[5];
//    float f = 0.0;
//    for (int i = 0; i < 5; i++)
//    {
//        scanf("%f", &arr[i]);
//        f += arr[i];
//    }
//    printf("%.2f", f / 5.0);
//    return 0;
//}