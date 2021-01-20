#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<time.h>
#include<math.h>

int max3(int a, int b, int c)
{
    return a > b ? a : b > c ? b : c;
}


void menu()
{
    printf("---------------------\n");
    printf("     1.玩游戏        \n");
    printf("     2.退出游戏      \n");
    printf("---------------------\n");
}


void GuessNum()
{
    srand((unsigned int)time(NULL));
    int m = rand() % 100 + 1;
    while (true)
    {
        int Num;
        cout << "请猜数字" << endl;
        cin >> Num;
        if (m == Num)
        {
            cout << "恭喜你答对了" << endl;
            break;
        }
        else if (m > Num)
        {

            cout << "猜小了，请重新猜" << endl;
        }
        else
        {
            cout << "猜大了，请重新猜" << endl;
        }
    }
}


//int main()
//{
    //1.问题描述：小乐乐的老师BoBo想知道班级中谁的数学成绩最高，请编程帮他实现。
    //第一行输入一个数n，代表小乐乐的班级中n个同学。
    //第二行输入n个数，用空格相隔，代表班级中每个人的数学成绩。
    //一个整数，代表班级中最高的数学成绩。
    //int x, arr[100], max = 0;
    //scanf("%d", &x);
    //for (int i = 0; i <x; i++)
    //{
    //    scanf("%d", &arr[i]);
    //    if (max < arr[i])
    //    {
    //        max = arr[i];
    //    }
    //}
    //printf("%d", max);


    //2.问题描述：小乐乐想计算一下1!+2!+3!+...+n!。
    //int n, Fac = 1, sum = 0;
    //scanf("%d", &n);
    //for (int i = 1; i <= n; i++)
    //{
    //    Fac = Fac * i;
    //    sum = sum + Fac;
    //}
    //printf("%d", sum);


    //3.问题描述：小乐乐学会了自定义函数，BoBo老师给他出了个问题，根据以下公式计算m的值。
    //m=max3(a + b, b, c)/max3(a, b + c, c) + max3(a, b, b + c
    //其中 max3函数为计算三个数的最大值，如： max3(1, 2, 3) 返回结果为3。
    //int a, b, c;
    //float m = 0;
    //scanf("%d %d %d", &a, &b, &c);
    //m =(float) max3(a + b, b, c)*1.0/(max3(a, b + c, c) + max3(a, b, b + c));
    //printf("%f", m);


    //4.问题描述：确定不同整型数据类型在内存中占多大（字节），输出不同整型数据类型在内存中占多大（字节）。
    //不同整型数据类型在内存中占多大（字节），具体格式详见输出样例，输出样例中的 ? 为不同整型数据类型在内存中占的字节数。
    //输出样例如下：
    /* The size of short is ? bytes.
    The size of int is ? bytes.
    The size of long is ? bytes.
    The size of long long is ? bytes.*/

    //printf("The size of short is %d bytes.\n", sizeof(short));        2
    //printf("The size of int is %d bytes.\n", sizeof(int));            4   
    //printf("The size of long is %d bytes.\n", sizeof(long));          4
    //printf("The size of long long is %d bytes.\n", sizeof(long long));8


    //5.问题描述：给定两个整数a和b (－10,000 < a,b < 10,000)，计算a除以b的整数商和余数。
    //int a = 0, b = 0;
    //scanf("%d%d", &a, &b);
    //printf("%d %d", a / b, a % b);


    //6.问题描述：请计算表达式“(-8+22)×a-10+c÷2”，其中，a = 40，c = 212。
    //int a = 40;
    //int c = 212;
    //int ret = (-8 + 22) * a - 10 + c / 2;
    //printf("%d\n", ret);


    //7.问题描述：KiKi想知道已经给出的三条边a，b，c能否构成三角形，如果能构成三角形，判断三角形的类型（等边三角形、等腰三角形或普通三角形）。
    //int  a, b, c;
    //while (scanf("%d%d%d", &a, &b, &c) != EOF)
    //{
    //    if (a + b > c && a + c > b && c + b > a)
    //    {
    //        if (a == b && b == c)
    //        {
    //            printf("Equilateral triangle!\n"); //等边
    //        }
    //        else if ((a == b && b != c) || (a == c && c != b) || (b == c && c != a))
    //        {
    //            printf("Isosceles triangle!\n");//等腰
    //        }
    //        else
    //        {
    //            printf("Ordinary triangle!\n");//普通
    //        }
    //    }
    //    else
    //    {
    //        //不是
    //        printf("Not a triangle!\n");
    //    }
    //}


    //8.问题描述：KiKi写了一个输出“Hello world!”的程序，BoBo老师告诉他printf函数有返回值，你能帮他写个程序输出printf(“Hello world!”)的返回值吗？
    //printf的返回值是字符的个数
    //int a = printf("Hello world!");
    //printf("\n");
    //printf("%d", a);


    //9.问题描述：输入3科成绩，然后把三科成绩输出，成绩为整数形式。
    //int score1 = 0, score2 = 0, score3 = 0;
    //scanf("%d%d%d", &score1, &score2, &score3);
    //printf("score1=%d,score2=%d,score3=%d", score1, score2, score3);


    //10.问题描述：根据给出的三角形3条边a, b, c（0 < a, b, c < 100,000），计算三角形的周长和面积。
    //int a = 0, b = 0, c = 0;
    //scanf("%d%d%d",&a,&b,&c);
    //float len =a+b+c;
    //float p = (a + b + c) / 2.0;
    //float area = sqrt(p * (p - a) * (p - b) * (p - c));
    //printf("circumference=%.2f area=%.2f", len, area);


    //11.问题描述：.KiKi参加了语文、数学、外语的考试，请帮他判断三科中的最高分。从键盘任意输入三个整数表示的分数，编程判断其中的最高分。
    //多组输入，每行输入包括三个整数表示的分数（0~100），用空格分隔。
    //int a, b, c;
    //while (scanf("%d%d%d", &a, &b, &c) != EOF)
    //{
    //    printf("%d\n", (a > b ? a : b) > c ? (a > b ? a : b) : c);
    //}


    //12.问题描述：KiKi想完成字母大小写转换，有一个字符，判断它是否为大写字母，如果是，将它转换成小写字母；反之则转换为大写字母。
    //char c = '0';
    //while (scanf("%c", &c) != EOF)
    //{
    //    if (c >= 'A' && c <= 'Z')
    //        printf("%c\n", c + 32);
    //    else if (c >= 'a' && c <= 'z')
    //        printf("%c\n", c - 32);
    //}


    //13.问题描述：猜数字游戏 
