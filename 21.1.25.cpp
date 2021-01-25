#define _CRT_SECURE_NO_WARNINGS 1

/*1.题目描述
KiKi最近学习了信号与系统课程，这门课里有一个非常有趣的函数，单位阶跃函数，其中一种定义方式为：
现在试求单位冲激函数在时域t上的值。
输入描述:
题目有多组输入数据，每一行输入一个t(-1000<t<1000)表示函数的时域t。
输出描述:
输出函数的值并换行。*/
//#include<stdio.h>
//int main()
//{
//    int t;
//    while (scanf("%d", &t) != EOF)
//    {
//        if (t > 0)
//        {
//            printf("1\n");
//        }
//        else if (t == 0)
//        {
//            printf("0.5\n");
//        }
//        else
//        {
//            printf("0\n");
//        }
//    }
//}


/*2.题目描述:不允许创建临时变量，交换两个整数的内容*/
//#include<stdio.h>
//void swap(int *a, int *b)
//{
//	*a= *a ^ *b;
//	*b= *a ^ *b;
//	*a= *a ^ *b;
//}
//int main()
//{
//	int x, y;
//	scanf("%d%d", &x, &y);
//	swap(&x, &y);
//	printf("x=%d y=%d", x, y);
//	return 0;
//}


/*3.题目描述:KiKi开始学习英文字母，BoBo老师告诉他，有五个字母A(a), E(e), I(i), O(o),U(u)称为元音，其他所有字母称为辅音，请帮他编写程序判断输入的字母是元音（Vowel）还是辅音（Consonant）。
输入描述:多组输入，每行输入一个字母。
输出描述:针对每组输入，输出为一行，如果输入字母是元音（包括大小写），输出“Vowel”，如果输入字母是非元音，输出“Consonant”。.*/
//#include<stdio.h>
//int main()
//{
//    char ch;
//    char c[] = "AaEeIiOoUu";
//    while (scanf("%c", &ch) != EOF)
//    {
//        getchar();      //把\n读走
//        int i = 0;
//        for (i = 0; i < 10; i++)
//        {
//            if (ch == c[i])
//            {
//                printf("Vowel\n");
//                break;
//            }
//        }
//        if (i == 10)
//        {
//            printf("Consonant\n");
//        }
//    }
//    return 0;
//}


/*4.题目描述:KiKi实现一个简单计算器，实现两个数的“加减乘除”运算，
用户从键盘输入算式“操作数1运算符操作数2”，计算并输出表达式的值，
如果输入的运算符号不包括在（+、-、*、/）范围内，输出“Invalid operation!”。
当运算符为除法运算，即“/”时。如果操作数2等于0.0，则输出“Wrong!Division by zero!”
输入描述:多组输入，一行，操作数1运算符操作数2（其中运算符号包括四种：+、-、*、/）。
输出描述:针对每组输入，输出为一行。
如果操作数和运算符号均合法，则输出一个表达式，操作数1运算符操作数2=运算结果，各数小数点后均保留4位，数和符号之间没有空格。
如果输入的运算符号不包括在（+、-、*、/）范围内，输出“Invalid operation!”。当运算符为除法运算，即“/”时。
如果操作数2等于0.0，则输出“Wrong!Division by zero!”。*/
//#include<stdio.h>
//int main()
//{
//    double num1, num2;
//    char ch;
//    while (scanf("%lf%c%lf", &num1, &ch, &num2) != EOF)
//    {
//        if (num2 == 0)
//        {
//            printf("Wrong!Division by zero!\n");
//        }
//        else
//        {
//            if (ch == '+')
//            {
//                printf("%.4f+%.4f=%.4f\n", num1, num2, num1 + num2);
//            }
//            else if (ch == '*')
//            {
//                printf("%.4f*%.4f=%.4f\n", num1, num2, num1 * num2);
//            }
//            else if (ch == '-')
//            {
//                printf("%.4f-%.4f=%.4f\n", num1, num2, num1 - num2);
//            }
//            else if (ch == '/')
//            {
//                printf("%.4f/%.4f=%.4f\n", num1, num2, num1 / num2);
//            }
//            else
//            {
//                printf("Invalid operation!\n");
//            }
//        }
//    }
//    return 0;
//}


/*5.题目描述:KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的翻转直角三角形图案。
输入描述:多组输入，一个整数（2~20），表示翻转直角三角形直角边的长度，即“*”的数量，也表示输出行数。
输出描述:针对每行输入，输出用“*”组成的对应长度的翻转直角三角形，每个“*”后面有一个空格。*/
//#include<stdio.h>
//int main()
//{
//    int len;
//    while (scanf("%d", &len) != EOF)
//    {
//        for (int i = 0; i < len; i++)
//        {
//            for (int j = len - i - 1; j >= 0; j--)   //类似冒泡排序
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//
//    }
//    return 0;
//}


