#define _CRT_SECURE_NO_WARNINGS 1


//�������ִ�к�n��ֵ���ڣ�
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char a[20];
//	char* p1 = (char*)a;
//	char* p2 = (char*)(a + 5);
//	int  n = p2 - p1;
//	printf("%d", n);			//n==5
//	system("pause");
//	return 0;
//}



//�������ִ�к������ֵ���Ϊ��
//#include<stdio.h>
//#pragma pack(4)
//int main()
//{
//	struct t1
//	{
//		short a;
//		char d;
//		long b;
//		long c;
//	};
//	struct t2
//	{
//		long b;
//		short c;
//		char d;
//		long a;
//	};
//	struct t3
//	{
//		short c;
//		long b;
//		char d;
//		long a;
//	};
//	struct t1 t1;
//	struct t2 t2;
//	struct t3 t3;
//	//					  12		  12		  16
//	printf("%d %d %d", sizeof(t1), sizeof(t2), sizeof(t3));
//	return 0��
//}
//#pragma pack()



//�㷨��
/*дһ��������unsigned int�ͱ���x���ڴ��ж�����1�ĸ���*/
#include<stdio.h>
int find_1(size_t x)
{
	int count = 0;
	while (x)
	{
		x=x&(x - 1);
		count++;
	}
	return count;
}

/*---------------------���Դ���-----------------------*/
int main()
{
	size_t x;
	scanf("%d", &x);
	printf("%d",find_1(x));
	return 0;
}



//������
//������5��5��5��1�������������㣬ÿ�����ֵ��ҽ�����һ�Σ�Ҫ��������ֵΪ24
/*  
5*(5-1/5)=24
*/