//    int select = 0;
//    while (true)
//    {
//        menu();
//        scanf("%d", &select);
//        switch (select)
//        {
//        case 1:
//            GuessNum();
//            system("pause");
//            system("cls");
//            break;
//        case 0:
//            exit(0);
//        default:
//            printf("输入有误，请重新输入\n");
//            system("pause");
//            system("cls");
//            break;
//        }
//    }
//
//    return 0;
//}


//14.问题描述：依次输入一个学生的学号，以及3科（C语言，数学，英语）成绩，在屏幕上输出该学生的学号，3科成绩。
//#include<stdio.h>
//int main()
//{
//    
//    int no;
//    float English_score;
//    float C;
//    float math_score;
//    scanf("%d;%f,%f,%f\n", &no, &C, &English_score, &math_score);
//    printf("The each subject score of  No. %d is %.2f, %.2f, %.2f.", no, C, English_score,math_score);
//    return 0;
//
//}
//    


//15.问题描述：BoBo教KiKi字符常量或字符变量表示的字符在内存中以ASCII码形式存储。BoBo出了一个问题给KiKi，转换以下ASCII码为对应字符并输出他们。
//73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33
//#include<stdio.h>
//int main()
//{
//    printf("%c%c%c%c%c%c%c%c%c%c%c%c", 73, 32, 99, 97, 110, 32, 100, 111, 32, 105,116, 33);
//    return 0;
//}


//16.问题描述：输入两个整数，范围-231~231-1，交换两个数并输出。
//#include<stdio.h>
//int main()
//{
//    int a;
//    int b;
//    int temp;
//    scanf("a=%d,b=%d", &a, &b);
//    temp = b;
//    b = a;
//    a = temp;
//    printf("a=%d,b=%d", a, b);
//    return 0;
//}


//17.问题描述：输入一个人的出生日期（包括年月日），将该生日中的年、月、日分别输出。
//三行，第一行为出生年份，第二行为出生月份，第三行为出生日期。输出时如果月份或天数为1位数，需要在1位数前面补0。
//#include<stdio.h>
//int main()
//{
//    int a, b, c;
//    scanf("%4d%2d%2d", &a, &b, &c);
//    printf("year=%d\nmonth=%02d\ndate=%02d\n", a, b, c);
//    return 0;
//}


//18.问题描述：BoBo教KiKi字符常量或字符变量表示的字符在内存中以ASCII码形式存储。
//BoBo出了一个问题给KiKi，输入一个字符，输出该字符相应的ASCII码。
//#include<stdio.h>
//int main()
//{
//    char c;
//    scanf("%c", &c);
//    printf("%d", c);
//    return 0;
//}
