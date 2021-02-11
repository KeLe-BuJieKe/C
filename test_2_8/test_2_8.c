#define _CRT_SECURE_NO_WARNINGS 1

//下面程序的运行结果是：
//#include<stdio.h>
//int main()
//{
//	int i, j, a = 0;
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if (j % 2)
//			{
//				break;
//			}
//			a++;
//		}
//		a++;
//	}
//	printf("%d\n", a);				//--------4
//	system("pause");
//	return 0;
//}



/*算法题*/
/*在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数，。时间复杂度O（row+col）*/
//#include<stdio.h>
//int find(int *arr, int key,int row,int col)
//{
//	if (NULL!=arr&&row > 0 && col > 0)
//	{
//		int x = 0;
//		int y = col - 1;
//		while (x <row && y >= 0)
//		{
//			if (arr[x * row + y] == key)
//			{
//				return 1;
//			}
//			else if (arr[x * row + y] < key)
//			{
//				x++;
//			}
//			else
//			{
//				y--;
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	//数组样例：
//	int arr[4][4] = { 1,2,8, 9,
//					  2,4,9, 12,
//				      4,7,10,13,
//				      6,8,11,15 };
//	int key;
//	printf("请输入要查找的数字\n");
//	scanf("%d", &key);
	/*把二维数组强转为int*，当成一维数组来访问*/
//	if (find((int *)arr, key, 4, 4) == 1)
//	{
//		printf("该数组中含有%d\n", key);
//	}
//	else
//	{
//		printf("该数组中没有%d\n", key);
//	}
//
//	return 0;
//}



/*智力题*/
/*有1000瓶药物，但是其中有一瓶是有毒的，小白鼠吃了一个星期以后就会死掉！，请问，在一个星期内找出有毒的药物，最少需要多少只小白鼠*/
