#define _CRT_SECURE_NO_WARNINGS 1


//#include<stdio.h>
//#include<stdlib.h>	
////����һ���ṹ������
////����һ��ѧ�����ͣ������ѧ������������ѧ������������
////����ѧ��������-����+�绰+�Ա�+����
//struct stu
//{
//	char name[20];          //����
//	char sex[10];           //�Ա�
//	char phone[20];         //�绰
//	int age;                //����
//}s3,s4;					    //ȫ�ֱ���
//
//struct stu s3;   //ȫ�ֱ���
//int main()
//{
//	//�����Ľṹ��ֲ�����
//	struct stu s1;
//	system("pause");
//	return 0;
//}



//�ṹ���ڴ����
/*���� ��μ��㣿 ���ȵ����սṹ��Ķ������
1. ��һ����Ա����ṹ�����ƫ����Ϊ0�ĵ�ַ����
2. ������Ա����Ҫ���뵽ĳ�����֣������������������ĵ�ַ����
������ = ������Ĭ�ϵ�һ�������� �� �ó�Ա��С�Ľ�Сֵ��
VS��Ĭ�ϵ�ֵΪ8					Linux�е�Ĭ��ֵΪ4
3. �ṹ���ܴ�СΪ����������ÿ����Ա��������һ��������������������
4. ���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ������������������������ṹ��������С������
��������������Ƕ�׽ṹ��Ķ�����������������
*/
//#include<stdio.h>
////��ϰ1
//struct S1
//{
//	char c1;
//	int a;
//	char c2;
//};
////��ϰ2
//struct S2
//{
//	char c1;
//	char c2;
//	int a;
//};
////��ϰ3
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
////��ϰ4-�ṹ��Ƕ������
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//
////����Ĭ�϶�����Ϊ4
//#pragma pack(4)
//struct s
//{
//	char c1;
//	double d;
//};
//#pragma pack()                      
////ȡ�����õ�Ĭ�϶�����
//
//int main()
//{
//	struct S1 s1 = { 0 };
//	printf("%d\n", sizeof(s1));             //---------12
//
//	struct S2 s2 = { 0 };
//	printf("%d\n", sizeof(s2));             //---------8
//
//	struct S3 s3 = { 0 };
//	printf("%d\n", sizeof(struct S3));      //---------16
//
//
//	printf("%d\n",sizeof(struct S4));       //----------32
//
//
//	//������Ĭ�϶�����
//	printf("%d\n", sizeof(struct s));       //-----------12
//	return 0;
//}



#include<stdio.h>
#include<stddef.h>
struct S
{
	char c;
	int i;
	double d;
};
int main()
{
	//offsetof----------����ƫ�����Ƕ���
	//offsetof��һ���꣬���Ǻ���
	//ͷ�ļ�Ϊ----------#include<stddef.h>
	printf("%d\n",offsetof(struct S, c));
	printf("%d\n", offsetof(struct S, i));
	printf("%d\n", offsetof(struct S, d));
	return 0;
}


//offsetofģ��ʵ��