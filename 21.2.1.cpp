#define _CRT_SECURE_NO_WARNINGS 1


/*1.作业标题:杨辉三角
作业内容:在屏幕上打印杨辉三角。
1
1 1
1 2 1
1 3 3 1
……*/
//#include<stdio.h>
//void yangHuiTriangle(int n)
//{
//	int arr[20][20];
//	for (int i = 0; i < n; i++)          //把俩边都初始化为1
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;                //1和2行都是1，这里已经把第1行和第2行初始化为1了
//	}
//	/*杨辉三角最终显示效果是一个等腰三角形，两个最外边都是1
//    杨辉三角的根本在于，每个数等于它上方两数之和*/
//	for (int i = 2; i <=n; i++)          //从第三行开始变化
//	{
//		for (int j = 1; j<i; j++)
//		{
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//
//	//打印
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printf("%5d", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	yangHuiTriangle(n);
//	return 0;
//}


/*2.作业标题：猜凶手
作业内容：日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
以下为4个嫌疑犯的供词:
A说：不是我。 B说：是C。 C说：是D。 D说：C在胡说。已知3个人说了真话，1个人说的是假话。
现在请根据这些信息，写一个程序来确定到底谁是凶手。*/
//#include<stdio.h>
//int main()
//{
//    int k = 0;
//    for (k == 'A'; k <= 'D'; k++)//从A开始判断
//    {
//        if ((k != 'A') + (k == 'C') + (k == 'D') + (k != 'D') == 3)//是凶手的条件
//        {
//            printf("k=%c\n", k);
//        }
//    }
//    return 0;
//}


/*3.作业标题:猜名次
作业内容:5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。*/
//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1) &&
//							((b == 2) + (e == 4) == 1) &&
//							((c == 1) + (d == 2) == 1) &&
//							((c == 5) + (d == 3) == 1) &&
//							((e == 4) + (a == 1) == 1))
//						{
//							if ((a * b * c * d * e == 120) && (a + b + c + d + e == 15))  //避免重复
//							{
//								printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
//							}
//
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}


/*4.下面代码的执行结果是*/
#include<stdio.h>
int main()
{
    const char str1[] = "hello bit.";
    const char str2[] = "hello bit.";
    const char* str3 = "hello bit.";
    const char* str4 = "hello bit.";

    //str1和str2是两个数组，数组的操作方式是将右边常量字符串的内容拷贝进来，所以他们是两个空间，只是内容相同，所以str1 != str2。
    if (str1 == str2)
    {
        printf("str1 and str2 are same\n");
    }
    else
    {
        printf("str1 and str2 are not same\n");
    }
    //而str3和str4是两个指针，编译器在处理的时候，会将相同的常量字符串做成同一个地址，所以，str3和str4指向的是同一个常量字符串，所以str3 == str4
    if (str3 == str4)
    {
        printf("str3 and str4 are same\n");
    }
    else
    {
        printf("str3 and str4 are not same\n");
    }
    return 0;
}
