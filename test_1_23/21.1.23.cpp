#define _CRT_SECURE_NO_WARNINGS 1

/*1.题目描述：输入一个十六进制数a，和一个八进制数b，输出a+b的十进制结果（范围-231~231-1）。
输入描述:一行，一个十六进制数a，和一个八进制数b，中间间隔一个空格。
输出描述:一行，a+b的十进制结果。*/
//#include<stdio.h>
//int main()
//{
//    int x;
//    int y;
//    scanf("0x%x 0%o", &x, &y);
//    printf("%d", x + y);
//    return 0;
//}


/*2.题目描述：KiKi非常喜欢网购，在一家店铺他看中了一件衣服，他了解到，如果今天是“双11”（11月11日）则这件衣服打7折，“双12” （12月12日）则这件衣服打8折，如果有优惠券可以额外减50元（优惠券只能在双11或双12使用），求KiKi最终所花的钱数。
输入描述:一行，四个数字，第一个数表示小明看中的衣服价格，第二和第三个整数分别表示当天的月份、当天的日期、第四个整数表示是否有优惠券（有优惠券用1表示，无优惠券用0表示）。
输出描述:一行，小明实际花的钱数（保留两位小数）。（提示：不要指望商家倒找你钱）*/
//#include<stdio.h>
//int main()
//{
//    float price;
//    int month;
//    int day;
//    int coupon;
//    float sum;
//    scanf("%f%d%d%d", &price, &month, &day, &coupon);
//    if (month == 11 && day == 11)
//    {
//        if (coupon == 1)
//        {
//            sum = price * 0.7 - 50;
//        }
//        else
//        {
//            sum = price * 0.7;
//        }
//    }
//    else if (month == 12 && day == 12)
//    {
//        if (coupon == 1)
//        {
//            sum = price * 0.8 - 50;
//        }
//        else
//        {
//            sum = price * 0.8;
//        }
//    }
//    else
//    {
//        if (coupon == 1)
//        {
//            sum = price - 50;
//        }
//        else
//        {
//            sum = price;
//        }
//    }
//    if (sum < 0)
//    {
//        sum = 0;
//    }
//    printf("%.2f", sum);
//    return 0;
//}


/*3.题目描述：变种水仙花数 - Lily Number：把任意的数字，从中间拆分成两个数字，
比如1461 可以拆分成（1和461）,（14和61）,（146和1),
如果所有拆分后的乘积之和等于自身，则是一个Lily Number。
例如：655 = 6 * 55 + 65 * 5
1461 = 1*461 + 14*61 + 146*1
求出 5位数中的所有 Lily Number。
*/
//#include <stdio.h>
//int main() {
//
//    //遍历所有的五位数，从10000开始
//    for (int i = 10000; i <= 99999; i++) {
//        //设置当前和，除数
//        int sum = 0, mod = 10000, cur = i;
//        //循环直到mod/10为0
//        while (mod / 10) {
//            //根据公式计算当前的除数和余数，进行累计求和
//            sum += (cur % mod) * (cur / mod);
//            //更新mod
//            mod /= 10;
//        }
//        //判断是否满足水仙花数
//        if (i == sum)
//            printf("%d ", i);
//    }
//    return 0;
//}


/*4.题目描述：期中考试开始了，大家都想取得好成绩，争夺前五名。从键盘输入n个学生成绩（不超过40个），输出每组排在前五高的成绩。
输入描述:两行，第一行输入一个整数，表示n个学生（>=5），第二行输入n个学生成绩（整数表示，范围0~100），用空格分隔。
输出描述:一行，输出成绩最高的前五个，用空格分隔。*/
//#include<stdio.h>
//int main()
//{
//    int n;
//    int arr[40] = { 0 };
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//        for (int j = 0; j < i; j++)
//        {
//            if (arr[j] < arr[i])
//            {
//                int temp = arr[i];
//                arr[i] = arr[j];
//                arr[j] = temp;
//            }
//        }
//    }
//    for (int i = 0; i < 5; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}


/*5.题目描述:假设你们社团要竞选社长，有两名候选人分别是A和B，社团每名同学必须并且只能投一票，最终得票多的人为社长.
输入描述:一行，字符序列，包含A或B，输入以字符0结束。
输出描述:一行，一个字符，A或B或E，输出A表示A得票数多，输出B表示B得票数多，输出E表示二人得票数相等。*/
//#include<stdio.h>
//int main()
//{
//    char c;
//    int count1 = 0, count2 = 0;
//    while (scanf("%c", &c) != EOF)
//    {
//
//        if (c == '0')
//        {
//            break;
//        }
//        if (c == 'A')
//        {
//            ++count1;
//        }
//        if (c == 'B')
//        {
//            ++count2;
//        }
//    }
//    if (count1 > count2)
//    {
//        printf("A");
//    }
//    else if (count1 < count2)
//    {
//        printf("B");
//    }
//    else
//    {
//        printf("E\n");
//    }
//    return 0;
//}


