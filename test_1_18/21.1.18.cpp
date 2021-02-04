#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stdio.h>
#include<time.h>
#include<math.h>
//��ŵ������
void move(char c1, char c2)
{
	static int count = 1;
	cout << count << "." << c1 << "->" << c2 << endl;
	count++;
}
void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
	{
		move(x, z);
	}
	else
	{
		hanoi(n - 1, x, z, y);
		move(x, z);
		hanoi(n - 1, y, x, z);
	}

}

void swap1(int& a, int& b)
{
	//���ֵ����ֹ���ʱ����������
	a = a + b;
	b = a - b;
	a = a - b;
}

void swap2(int& a, int& b)
{
	//a��b��λ���   ����aΪ1---�൱��001   bΪ2---�൱��010  ��ͬΪ0������Ϊ1
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//�ж������ε�����
void iftge()
{
	int  a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) != EOF)
	{
		if (a + b > c && a + c > b && c + b > a)
		{
			if (a == b && b == c)
			{
				printf("Equilateral triangle!\n"); //�ȱ�
			}
			else if ((a == b && b != c) || (a == c && c != b) || (b == c && c != a))
			{
				printf("Isosceles triangle!\n");//����
			}
			else
			{
				printf("Ordinary triangle!\n");//��ͨ
			}
		}
		else
		{
			//����
			printf("Not a triangle!\n");
		}
	}

}

int max(int x, int y)
{
	return x > y ? x : y;
}

//��1-N���м���ż������������
void base_evennumber()
{
	int N;
	int base = 0;
	int evennumber = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		if (i % 2 != 0)
		{
			base++;
		}
		else
		{
			evennumber++;
		}
	}
	printf("��������Ϊ��%d ż������Ϊ��%d", base, evennumber);
}

//�������ε��ܳ������
void area_per()
{
	int a = 0, b = 0, c = 0;
	scanf("%d%d%d", &a, &b, &c);
	float len = a + b + c;
	float p = (a + b + c) / 2.0;
	float area = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("circumference=%.2f area=%.2f", len, area);
}

//6
void max_min(int a, int b, int c)
{
	if (a < b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	if (a < c)
	{
		a = a ^ c;
		c = a ^ c;
		a = a ^ c;
	}
	if (b < c)
	{
		b = b ^ c;
		c = b ^ c;
		b = b ^ c;
	}
	printf("max=%d second=%d min=%d", a, b, c);
}

void Common_divisor(int a, int b)
{
	int temp = 0;
	while (a % b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	if (a == b)    //���a��b��ȣ���ô���Ǳ���������Լ��
	{
		goto again;
	}
again:	printf("���Լ��=%d", b);
}

void _9num()
{
	int count = 0;
	int a = 100;
	while (a--)
	{
		if (a % 10 == 9)
		{
			count++;
		}
		if (a / 10 == 9)
		{
			count++;
		}
	}
	printf("9�ĸ���Ϊ��%d", count);
}

void _3_multiple()
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			printf("%d ", i);
		}
	}
}

void _max(int arr[], int len)
{
	int max = arr[0];   //�Ȱ�����ĵ�һ��Ԫ�ص������ֵ
	for (int i = 0; i < len; i++)
	{
		if (arr[0] < arr[i])
		{
			max = arr[i];
		}
	}
	printf("���ֵΪ��%d", max);
}

void _99multiplication()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d\t", i, j, i * j);
		}
		printf("\n");
	}
}

void leap_year()
{
	//�ж�����
	//1.�ܱ�4�������Ҳ��ܱ�100����������
	//2.�ܱ�400����������
	int count = 0;
	int i = 0;
	for (i = 1000; i < 2000; i++)
	{
		if (i % 4 == 0 && i % 100 != 0)
		{
			count++;
			printf("%d ", i);
		}
		else if (i % 400 == 0)
		{
			count++;
			printf("%d ", i);
		}
	}
	printf("����Ϊ��%d", count);
}

void prime_number()
{
	int count = 0;
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		int j = 0;
		//sqrt()��һ����ѧ�⺯��     ͷ�ļ�math.h
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i) && i != 1)
		{
			count++;
			printf("%d\n", i);
		}
	}
	printf("һ������%d������\n", count);
}

