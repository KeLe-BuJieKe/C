#define _CRT_SECURE_NO_WARNINGS 1


//ģ��ʵ��atoi 
//#include<stdio.h>
//#include<limits.h>
//#include<ctype.h>
////���������
///*
//1.���������ǿ��ַ���
//2.���������ǿ�ָ��
//*/
//enum State
//{
//	VALID,		//�Ϸ���״̬
//	NOVALID		//���Ϸ���״̬
//};
//
//enum State state = NOVALID;
//
//int  my_atoi(const char*str)
//{
//	//1.���������ǿ��ַ���
//	if (str == NULL)
//	{
//		return 0;
//	}
//	//2.���������ǿ�ָ��
//	else if (*str == '\0')
//	{
//		return 0;
//	}
//	//3.һ������ǰ�����ַ��ǿո��������ո�
//	while (*str== ' ')
//	{
//		str++;
//	}
//
//	//�ж����������Ǹ���
//	int flag = 1;
//	if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	else if(*str == '+')
//	{
//		flag = 1;
//		str++;
//	}
//	int num = 0;
//	while (*str!='\0')
//	{
//		//isdigit��һ���ж��Ƿ������ֵĺ���
//		if (isdigit(*str))
//		{
//			num = num * 10 + flag*(*str- '0');
//			//�ж��Ƿ����
//			if (num > INT_MAX || num < INT_MIN)
//			{
//				return 0;
//			}
//		}
//		else
//		{
//			return 0;
//		}
//
//		str++;
//	}
//	state = VALID;
//	return num;
//}
////--------------���Դ���--------------------
//int main()
//{
//	int ret = my_atoi("0");
//	if (state == VALID)
//	{
//		printf("�Ϸ�:%d\n", ret);
//	}
//	else
//	{
//		printf("���Ϸ�\n");
//	}
//	
//	return 0;
//}




//дһ���꣬���Խ�һ�������Ķ�����λ������λ��ż��λ������
#include<stdio.h>
#define SWAP(X) (((X&0x55555555)<<1)|(X&0xaaaaaaaa)>>1)

int main()
{
	int temp = SWAP(100);
	//1.����������е�ż��λ����������Ϊ0
	//	�ѵõ������֣������ƶ�һλ
	//2.����������е�����λ������ż��Ϊ0
	//  �ѵõ������֣������ƶ�һλ
	//3.��ǰ��õ���2�����ְ�λ��
	printf("%d\n", temp);
	return 0;
}