#define _CRT_SECURE_NO_WARNINGS 1

/*1.题目描述:小乐乐上课需要走n阶台阶，因为他腿比较长，所以每次可以选择走一阶或者走两阶，那么他一共有多少种走法？
输入描述:
输入包含一个整数n (1 ≤ n ≤ 30)
输出描述:
输出一个整数，即小乐乐可以走的方法数。*/
//#include<stdio.h>
//int fib(int num)         //又称青蛙跳台阶问题
//{
//    if (num <= 2)
//    {
//        return num;
//    }
//    else
//    {
//        return fib(num - 1) + fib(num - 2);
//    }
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int temp = fib(n);
//    printf("%d\n", temp);
//    return 0;
//}


/*2.题目描述：小乐乐输入三科成绩，请编程帮他输出三科成绩总分及平均分。
输入描述:
一行，3科成绩（浮点数），成绩之间用一个空格隔开。
输出描述:
一行，总分和平均分（小数点后保留两位），用一个空格隔开。*/
//#include<stdio.h>
//int main()
//{
//    float score[3], num = 0;
//    for (int i = 0; i < 3; i++)
//    {
//        scanf("%f", &score[i]);
//        num += score[i];
//    }
//    printf("%.2f %.2f", num, num / 3);
//    return 0;
//}


/*3.题目描述：老师给了小乐乐一个正整数序列，要求小乐乐把这个序列去重后按从小到大排序。但是老师给出的序列太长了，小乐乐没办法耐心的去重并排序，请你帮助他。
输入描述:
第一行包含一个正整数n，表示老师给出的序列有n个数。接下来有n行，每行一个正整数k，为序列中每一个元素的值。(1 ≤ n ≤ 105，1 ≤ k ≤ n)
输出描述:
输出一行，为去重排序后的序列，每个数后面有一个空格。*/
//#include<iostream>
//#include<algorithm>
//#include<stdio.h>
//using namespace std;
//int main()
//{
//    int arr[100000], n;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    sort(arr, arr + n);//sort需要包含的头文件  默认是升序
//    for (int k = 0; k < n; k++)
//    {
//        if (arr[k] == arr[k + 1])//重复不输出
//        {
//            continue;
//        }
//        printf("%d ", arr[k]);
//    }
//    return 0;
//}


/*4.题目描述：在庆祝祖国母亲70华诞之际，老师给小乐乐出了一个问题。大家都知道China的英文缩写是CHN，那么给你一个字符串s，你需要做的是统计s中子串“CHN”的个数。
子串的定义：存在任意下标a < b < c，那么“s[a]s[b]s[c]”就构成s的一个子串。如“ABC”的子串有“A”、“B”、“C”、“AB”、“AC”、“BC”、“ABC”。
输入描述:
输入只包含大写字母的字符串s。(1 ≤ length ≤ 8000)
输出描述:
输出一个整数，为字符串s中字串“CHN”的数量。*/
//#include<stdio.h>
//int main()
//{
//    char arr[8000] = { 0 };
//    scanf("%s", arr);
//    long long C = 0;
//    long long CH = 0;
//    long long CHN = 0;
//    char* p = arr;     //CCHNCHNCHNCHN
//    while (*p != '\0')
//    {
//        if (*p == 'C')   //2+1=3  4  5
//        {
//            C++;
//        }
//        else if (*p == 'H')
//        {
//            CH += C;   //2+3=5+4=9+5=14
//        }
//        else if (*p == 'N')
//        {
//            CHN += CH;   //2+5=7+9=16+14
//        }
//        p++;
//    }
//    printf("%lld", CHN);
//    return 0;
//}


/*5.题目描述：小乐乐获得4个最大数，请帮他编程找到最大的数。
输入描述:
一行，4个整数，用空格分开。
输出描述:
一行，一个整数，为输入的4个整数中最大的整数。*/
//#include<stdio.h>
//int main()
//{
//    int max[4], max1 = 0;
//    for (int i = 0; i < 4; i++)
//    {
//        scanf("%d", &max[i]);
//        if (max1 < max[i])
//        {
//            max1 = max[i];
//        }
//    }
//    printf("%d", max1);
//    return 0;
//}