/*6.题目描述:KiKi想知道他的考试成绩是否完美，请帮他判断。
从键盘输入一个整数表示的成绩，编程判断成绩是否在90~100之间，如果是则输出“Perfect”。
输入描述:多组输入，每行输入包括一个整数表示的成绩（90~100）。
输出描述:针对每行输入，输出“Perfect”。*/
//#include<stdio.h>
//int main()
//{
//    int s;
//    scanf("%d", &s);
//    if (s >= 90 && s <= 100)
//    {
//        printf("Perfect");
//    }
//    return 0;
//}



/*7.题目描述:KiKi想知道他的考试分数是否通过，请帮他判断。从键盘任意输入一个整数表示的分数，编程判断该分数是否在及格范围内，如果及格，即：分数大于等于60分，是输出“Pass”，否则，输出“Fail”。
输入描述:多组输入，每行输入包括一个整数表示的分数（0~100）。
输出描述:针对每行输入，输出“Pass”或“Fail”*/
//#include<stdio.h>
//int main()
//{
//    int a;
//    while (scanf("%d", &a) != EOF)
//    {
//        if (a >= 60)
//        {
//            printf("Pass\n");
//        }
//        else
//        {
//            printf("Fail\n");
//        }
//    }
//    return 0;
//}


/*8.题目描述:KiKi想知道一个整数的奇偶性，请帮他判断。从键盘任意输入一个整数（范围-231~231-1），编程判断它的奇偶性。
输入描述:多组输入，每行输入包括一个整数。
输出描述:针对每行输入，输出该数是奇数（Odd）还是偶数（Even）。*/
//#include<stdio.h>
//int main()
//{
//    int num;
//    while (scanf("%d", &num) != EOF)
//    {
//        if (num % 2 == 0)
//        {
//            printf("Even\n");
//        }
//        else
//        {
//            printf("Odd\n");
//        }
//    }
//    return 0;
//}


/*9.题目描述:KiKi想判断输入的字符是不是字母，请帮他编程实现。
输入描述:多组输入，每一行输入一个字符。
输出描述:针对每组输入，输出单独占一行，判断输入字符是否为字母*/
//#include<stdio.h>
//int main()
//{
//    char c = '0';
//    while (scanf("%c", &c) != EOF)
//    {
//        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
//        {
//            printf("%c is an alphabet.\n", c);
//        }
//        else
//        {
//            printf("%c is not an alphabet.\n", c);
//        }
//        getchar();
//    }
//
//    return 0;
//}


/*10.题目描述KiKi想知道从键盘输入的两个数的大小关系，请编程实现。
输入描述:题目有多组输入数据，每一行输入两个整数（范围（1 ~231-1），用空格分隔。
输出描述:针对每行输入，输出两个整数及其大小关系，数字和关系运算符之间没有空格，*/
//#include<stdio.h>
//int main()
//{
//    int a, b;
//    while (scanf("%d%d", &a, &b) != EOF)
//    {
//        if (a > b)
//        {
//            printf("%d>%d\n", a, b);
//        }
//        else if (a < b)
//        {
//            printf("%d<%d\n", a, b);
//        }
//        else
//        {
//            printf("%d=%d\n", a, b);
//        }
//    }
//    return  0;
//}


/*11.题目描述
在计算BMI（BodyMassIndex ，身体质量指数）的案例基础上，判断人体胖瘦程度。BMI中国标准如下表所示。
输入描述:多组输入，每一行包括两个整数，用空格隔开，分别为体重（公斤）和身高（厘米）。
输出描述:针对每行输入，输出为一行，人体胖瘦程度，即分类。*/
//#include<stdio.h>
//int main()
//{
//    float height;
//    float weight;
//    while (scanf("%f%f", &weight, &height) != EOF)
//    {
//        float bmi = weight / (height / 100.0 * height / 100.0);
//        if (bmi < 18.5)
//        {
//            printf("Underweight\n");
//        }
//        else if (bmi >= 18.5 && bmi <= 23.9)
//        {
//            printf("Normal\n");
//        }
//        else if (bmi > 23.9 && bmi <= 27.9)
//        {
//            printf("Overweight\n");
//        }
//        else
//        {
//            printf("Obese\n");
//        }
//    }
//    return 0;
//}