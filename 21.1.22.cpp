#define _CRT_SECURE_NO_WARNINGS 1

/*1.问题描述：不使用累计乘法的基础上，通过移位运算（<<）实现2的n次方的计算。
输入描述：多组输入，每一行输入整数n（0 <= n < 31）。
输出描述：针对每组输入输出对应的2的n次方的结果。*/
//#include<stdio.h>
//int main()
//{
//    int a;
//    while (scanf("%d", &a) != EOF)
//    {
//        //1向左移动a位
//        printf("%d\n", 1<<a);     //向左移动一位等于原来数的俩倍  例如：2向左移动一位就等于4
//    }
//    return 0;
//}


/*2.问题描述：BoBo买了一箱酸奶，里面有n盒未打开的酸奶，
KiKi喜欢喝酸奶，第一时间发现了酸奶。KiKi每h分钟能喝光一盒酸奶，
并且KiKi在喝光一盒酸奶之前不会喝另一个，那么经过m分钟后还有多少盒未打开的酸奶？*/
//#include<stdio.h>
//int main()
//{
//    int n;   //一箱有n盒
//    int h;   //h分钟喝完一盒酸奶
//    int m;   //经过m分钟
//    
//    while (scanf("%d %d %d",&n,&h,&m)!= EOF)
//    {
//        if (m % h == 0)
//        {
//            printf("%d", n - m / h );
//        }
//        else
//        {
//            printf("%d", n - m / h-1);
//        }
//    }
//    return 0;
//}


/*3.问题描述：递归方式实现打印一个整数的每一位*/
//#include<stdio.h>
//void print(int m)
//{
//	if (m > 9)
//	{
//		print(m / 10);
//	}
//	printf("%d ", m%10);
//	
//}
//int main()
//{
//	int x;
//	printf("请输入你要打印的数字：");
//	scanf("%d", &x);
//	print(x);
//	return 0;
//}


/*4.问题描述：递归和非递归分别实现求n的阶乘（不考虑溢出的问题）*/
//#include<stdio.h>
//int fac1(int n)   //递归
//{
//	if (n<=1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n* fac1(n - 1);
//	}
//}
//
//int fac2(int n)  //非递归
//{
//	int temp = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		temp *= i;
//	}
//	return temp;
//}
//int main()
//{
//	int x;
//	printf("请输入您想要求几的阶乘：");
//	scanf("%d", &x);
//	int f1=fac1(x);
//	printf("递归:  %d\n", f1);
//	int f2=fac2(x);
//	printf("非递归:%d", f2);
//	return 0;
//}


/*5.问题描述：递归和非递归分别实现strlen*/
//#include<stdio.h>
//int my_strlen1(char *arr)   //递归
//{
//	if (*arr != '\0')
//	{
//		return 1 + my_strlen1(++arr);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int my_strlen2(char* arr)   //非递归
//{
//	int count = 0;
//	while(*arr != '\0')
//	{
//		++arr;
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "dasfas";
//	int  temp1=my_strlen1(arr);  //递归
//	printf("递归:  %d\n", temp1);
//	int  temp2=my_strlen2(arr);  //非递归
//	printf("非递归:%d", temp2);
//	return 0;
//}


/*6.问题描述：字符串逆序（递归实现）
编写一个函数 reverse_string(char * string)（递归实现）
实现：将参数字符串中的字符反向排列。
要求：不能使用C函数库中的字符串操作函数。*/
//#include<stdio.h>
//#include<string.h>
//void reverse_string(char*arr)
//{
//	int len = strlen(arr);
//	char temp = *arr;
//	*arr = *(arr + len - 1);
//	*(arr + len - 1) = '\0';
//
//	if (strlen(arr + 1) >= 2)
//	{
//		reverse_string(arr + 1);
//	}
//	*(arr + len - 1) = temp;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s", arr);
//	return 0;
//}


/*7.问题描述：写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19
输入：1729，输出：19*/
//#include<stdio.h>
//int DigitSum(int num)
//{
//	while (num % 10)
//	{
//		if (num < 9)
//		{
//			return num;
//		}
//		return num % 10 + DigitSum(num / 10);
//	}
//}
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	int temp=DigitSum(num);
//	printf("%d", temp);
//}


