#define _CRT_SECURE_NO_WARNINGS 1

/*1.问题描述：输入两个整数，求两个整数二进制格式有多少个位不同
输入描述:两个整数
输出描述:二进制不同位的个数*/
//#include<stdio.h>
//int diff_bit(int m, int n)
//{
//    int count = 0, c = 0;
//    c = m ^ n;
//    for (int i = 0; i < 32; i++)
//    {
//        if (((c >> i) & 1) == 1)   //c向右移动一位，如果最后一位是1，c&1，其余前面的就变成了0，只剩最后一位如果等于1，则count++
//        {
//            count++;
//        }
//    }
//    return count;
//}
//int main()
//{
//    int x, y;
//    scanf("%d%d", &x, &y);
//    printf("%d", diff_bit(x, y));
//    return 0;
//}


/*2.作业标题：打印整数二进制的奇数位和偶数位
作业内容：获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列*/
//#include<stdio.h>
//void bitprintf(int x)
//{
//	printf("奇数位：\n");
//	for (int j = 31; j>0; j = j - 2)
//	{
//		printf("%d ", (x>>j) & 1);
//	}
//	printf("\n");
//	printf("偶数位：\n");
//	for (int i = 30; i>=0; i=i-2)
//	{
//		//为什么不选择<<,是因为向左一位，左边抛弃、右边补0
//		//会导致打印出来的数字都是0
//		printf("%d ", (x>>i)&1);           //先向右移i位，在&1，得到最后一位，看到底是0还是1，是1就打印1，否则就打印0
//	}
//}
//int main()
//{
//	int x;
//	printf("请输入一个数：");
//	scanf("%d", &x);
//	bitprintf(x);
//	return 0;
//}


/*3.问题描述：二进制中1的个数
输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。
*/
/*方法一
缺陷：不论是什么数据，循环都要执行32次
*/
//#include<stdio.h>
//int NumberOf1(int m)
//{
//    int count = 0;
//    for (int i = 0; i < 32; i++)
//    {
//        if (((m >> i) & 1) == 1)  
//        {
//            count++;
//        }
//    }
//    return count;
//}
////方法二
////思路：采用相邻的两个数据进行按位与运算
////此种方式，数据的二进制比特位中有几个1，循环就循环几次，而且中间采用了位运算，处理起来比较高效
//int NumberOf1_(int n)
//{
//    int count = 0;                //例如：10的二进制---1010    第一次循环：n=1010&1001=1000  n就等于8  
//                                  //                           第二次循环：n=1000&0111=0000  n就等于0
//    while (n)
//    {
//        n = n & (n - 1);
//        count++;
//    }
//    return count;
//}
//int main()
//{
//    int x;
//    printf("请输入一个数：");
//    scanf("%d", &x);
//    //方法一
//    printf("%d\n",NumberOf1(x));
//    //方法二
//    printf("%d\n", NumberOf1_(x));
//}

//4.下面代码的结果是：（ ）
/*解析：
arr数组在内存中的存储格式为：
0x00ECFBF4:  01 00 00 00
0x00ECFBF8:  02 00 00 00
0x00ECFBFC:  03 00 00 00
0x00ECFC00:  04 00 00 00
0x00ECFC04:  05 00 00 00
指针p的类型为short*类型的，因此p每次只能所有两个字节，for循环对数组中内容进行修改时，一次访问的是：
arr[0]的低两个字节，arr[0]的高两个字节，arr[1]的低两个字节，arr[1]的高两个字节，故改变之后，数组中内容如下：
0x00ECFBF4:  00 00 00 00
0x00ECFBF8:  00 00 00 00
0x00ECFBFC:  03 00 00 00
0x00ECFC00:  04 00 00 00
0x00ECFC04:  05 00 00 00
故最后打印：0   0   3   4   5
*/
//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5 };
//    short* p = (short*)arr;        //■在此翻车，保证以后不犯
//    int i = 0;
//    for (i = 0; i < 4; i++)
//    {
//        *(p + i) = 0;
//    }
//
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}


/*5.作业标题：使用指针打印数组内容
作业内容写一个函数打印arr数组的内容，不使用数组下标，使用指针。
arr是一个整形一维数组。*/
//#include<stdio.h>
//void _printf(int *arr,int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", *arr);
//		arr++;
//	}
//}
//int main()
//{
//	int arr[5] = {1,2,3,4,5};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	_printf(arr, len);    // 数组名代表数组首元素的地址
//	return 0;
//}


