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
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<assert.h>
//char* change(char* str)
//{
//	assert(str != NULL);
//	int len = strlen(str);  //ȫ���ַ��ĸ���
//	int count = 0;  //�ո�ĸ���
//	char arr[] = "%20";
//	for (int i = 0; i < len; i++)
//	{
//		if (str[i] == ' ')
//		{
//			count++;
//		}
//	}
//	char* s = (char*)malloc(len+ count*3-count);
//	int size = 0;
//	for (int j = 0; j < len; j++)
//	{
//		if (str[j] != ' ')
//		{
//			s[size++] = str[j];
//			
//		}
//		else
//		{
//			s[size++] = '%';
//			s[size++] = '2';
//			s[size++] = '0';
//			
//		}
//	}
//	s[size] = '\0';
//	strcpy(str, s);
//	return str;
//}
//int main()
//{
//	char arr[30]= "abc defgx yz";
//	change(arr);
//	printf("%s\n", arr);
//	return 0;
//}


//������
//#include<stdio.h>
//void ReplaceBlank(char* str, int len)
//{
//	int MLen = 0;//�����ַ��ĸ���
//	int NumBlank=0;//����ո������
//	int IndexofMLen=0;
//	int Indexofnew=0;
//	int newlen=0;
//	int i=0;//��0���±꿪ʼ����
//	if(str==NULL||len<=0)
//	{
//		return;
//	}
//	while(str[i]!='\0')
//	{
//		++MLen;
//		if(str[i]==' ')
//		{
//			++NumBlank;
//		}
//		++i;
//	}
//	newlen=MLen+NumBlank*2;//a%20b%20c%20dabcd
//	if(newlen>len)//newlen�����������Ĵ�С������һ��Ҫ����lenԭ����С����Ȼ�Ų���
//	{
//		return;
//	}
//	IndexofMLen=MLen;
//	Indexofnew=newlen;
//	while(IndexofMLen>=0&&Indexofnew>IndexofMLen)
//	{
//		if(str[IndexofMLen]==' ')
//		{
//			str[Indexofnew--]='0';
//			str[Indexofnew--] = '2';
//			str[Indexofnew--] = '%';
//		}	
//		else 
//		{
//			str[Indexofnew--] = str[IndexofMLen]; 
//		}
//		--IndexofMLen; 
//	}
//}
//int main()
//{ 
//	char str[30] = "abc defgx yz"; 
//	int len = (sizeof(str) / sizeof(str[0])); 
//	ReplaceBlank(str, len);
//	printf("%s\n", str); 
//	return 0; 
//}




/*������
A��B��C��D�ĸ��ˣ�Ҫ��ҹ���һ���š�����ͨ�������ŷֱ���Ҫ��ʱ1��2��5��10���ӣ�ֻ��һ֧�ֵ磬����ͬʱ���ֻ��������һ����š�
���ʣ���ΰ��ţ��ܹ���17���������ĸ��˶����ţ�*/

//�������