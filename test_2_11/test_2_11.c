#define _CRT_SECURE_NO_WARNINGS 1


//����ĳ����������Ƕ���
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int a = 5;
//	if (a = 0)			//�����a��ֵΪ0�������ж�a�Ƿ����0������==
//	{
//		printf("%d", a - 10);
//	}
//	else
//	{
//		printf("%d", a++);		//�ȴ�ӡaΪ0��Ȼ��������
//	}
//	system("pause");
//	return 0;
//}



//�����´���
//#include<string.h>
//#include<stdio.h>
//int main()
//{
//	char acHello[] = "hello\0world";
//	char acNew[15] = { 0 };
//	strcpy(acNew, acHello);
//
//	/*�������*/
//	int len = strlen(acNew);
//	int size = sizeof(acHello);
//	printf("%d %d", len, size);			//len==5   size==12
//	return 0;	
//}



//�㷨��
//��д���������n��쳲��������е�ֵ�ǵݹ�
//#include<stdio.h>
//long long fib(long long n)
//{
//	long long a = 1;
//	long long b = 1;
//	long long c = 1;
//	while(n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n;
//	printf("���������֪������쳲�������Ϊ��");
//	scanf("%d", &n);
//	printf("%lld\n",fib(n));
//	return 0;
//}



//������
/*��50���˼ң�ÿ��һ��������һ�쾯��֪ͨ��50���������в�������Ϊ����������һ��*/

//�������