/*8.问题描述：编写一个函数实现n的k次方，使用递归实现。*/
//#include<stdio.h>
//double pow(double n, double k)
//{
//	if (k==0)           //通过判断k（系数）是否为0，为零就直接返回1
//	{
//		return 1;
//	}
//	return n * pow(n, k - 1);
//	
//}
//int main()
//{
//	double n, k;
//	scanf("%lf%lf", &n,&k);
//	double temp=pow(n, k);
//	printf("%lf", temp);
//	return 0;
//}


/*9.问题描述：计算斐波那契数
递归和非递归分别实现求第n个斐波那契数
例如：
输入：5  输出：5
输入：10， 输出：55
输入：2， 输出：1*/
//#include<stdio.h>
//int Fib1(int num)          //递归
//{
//	if (num <= 2)
//	{
//		return 1;
//	}
//	return Fib1(num - 1)+Fib1(num - 2);
//}
//
//int Fib2(int num)          //非递归
//{
//	int a = 1, b = 1, c = 1;
//	while (num > 2)
//	{
//		c = a + b;        
//		a = b;
//		b = c;
//		num--;
//	}
//	return c;
//}
//
//int main()
//{
//	int num;
//	printf("请输入您想要查看的第几个斐波那契数：");
//	scanf("%d", &num);
//	int temp1=Fib1(num);     //递归
//	printf("%d\n", temp1);
//
//	int temp2 = Fib2(num);   //非递归
//	printf("%d", temp2);
//	return 0;
//}


/*10.问题描述：学生信息管理系统是学校教学管理的重要工具，现有一名学生基本信息如下：
姓名-Jack，年龄-18，性别-Man，请按照输出样例的格式输出该学生的信息。*/
//#include<stdio.h>
//int main()
//{
//    printf("Name    Age    Gender\n");
//    printf("---------------------\n");
//    printf("Jack    18     man\n");
//    return 0;
//}


/*11.问题描述：从键盘输入5个学生的成绩（整数），求他们的平均成绩（浮点数，保留一位小数）。
输入描述:一行，连续输入5个整数（范围0~100），用空格分隔。
输出描述:一行，输出5个数的平均数（保留一位小数）。*/
//#include<stdio.h>
//int main()
//{
//    int arr[5] = { 0 };
//    float sum = 0;
//    for (int i = 0; i < 5; i++)
//    {
//        scanf("%d", &arr[i]);
//        sum += arr[i];
//    }
//    printf("%.1f", sum / 5.0);
//    return 0;
//}


/*12.问题描述：从键盘任意输入一个字符，编程判断是否是字母（包括大小写）。
输入描述:多组输入，每行输入包括一个字符。
输出描述:针对每行输入，输出该字符是字母（YES）或不是（NO）。*/
//#include<stdio.h>
//int main()
//{
//    char c = '0';
//    while (scanf("%c", &c) != EOF)
//    {
//        if (c >= 'A' && c <= 'Z' || c>='a' && c <= 'z')
//        {
//            printf("YES\n");
//        }
//        else
//        {
//            printf("NO\n");
//        }
//        getchar();            //消除换行符的影响
//    }
//    return 0;
//}


/*13.问题描述：BMI指数（即身体质量指数）是用体重公斤数除以身高米数平方得出的数字
例如：一个人的身高为1.75米，体重为68千克，他的BMI=68/(1.75^2)=22.2（千克/米^2）。
当BMI指数为18.5～23.9时属正常，否则表示身体存在健康风险。编程判断人体健康情况。
输入描述:一行，输入一个人的体重（千克）和身高（米），中间用一个空格分隔。
输出描述:一行，输出身体Normal(正常)或Abnormal(不正常)。*/
//#include<stdio.h>
//int main()
//{
//    float height;
//    float weight;
//    scanf("%f%f", &weight, &height);
//    float bmi = weight / (height * height);
//    if (bmi >= 18.5 && bmi <= 23.9)
//    {
//        printf("Normal\n");
//    }
//    else
//    {
//        printf("Abnormal\n");
//    }
//    return 0;
//}