/*6.问题描述：字符逆序
将一个字符串str的内容颠倒过来，并输出。str的长度不超过100个字符。*/

//方法一（递归）
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


//方法二（循环）
//#include<stdio.h>
//#include<string.h>
//void reverse_string(char* str)
//{
//    int len = strlen(str);
//    int left = 0, right = len - 1;
//    while (left < right)
//    {
//        char temp = str[left];
//        str[left] = str[right];
//        str[right] = temp;
//        left++;
//        right--;
//    }
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


/*7.作业标题:计算求和
作业内容:求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
例如：2+22+222+2222+22222*/
//#include<stdio.h>
//int Sn(int a)
//{
//	int temp = 0, sum = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		temp = a + temp*10;
//		sum += temp;
//	}
//	return sum;	
//}
//int main()
//{
//	int a;
//	scanf("%d",&a);
//	printf("前5项和为%d",Sn(a));
//	return 0;
//}


/*8.作业标题:打印水仙花数
作业内容：求出0～100000之间的所有“水仙花数”并输出。
“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。*/
//#include<stdio.h>
//#include<math.h>
//int Power(int i)        //求几位数
//{
//	int temp =i,count=1;
//	while (temp/10)
//	{
//		count++;
//		temp=temp / 10;
//	}
//	return count;
//}
//void Narcissistic_number()
//{
//	for (int i =0; i < 100000; i++)
//	{
//		int sum = 0,temp=i;
//		while (temp)
//		{
//			sum += pow(temp% 10, Power(i));
//			temp = temp / 10;
//		}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//}
//int main()
//{
//	Narcissistic_number();
//	return 0;
//}



/*9.作业标题：打印菱形*/
//#include<stdio.h>
//void printf_diamond()
//{
//	for (int i =0; i<13; i+=2)
//	{
//		for (int j = 0; j < 13 - i; j += 2)
//		{
//			printf("  ");
//		}
//		for (int k = 0; k < i + 1; k++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//
//	for (int i = 0; i <11; i += 2)
//	{
//		printf("  ");
//		for (int j = 0; j <=i; j++)
//		{
//			printf(" ");
//		}
//		for (int k = 0; k < 11 - i; k++)
//		{
//			printf(" *");
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	printf_diamond();
//	return 0;
//}


/*10.作业标题:喝汽水问题
作业内容:喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）。*/
//方法一
//#include<stdio.h>
//int Drink_soda(int money)
//{
//	int sum=money;              //先初始化为money，因为有多少钱就可以喝多少瓶汽水
//	int empty_bottle= money;    //一开始有多少钱就有多少个空瓶，所以初始为money
//	while (empty_bottle>1)
//	{
//		sum +=empty_bottle/ 2;     //等于每回合空瓶的数量除以2
//		empty_bottle =empty_bottle/ 2 + empty_bottle% 2;   //--------等于每回合换的汽水数+剩余空瓶
//	}
//	return sum;
//}
//int main()
//{
//	int money;
//	printf("请输入你有多少钱：");
//	scanf("%d", &money);
//	printf("%d", Drink_soda(money));
//	return 0;
//}
// 方法二：按照上述喝水和用瓶子换的规则的话，可以发现，其实就是个等差数列：money*2-1
//#include<stdio.h>
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	scanf("%d", &money);
//	//方法2
//	if (money <= 0)
//	{
//		total = 0;
//	}
//	else
//	{
//		total = money * 2 - 1;
//	}
//	printf("total = %d\n", total);
//
//
//	return 0;
//}

/*11.问题描述：将一个字符串str输出*/
//#include<stdio.h>
//#include<string.h>
//循环方法
//void print(char* ch)
//{
//    int len = strlen(ch);
//    for (int i = len-1; i>=0; i--)
//    {
//        printf("%c", ch[i]);
//
//    }
//}

//递归方法
//void print(char* ch)
//{
//	if(*ch!= '\0')
//	{
//		print(ch + 1);
//	}
//	if (*ch != '\0')
//	{
//		printf("%c", *ch);
//	}
//	
//}
//int main()
//{
//    char arr[100];
//    gets(arr);   //gets()读取一行字符串
//    print(arr);
//    return 0;
//}