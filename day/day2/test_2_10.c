#define _CRT_SECURE_NO_WARNINGS 1

/*��vs�£�����ṹ����ռ�Ŀռ��С�Ƕ����ֽ�*/
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct
//{
//	int a;  //4		
//	char b;	//1
//	short c;//2
//	short d;//2
//}AA_t;
//int main()
//{
//	printf("%d\n", sizeof(AA_t));		//----12
//	system("pause");
//	return 0;
//}



//a��ֵΪ��
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	a += a *= a -= a / 3;
//	printf("%d\n", a);	//--98
//	return 0;
//}


//���³�����whileѭ���ᷢ��ʲô��
//int  main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		if (i < 1)			//iһֱ����0��һֱ��ѭ��
//		{
//			continue;
//		}
//		if (i == 5)
//		{
//			break;
//		}
//		i++;
//	}
//}



/*�㷨��
Ҫ��дһ�����������ַ����еĿո��滻��%20.������"abc defgx yz"ת����abc%20defgx%20yz*/

//�Լ�������
#include<stdio.h>
#include<assert.h>
//char* str---����   int len----�����С
void  Replace(char* str,int len)
{
	assert(str != NULL && len != 0);
	int i = 0;				//�����±�
	int numlen = 0;			//�����ַ�����
	int numBlank = 0;		//����ո����
	for (i = 0;str[i] != '\0'; i++)
	{
		numlen++;
		if (str[i] == ' ')
		{
			numBlank++;
		}
	}
	int newlen = numlen + 2 * numBlank;    //����������С
	if (newlen > len)					   //����������Сһ��ҪС��ԭ��������ܴ�С����Ȼ��Խ��
	{
		return;
	}
	int tempnumlen = numlen;
	int tempnewlen = newlen;

	//ֻ�ý�����û�пո�Ҳ����tempnewlen==tempnumlenʱ�����Ч��
	while (tempnumlen>=0&&tempnewlen>tempnumlen)
	{
		if(str[tempnumlen]==' ')
		{
			str[tempnewlen--] = '0';
			str[tempnewlen--] = '2';
			str[tempnewlen--] = '%';
		}
		else
		{
			str[tempnewlen--] = str[tempnumlen];
		}
		tempnumlen--;
	}

}
int main()
{
	char arr[30]= "abc defgx yz";
	int len = sizeof(arr) / sizeof(arr[0]);
	Replace(arr,len);
	printf("%s\n", arr);
	return 0;
}



/*������
A��B��C��D�ĸ��ˣ�Ҫ��ҹ���һ���š�����ͨ�������ŷֱ���Ҫ��ʱ1��2��5��10���ӣ�ֻ��һ֧�ֵ磬����ͬʱ���ֻ��������һ����š�
���ʣ���ΰ��ţ��ܹ���17���������ĸ��˶����ţ�*/

//�������
