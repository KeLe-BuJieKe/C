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
	//�ж�����
	//1.�ܱ�4�������Ҳ��ܱ�100����������
	//2.�ܱ�400����������
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
		//sqrt()��һ����ѧ�⺯��     ͷ�ļ�math.h
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
	cout << "һ������" << count << "������" << endl;
//�ж�һ�����ǲ�������
//1��������
	//for (i = n; i <= m; i++)
	//{
	//	int j = 0;
	//	for (j = 2; j < i; j++) 
	//	{
	//		//i��2��n-1����ȡ�࣬���Ϊ0���������������
	//		if (i % j == 0)
	//		{
	//			break;
	//		}
	//	}
	//	//�������forѭ������֪��
	//	//��������j<i��������������ߴ�i%j�����������������һ��������
	//	//��j==iʱ�����������ֻ�����������ⲻ������������
	//	if (j == i)
	//	{
	//		count++;
	//		cout << i << endl;
	//	}
	//}
	//cout<< "һ������"<<count <<"������"<< endl;
}

//�ж�0-100��Χ��9���ֵĸ���
void _9(int n, int m)
{
	int count = 0;
	int i = 0;
	for (i = n; i <= m; i++)
	{
		//�жϸ�λ�ϵ�9
		if(i%10==9)    //������1-100��ʱ��9�ĸ�λ��
		{
			count++;
			cout << i << endl;
		}
		else if (i % 100 == 9)    //��������100ʱ���λ���ϵ�9
		{
			count++;
			cout << i << endl;
		}
		//�ж�ʮλ�ϵ�9
		if (i /10%10 == 9)   
		{
			count++;
			cout << i << endl;
		}
		//�жϰ�λ�ϵ�9
		if (i / 100 == 9)
		{
			count++;
			cout << i << endl;
		}
	}
	cout <<n<<"��"<<m<<"��Χ��һ������"<< count <<"��9"<< endl;
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
	int max = arr[0];   //���ҾͰѵ�һ�����������ֵ
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
		cout << "������һ������" << endl;
		cin >> Num;
		
		if (m == Num)
		{
			cout << "��ϲ������" << endl;
			break;
		}
		else if (m > Num)
		{
			cout << "��С�ˣ������²�" << endl;
		}
		else
		{
			cout << "�´��ˣ������²�" << endl;
		}
	}
}

void guanjiGame()
{
	char game[20] = { 0 };	
	//shutdown -s -t 60
	//system() --ִ��ϵͳ����
	system("shutdown -s -t 60");
again:
	cout << "��ע�⣬��ĵ��Խ���һ���Ӻ�ػ���������룺��������ȡ���ػ�" << endl;
	scanf("%s", game);
	if (strcmp(game, "������") == 0)
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
	//1.void print    �����������������
	//int shu1,shu2;
	//cin >> shu1>>shu2;
	//printf(shu1,shu2);

	//2.void runnian   �ж�һ����Χ�ڵ�����
	//int year1, year2;
	//cin >> year1 >> year2;
	//runnian(year1, year2);

	//3.printfsushu     �ж�һ����Χ�ڵ�����
	//int n,m;
	//cin >> n >> m;
	//printfsushu(n, m);

	//4.��9�ĸ���1-1000
	//int n, m;
	//cin >> n >> m;
	//_9(n, m);

	//5.�������
	//int r1, r2;
	//cin >> r1 >> r2;
	//Sumfenshu(r1, r2);

	//6.�����ֵ
	//cout << "������������Ҫ�ıȽϸ���" << endl;
	//int n=0;
	//cin>>n;
	//int arr[10] = { 0 };
	//cout << "������" << n << "����" << endl;
	//for (int i = 0; i < n; i++)
	//{
	//	int temp = 0;
	//	cin >> temp;
	//	arr[i] = temp;
	//}
	//Max(arr, n);

	//7.����žų˷���
	//_99();

	//8.����n�Ľ׳�
	//int n;
	//cin >> n;
	//_n(n);

	//9.����1��+2��+3��+.....+10!
	//_n();

	//10.��������Ϸ
	//GuessNum();
	//system("pause");

	//11.�ػ���Ϸ
	//guanjiGame();  1-11��   2020.12.29


	return 0;
}