void fraction_sum()
{
	float sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 != 0)
		{
			sum = sum + 1.0 / i;
		}
		else
		{
			sum = sum - 1.0 / i;
		}
	}
	printf("%f", sum);
}

void Half_search(int arr[], int len, int X)
{
	int i = 0;
	int j = len - 1;
	while (i <= j)
	{
		int mid = i+(j-i)/2;
		if (X > arr[mid])
		{
			i = mid + 1;
		}
		else if (X < arr[mid])
		{
			j = mid - 1;
		}
		else
		{
			printf("�ҵ����±�Ϊ��%d", mid);
			break;
		}
	}
	if (j < i)
	{
		printf("û�ҵ�");
	}
}
int main()
{
	//1.��ŵ������
		/*
		hanoi����
		����������1.����������X,Y,Z,X������nֻ����
				  2.ÿ���ƶ� һ����ӣ�С��ֻ�ܵ��ڴ������
				  3.�����е��Ӵ�X�˾�Y��ȫ���Ƶ�Z����
		�ݹ���⣺1.��ֻ��һ�����ӣ�ֱ�ӽ�����X���ƶ���Z��
				  2.
				  (1)��n-1ֻ���Ӱ���С�ݼ��Ĵ����X�˾�Z���ƶ���Y�ˣ�
				  (2)��X���ϵ�nֻ�����ƶ���Z�ˣ�
				  (3)Ȼ���ٽ�n-1ֻ���Ӱ���С�ݼ��Ĵ����Y�˾�X���ƶ���Z��
		*/
		//int n;
		//cout << "��������ٸ�����" << endl;
		//cin >> n;
		//hanoi(n, 'a', 'b', 'c');

		//2.��ʹ�õ��������������ݽ���
		//int a, b;
		//cin >> a >> b;
		//swap2(a, b);
		//swap1(a, b);
		//cout << "a=" << a << "  b=" << b;

		//3.���������е����ֵ
		//int a=0, b=0;
		//scanf("%d%d", &a, &b); 
		//printf("%d", max(a, b));

		//4.��֪���Ѿ�������������a��b��c�ܷ񹹳������Σ�����ܹ��������Σ��ж������ε����ͣ��ȱ������Ρ����������λ���ͨ�����Σ���
		//iftge();

		//5.��������һ��������N��ͳ��1~N֮�������ĸ�����ż���ĸ������������
		//һ�У�һ��������N����1��N��100,000��
		//һ�У�1~N֮�������ĸ�����ż���ĸ������ÿո�ֿ���
		//base_evennumber();

		//6.д���뽫���������Ӵ�С���
		//int a, b, c;
		//scanf("%d%d%d", &a, &b, &c);
		//max_min(a,b,c);

		//7.���������������������������Լ��
		//int a,b;
		//scanf("%d%d", &a, &b);
		//Common_divisor(a, b);

		//8.��д������һ��1��100�����������г��ֶ��ٸ�����9
		//_9num();

		//9.дһ�������ӡ1-100֮������3�ı���������
		/*_3_multiple();*/

		//10.��10�����������ֵ
		//int arr[10];
		//for (int i = 0; i < 10; i++)
		//{
		//	scanf("%d", &arr[i]);
		//}
		//int len = sizeof arr /sizeof arr[0];
		//_max(arr,len);

		//11.����Ļ�����9*9�˷��ھ���
		/*_99multiplication();*/

		//12.��ӡ1000�굽2000��֮�������
		//leap_year();


		//13.дһ�����룺��ӡ100~200֮�������
		//prime_number();


		//14.����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ����ӡ�����
		/*fraction_sum();*/


		//15.��д������һ���������������в��Ҿ����ĳ����
		//Ҫ���ҵ��˾ʹ�ӡ�������ڵ��±꣬�Ҳ�����������Ҳ�����
		//int arr[10] = {1,2,3,4,5,6,7,8,9,10};
		//int len = 0;
		//len = sizeof arr / sizeof arr[0];
		//int x;
		//printf("��������Ҫ���ҵ����֣�");
		//scanf("%d",&x);
		//Half_search(arr,len,x);
	return 0;
}