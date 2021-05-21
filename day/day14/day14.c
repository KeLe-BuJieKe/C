#define _CRT_SECURE_NO_WARNINGS 1


//1.下面代码的输出结果是
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int arr[] = { 6,7,8,9,10 };
//	int* ptr = arr;
//	*(ptr++) += 123;	//此时一开始ptr指向的6，并让它+123==129，并让指针++，指向了7
//	//到了printf它从右往左开始计算，此时先进行++，则ptr指向8这个元素，所以俩个都打印8
//	printf("%d %d\n", *ptr, *(++ptr));		//8   8
//	system("pause");
//	return 0;
//}



//2.下列代码段将打印出
//#include<stdio.h>
//int main()
//{
//	int a = 2, * p1, **p2;
//	p2 = &p1;
//	p1 = &a;
//	a++;
//	printf("%d %d %d", a, *p1, **p2);	//	3		3		3
//	return 0;
//}



//3.程序的运行结果是
//#include<stdio.h>
//int main()
//{
//	int k, j, s;
//	for (k = 2; k < 6; k++, k++)
//	{
//		s = 1;
//		//先看题目，需要我们要打印的是s的值
//		//由于每次循环都会被s重置为1，所以直接把k的最大值带入内层循环，则可以得到
//		//1+4=5   5+5=10
//		for (j = k; j < 6; j++)
//		{
//			s += j;
//		}
//	}
//	printf("%d\n", s);	//		10
//	return 0;
//}



//算法题
/*编写一个函数，求一个数字是否是回文数。回文数概念：给定一个数，这个数顺读和逆读都是一样的。
例如：121，1221是回文数，1123，1231不是回文数。
*/
#include<stdio.h>
#include<stdbool.h>
bool is_Palindrome(int num)
{
	if ((num < 0) || (num % 10 == 0 && num != 0))
	{
		// 特殊情况：
		// 如上所述，当 x < 0 时，x 不是回文数。
		// 同样地，如果数字的最后一位是 0，为了使该数字为回文，
		// 则其第一位数字也应该是 0
		// 只有 0 满足这一属性
		return false;
	}
	int revertedNumber = 0;
	while (num > revertedNumber)
	{
		revertedNumber = revertedNumber * 10 + num % 10;
		num /= 10;
	}
	// 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
	// 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
	// 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
	return num == revertedNumber || num == revertedNumber / 10;

}
//--------------------测试代码-------------------------
int main()
{
	if (is_Palindrome(1111111111))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}



//智力题
/*假设你有8个球，其中一个略微重一些，但是找出这个球的唯一方法是将俩个球放在天平上对比。
最少要称多少次才能找出这个较重的球？*/


/*把8个球分为3个组，每个组的球分别为3、3、2
一开始第1次对比先把两个3个球的放刀天平上对比，如果相等，第2次就对比另外的俩个球	需要两次
如果第1次对比发现两个3个球的那边重，把重的那边的3个球拿出俩个来进行对比第2次，如果那边重，则就是那个。如果一样重，则就是第3个没称量的球
最少需要两次对比
*/