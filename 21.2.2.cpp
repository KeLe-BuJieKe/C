#define _CRT_SECURE_NO_WARNINGS 1

//1.���ú���ָ������ļ�����
//#include<stdio.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("��******************************��\n");
//	printf("��  1.add             2.sub     ��\n");
//	printf("��  3.mul             4.div     ��\n");
//	printf("��  0.exit                      ��\n");
//	printf("��******************************��\n");
//
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//
//int sub(int x, int y)
//{
//	return x - y;
//}
//
//int mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//
//	int input = 0;
//	int x, y;
//	//����ָ������---ת�Ʊ�
//	//�Ѻ����������ָ������
//	int (*pArr[])(int, int) = { 0,add,sub,mul,Div };
//
//	while (true)
//	{
//		menu();
//		printf("��ѡ��>\n");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("�˳�������\n");
//			exit(0);
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("������2����������>\n");
//			scanf("%d %d", &x, &y);
//			int ret = pArr[input](x, y);
//			printf("ret=%d\n", ret);
//		}
//		else
//		{
//			printf("ѡ�����������ѡ��\n");
//		}
//		system("pause");
//		system("cls");
//	}
//	return 0;
//}


//2.�����ص��ļ�����
//#include<stdio.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("��******************************��\n");
//	printf("��  1.add             2.sub     ��\n");
//	printf("��  3.mul             4.div     ��\n");
//	printf("��  0.exit                      ��\n");
//	printf("��******************************��\n");
//
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//
//int sub(int x, int y)
//{
//	return x - y;
//}
//
//int mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
////��������-����ָ��
////�ص�����
//void calc(int(* p)(int, int))//����ָ��
//{
//	int x, y;
//	printf("������2����������>\n");
//	scanf("%d %d", &x, &y);
//	int ret = p(x, y);
//	printf("ret=%d\n", ret);
//}
//int main()
//{
//
//	int input = 0;
//	
//
//	while (true)
//	{
//		menu();
//		printf("��ѡ��>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(add);   
//			break;
//		case 2:
//			calc(sub);
//			break;
//		case 3:
//			calc(mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		case 0:
//			printf("�˳�������\n");
//			exit(0);
//		default:
//			printf("ѡ�����������ѡ��\n");
//			break;
//		}
//		system("pause");
//		system("cls");
//	}
//	return 0;
//}


/*3.�ص�����*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void print(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{	
//		printf("%d ", arr[i]);
//	}
//}
//int cmp_int(const void* e1, const void* e2)
//{
//	//����
//	//return (*(int *)e1 - *(int*)e2); 
//
//	//����
//	return (*(int*)e2 - *(int*)e1);
//}
//void test1()
//{
//	//����qsort ����һ����������
//	int arr[] = { 9,0,5,7,6,1,3,2,8 ,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//��Ҫ��ͷ�ļ�---- #include<stdlib.h>
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	print(arr, sz);
//}
//
//struct stu
//{
//	char m_name[20];
//	int  age;
//};
//int cmp_age(const void* e1, const void* e2)
//{
//	//����������
//	return (*(stu*)e1).age - (*(stu*)e2).age;
//
//	//�����併��
//	//return (*(stu*)e2).age - (*(stu*)e1).age;
//}
//int cmp_name(const void* e1, const void* e2)
//{
//	//����������
//	return strcmp((*(stu*)e1).m_name,(*(stu*)e2).m_name);
//
//	//�����ֽ���	
//	//return strcmp((*(stu*)e2).m_name,(*(stu*)e1).m_name);
//}
//
//void test2()
//{
//	//ʹ��qsort��������ṹ��
//	stu arr[] = { {"zhansan",20},{"lisi",30},{"wangwu",10} };
//	int sz=sizeof(arr) / sizeof(arr[0]);
//	//����������
//	qsort(arr, sz, sizeof(arr[0]), cmp_age);  //-----qsort�ĵ��ĸ������Ǻ���ָ��
//
//	//����������
//	qsort(arr, sz, sizeof(arr[0]), cmp_name);
//}
//int main()
//{	
//	//test1();
//	test2();
//	return 0;
//}


//4.��bobble_sortģ��qsort����
/*void* base----���������ݵ���ʼλ��
size_t size---- Ԫ�ظ���
size_t width----һ��Ԫ�صĴ�С
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void _swap(char* buf1, char* buf2, size_t width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		//һ���ֽ�һ���ֽڵĽ���
		char temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void* base, size_t size, size_t width, int (*cmp)(const void* e1, const void* e2))
{
	size_t i = 0;
	for (i = 0; i < size - 1; i++)
	{
		size_t j = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			//��������Ԫ�صıȽ�
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//���������˳��ͽ���
				_swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

struct stu
{
	char m_name[20];  //����

	int  age;         //����
};

int cmp_age(const void* e1, const void* e2)
{
	//����������
	return (*(stu*)e1).age - (*(stu*)e2).age;

	//�����併��
	//return (*(stu*)e2).age - (*(stu*)e1).age;
}

int cmp_name(const void* e1, const void* e2)
{
	//����������
	return strcmp((*(stu*)e1).m_name, (*(stu*)e2).m_name);

	//�����ֽ���	
	//return strcmp((*(stu*)e2).m_name,(*(stu*)e1).m_name);
}

void test3()
{
	stu arr[] = { {"zhansan",20},{"lisi",30},{"wangwu",10} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//����������
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_age);
	//����������
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_name);
}

int main()
{
	test3();
}