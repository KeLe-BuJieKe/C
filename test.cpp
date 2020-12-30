#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdio.h>
#include<time.h>
void printf(int n1,int n2)
{
	int temp = 0;;
	while (n1%n2)
	{
		temp = n1 % n2;
		n1 = n2;
		n2 = temp;
	}
	cout << temp << endl;
}

void runnian(int year1,int year2)
{
	//判断闰年
	//1.能被4整除并且不能被100整除是闰年
	//2.能被400整除是闰年
	int count = 0;
	int i = 0;
	for (i = year1; i < year2; i++)
	{
		if (i % 4 == 0 && i % 100 != 0)
		{
			count++;
			cout << i << endl;
		}
		else if (i % 400 == 0)
		{
			count++;
			cout << i << endl;
		}
	}
	cout << count << endl;
}

void printfsushu(int n,int m)
{
	int count = 0;
	int i = 0;
	for (i = n; i <= m; i++)
	{
		int j = 0;
		//sqrt()是一个数学库函数     头文件math.h
		for(j=2;j<=sqrt(i);j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j >sqrt(i)&&i!=1)
		{
			count++;
			cout << i << endl;
		}
	}
	cout << "一共共有" << count << "个素数" << endl;
//判断一个数是不是素数
//1不是素数
	//for (i = n; i <= m; i++)
	//{
	//	int j = 0;
	//	for (j = 2; j < i; j++) 
	//	{
	//		//i与2→n-1个数取余，如果为0，则该数不是素数
	//		if (i % j == 0)
	//		{
	//			break;
	//		}
	//	}
	//	//由上面的for循环可以知道
	//	//当不满足j<i这个条件跳出或者从i%j中跳出，则表明该数一定是素数
	//	//当j==i时，则表明该数只有它本身以外不再有其他因数
	//	if (j == i)
	//	{
	//		count++;
	//		cout << i << endl;
	//	}
	//}
	//cout<< "一共共有"<<count <<"个素数"<< endl;
}

//判断0-100范围内9出现的个数
void _9(int n, int m)
{
	int count = 0;
	int i = 0;
	for (i = n; i <= m; i++)
	{
		//判断个位上的9
		if(i%10==9)    //当数是1-100内时求9的个位数
		{
			count++;
			cout << i << endl;
		}
		else if (i % 100 == 9)    //当数大于100时求个位数上的9
		{
			count++;
			cout << i << endl;
		}
		//判断十位上的9
		if (i /10%10 == 9)   
		{
			count++;
			cout << i << endl;
		}
		//判断百位上的9
		if (i / 100 == 9)
		{
			count++;
			cout << i << endl;
		}
	}
	cout <<n<<"到"<<m<<"范围内一共出现"<< count <<"个9"<< endl;
}

void Sumfenshu(int r1,int r2)
{
	int i = 0;
	float sum = 0;
	for (i = r1;i <= r2; i++)
	{
		if (i % 2 == 0)
		{
			sum = sum - 1.0 / i;
		}
		else
		{
			sum = sum +1.0 / i;
		}
	}
	cout << sum << endl;
}

void Max(int arr[],int n)
{
	int max = arr[0];   //暂且就把第一个数当成最大值
	for (int i = 1; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	cout << max << endl;;
}

void _99()
{
	int i = 0;
	for (i = 1; i <= 9; i++)
	{
		int j ;
		for (j = 1; j <=i; j++)
		{
			cout << i << "*" << j << "=" << i * j <<"\t";
		}
		cout << endl;
	}
}

void _n(int n)
{
	int i = 0;
	int temp = 1;
	for (i = 1; i <=n; i++)
	{
		temp = temp * i;
	}
	cout << temp << endl;
}

void _n()
{
	int i = 0;
	int temp = 1;
	int sum = 0;
	for (i = 1; i <= 10; i++)
	{
		temp = temp * i;
		sum = temp + sum;
	}

	cout << sum << endl;
}

void GuessNum()
{
	srand((unsigned int)time(NULL));
	int m= rand() % 100 + 1;
	while (true)
	{
		int Num;
		cout << "请输入一个数字" << endl;
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

void guanjiGame()
{
	char game[20] = { 0 };	
	//shutdown -s -t 60
	//system() --执行系统命令
	system("shutdown -s -t 60");
again:
	cout << "请注意，你的电脑将在一分钟后关机，如果输入：我是猪，就取消关机" << endl;
	scanf("%s", game);
	if (strcmp(game, "我是猪") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
}
int main()
{
	//1.void print    求俩个数得最大公因数
	//int shu1,shu2;
	//cin >> shu1>>shu2;
	//printf(shu1,shu2);

	//2.void runnian   判断一个范围内的闰年
	//int year1, year2;
	//cin >> year1 >> year2;
	//runnian(year1, year2);

	//3.printfsushu     判断一个范围内的素数
	//int n,m;
	//cin >> n >> m;
	//printfsushu(n, m);

	//4.数9的个数1-1000
	//int n, m;
	//cin >> n >> m;
	//_9(n, m);

	//5.分数求和
	//int r1, r2;
	//cin >> r1 >> r2;
	//Sumfenshu(r1, r2);

	//6.求最大值
	//cout << "请输入您所需要的比较个数" << endl;
	//int n=0;
	//cin>>n;
	//int arr[10] = { 0 };
	//cout << "请输入" << n << "个数" << endl;
	//for (int i = 0; i < n; i++)
	//{
	//	int temp = 0;
	//	cin >> temp;
	//	arr[i] = temp;
	//}
	//Max(arr, n);

	//7.输出九九乘法表
	//_99();

	//8.计算n的阶乘
	//int n;
	//cin >> n;
	//_n(n);

	//9.计算1！+2！+3！+.....+10!
	//_n();

	//10.猜数字游戏
	//GuessNum();
	//system("pause");

	//11.关机游戏
	//guanjiGame();  1-11题   2020.12.29


	return 0;
}