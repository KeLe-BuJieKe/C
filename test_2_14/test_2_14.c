#define _CRT_SECURE_NO_WARNINGS 1


/*malloc����*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<errno.h>
//int main()
//{
//	
//	int n;
//	scanf("%d", &n);
//	//malloc���ڴ�����n�����οռ�
//	/*����������ڴ�����һ���������õĿռ䣬������ָ�����ռ��ָ�롣
//	������ٳɹ����򷵻�һ��ָ�򿪱ٺÿռ��ָ�롣
//	�������ʧ�ܣ��򷵻�һ��NULLָ�룬���malloc�ķ���ֵһ��Ҫ����顣*/
//	int* p = (int*)malloc(n*sizeof(int));
//	
//	if (NULL == p)
//	{
//		//��ӡ������Ϣ
//		printf("%s",strerror(errno));
//	}
//	else
//	{
//		//����ʹ�ÿռ�
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			*(p + i) = i;
//			printf("%d ", *(p + i));
//		}
//	}
//	//����̬����Ŀռ䲻��ʹ��ʱ
//	//��������ϵͳ
//	/*free���������ͷŶ�̬���ٵ��ڴ档
//	������� ptr ָ��Ŀռ䲻�Ƕ�̬���ٵģ���free��������Ϊ��δ����ġ�
//	������� ptr ��NULLָ�룬����ʲô�¶�����*/
//	free(p);
//	p = NULL;
//	return 0;
//}





/*calloc����*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<errno.h>
//int main()
//{
//	/*C���Ի��ṩ��һ�������� calloc �� calloc ����Ҳ������̬�ڴ���䡣ԭ�����£�
//	void *calloc( size_t num, size_t size );
//	�����Ĺ�����Ϊ num ����СΪ size ��Ԫ�ؿ���һ��ռ䣬���Ұѿռ��ÿ���ֽڳ�ʼ��Ϊ0��
//	�뺯�� malloc ������ֻ���� calloc ���ڷ��ص�ַ֮ǰ������Ŀռ��ÿ���ֽڳ�ʼ��Ϊȫ0��*/
//	int n;
//	scanf("%d", &n);
//	//calloc���ڴ�����n�����οռ�
//	int* p = (int*)calloc(n,sizeof(int));
//	
//	if (NULL == p)
//	{
//		//��ӡ������Ϣ
//		printf("%s",strerror(errno));
//	}
//	else
//	{
//		//����ʹ�ÿռ�
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			//calloc�������ڴ��ֵȫ����ʼ��Ϊ0
//			printf("%d ", *(p + i));
//		}
//	}
//	//�ͷſռ�
//	free(p);
//	p = NULL;
//	return 0;
//}




/*realloc����*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main()
{
	int* p = (int*)malloc(20);
	if (NULL == p)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p + i)=i;
		}
	}
	//������ʹ��malloc���ٵ�20���ַ��ռ�
	//�������20���ֽڲ����������ǵ������ˣ�ϣ�������ܹ���40���ֽڵĿռ䣬�������ǾͿ���ʹ��remalloc��������̬���ٵ��ڴ�
	//����ԭ��----void *realloc( void *memblock, size_t size );
	//void *memblock-----��Ҫ�������ڴ��ַ   size_t size-----����֮���µĴ�С
	//����ֵΪ����֮����ڴ���ʼλ��	


	//reallocʹ�õ�ע������
	//1.���pָ��Ŀռ�֮�����㹻���ڴ�ռ����׷�ӣ���ֱ��׷�ӣ��󷵻�p
	//2.���pָ��Ŀռ�֮��û���㹻���ڴ�ռ����׷�ӣ���realloc������������һ���µ��ڴ�����
	//  ����һ����������Ŀռ䣬���Ұ�ԭ���ڴ��е����ݿ����������ͷžɵ��ڴ�ռ䣬��󷵻��¿��ٵ��ڴ�ռ��ַ
	//3.����һ���µı���������realloc�����ķ���ֵ

	int* ptr =(int *)realloc(p, 40);
	//��ֹ����ʧ�ܣ�ʹ��ԭ����p�Ҳ�����
	if (NULL != ptr)
	{
		p = ptr;

		//ʹ����չ���ڴ��
		int i = 0;
		for (int i = 5; i < 10; i++)
		{
			*(p + i) = i;
		}

		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}

	//�ͷ��ڴ�
	free(p);
	p = NULL;
	return 0;
}