/*6.题目描述小乐乐输入百分制成绩，他想将成绩转换成等级制。转换规则为：90-100为’A’，
80-89为’B’，70-79为’C’，60-69为’D’，59以下为’E’。如果输入的成绩不在0-100之间，输出’F’。
输入描述:一行，一个整数表示的成绩。
输出描述:一行，转换后的等级。*/
//#include<stdio.h>
//int main()
//{
//    int score = 0;
//    scanf("%d", &score);
//    if (score >= 0 && score <= 100)
//    {
//        switch (score / 10)
//        {
//        case 9:
//        case 10:
//            printf("A\n");
//            break;
//        case 8:
//            printf("B\n");
//            break;
//        case 7:
//            printf("C\n");
//            break;
//        case 6:
//            printf("D\n");
//            break;
//        default:
//            printf("E\n");
//            break;
//        }
//    }
//    else
//    {
//        printf("F\n");
//    }
//    return 0;
//}


/*7.题目描述给定n个整数和一个整数x，小乐乐想从n个整数中判断x出现几次，请编程帮他实现。
输入描述:共3行
第一行，一个整数，表示n（1 <= n <= 100）。
第二行，共输入n个整数，两个整数之间用空格分隔。
第三行，输入一个整数，表示要查找的整数x。
输出描述:一行，表示整数x出现的次数。*/
//#include<stdio.h>
//int main()
//{
//    int n, arr[100], k;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    int count = 0;
//    scanf("%d", &k);
//    for (int i = 0; i < n; i++)
//    {
//        if (k == arr[i])
//        {
//            count++;
//        }
//    }
//    printf("%d", count);
//    return 0;
//}


/*8.题目描述：KiKi知道了什么是质数（只能被1和他自身整除的数），他现在想知道所有三位整数中，有多少个质数。
输入描述:无
输出描述:一行，一个整数，表示所有三位整数中，有多少个质数。*/
//#include<stdio.h>
//#include<math.h>
//int is_prime(int i)
//{
//    for (int j = 2; j <= sqrt(i); j++)
//    {
//        if (i % j == 0)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//int main()
//{
//    int count = 0;
//    for (int i = 100; i <= 999; i++)
//    {
//        if (is_prime(i))
//        {
//            count++;
//        }
//    }
//    printf("%d", count);
//    return 0;
//}


/*9.题目描述：KiKi学习了面向对象技术，学会了通过封装属性（变量）和行为（函数）定义类，现在他要设计一个电子日历类TDate。
它有3个私有数据成员：Month,Day,Year和若干个公有成员函数，要求：
（1）带有默认形参值的构造函数，默认值为0, 0, 0；
（2）输出日期函数，用“日/月/年”格式输出日期；
（3）设置日期函数，从键盘输入年、月、日。
输入描述:
一行，三个整数，用空格分隔，分别表示年、月、日。
输出描述:
一行，用“日/月/年”格式输出日期。*/
//#include<iostream>
//using namespace std;
//class TDate
//{
//public:
//    TDate(int y = 0, int m = 0, int d = 0)
//    {
//        this->year = y;
//        this->month = m;
//        this->day = d;
//    }
//    void print()
//    {
//        cout << this->day << "/" << this->month << "/" << this->year << endl;
//    }
//private:
//    int year;
//    int month;
//    int day;
//};
//int main()
//{
//    int year;
//    int month;
//    int day;
//    cin >> year >> month >> day;
//    TDate D(year, month, day);
//    D.print();
//    return 0;
//}


/*10.题目描述：小乐乐的班主任想统计一下班级里一共有多少人需要被请家长，三个成绩（语文，数学，外语）
平均分低于60的将被请家长，小乐乐想编程帮助班主任算一下有多少同学被叫家长。
输入描述:共n+1行
第一行，输入一个数n，代表小乐乐的班级中有n个同学。
在接下来的n行中每行输入三个整数代表班级中一个同学的三科成绩（语文，数学，外语），用空格分隔。
输出描述:一行，一个整数，代表班级中需要被请家长的人数。*/
//#include<stdio.h>
//int main()
//{
//    int n, arr[3];
//    scanf("%d", &n);
//    int count = 0;
//    while (n)
//    {
//        int sum = 0;
//        for (int i = 0; i < 3; i++)
//        {
//            scanf("%d", &arr[i]);
//            sum += arr[i];
//        }
//        if ((sum / 3.0) < 60)
//        {
//            count++;
//        }
//        n--;
//    }
//    printf("%d", count);
//    return 0;
//}