/*6.题目描述：KiKi想知道这学期他的学习情况，BoBo老师告诉他这学期挂的科目累计的学分，根据所挂学分，判断KiKi学习情况，10分以上：很危险(Danger++)，4~9分：危险(Danger)，0~3:Good。
输入描述:一行，一个整数（0~30），表示KiKi挂的科目累计的学分。
输出描述:一行，根据输入的挂科学分，输出相应学习情况（Danger++，Danger，Good）。*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    scanf("%d", &num);
//    if (num >= 0 && num <= 3)
//    {
//        printf("Good\n");
//    }
//    else if (num >= 4 && num <= 9)
//    {
//        printf("Danger\n");
//    }
//    else
//    {
//        printf("Danger++\n");
//    }
//}


/*7.题目描述：输入n科成绩（浮点数表示），统计其中的最高分，最低分以及平均分。
输入描述:两行，
第1行，正整数n（1≤n≤100）
第2行，n科成绩（范围0.0~100.0），用空格分隔。
输出描述:输出一行，三个浮点数，分别表示，最高分，最低分以及平均分（小数点后保留2位），用空格分隔。*/
//#include<stdio.h>
//int main()
//{
//    int n;
//    float score[20];
//    float max = 0;
//    float min = 110;
//    float sum;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%f", &score[i]);
//        sum += score[i];
//        if (max < score[i])
//        {
//            max = score[i];
//        }
//        if (min > score[i])
//        {
//            min = score[i];
//        }
//    }
//    printf("%.2f %.2f %.2f\n", max, min, sum / 5);
//    return 0;
//}


/*8.题目描述:输入一个班级5个学生各5科成绩，输出5个学生各5科成绩及总分。
输入描述:五行，每行输入一个学生各5科成绩（浮点数表示，范围0.0~100.0），用空格分隔。
输出描述:五行，按照输入顺序每行输出一个学生的5科成绩及总分（小数点保留1位），用空格分隔。*/
//#include<stdio.h>
//int main()
//{
//    float arr[5];
//    for (int j = 0; j < 5; j++)
//    {
//        float sum = 0;
//        for (int i = 0; i < 5; i++)
//        {
//            scanf("%f", &arr[i]);
//            printf("%.1f ", arr[i]);
//            sum += arr[i];
//        }
//        printf("%.1f\n", sum);
//    }
//
//    return 0;
//}


/*9.题目描述:输入数字N，然后输入N个数，计算这N个数的和。
输入描述:第一行输入一个整数N(0≤N≤50)，第二行输入用空格分隔的N个整数。
输出描述:输出为一行，为第二行输入的“N个整数之和”的计算结果。*/
//#include<stdio.h>
//int main()
//{
//    int n;
//    int arr[100];
//    scanf("%d", &n);
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//        sum += arr[i];
//    }
//    printf("%d", sum);
//    return 0;
//}


/*10.题目描述:输入n个成绩，换行输出n个成绩中最高分数和最低分数的差。
输入描述:两行，第一行为n，表示n个成绩，不会大于10000。
第二行为n个成绩（整数表示，范围0~100），以空格隔开。
输出描述:一行，输出n个成绩中最高分数和最低分数的差。*/
//#include<stdio.h>
//int main()
//{
//    int n;
//    int arr[10000];
//    int max = 0, min = 100;
//    scanf("%d", &n);
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//        sum += arr[i];
//        if (max < arr[i])
//        {
//            max = arr[i];
//        }
//        if (min > arr[i])
//        {
//            min = arr[i];
//        }
//    }
//    printf("%d", max - min);
//    return 0;
//}


/*11.题目描述:已知一个函数y=f(x)，当x < 0时，y = 1；当x = 0时，y = 0；当x > 0时，y = -1。   
输入描述:一行，输入一个整数x。（-10000<x<10000）
输出描述:一行，输出y的值*/
//#include<stdio.h>
//int main()
//{
//    int x, y;
//    scanf("%d", &x);
//    if (x < 0)
//    {
//        y = 1;
//        printf("1\n");
//    }
//    else if (x == 0)
//    {
//        y = 0;
//        printf("0\n");
//    }
//    else
//    {
//        y = -1;
//        printf("-1\n");
//    }
//    return 0;
//}