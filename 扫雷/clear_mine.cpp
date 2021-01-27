#include"clear_mine.h"

//�˵�����
void menu()
{
	printf("����������������������������������\n");
	printf("��          1.����Ϸ            ��\n");
	printf("����������������������������������\n");
	printf("��          0.�˳�����          ��\n");
	printf("����������������������������������\n");
}

//��ʼ�����̺���
void InitBoard(char arr[ROWS][COLS],int rows, int cols, char ch)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = ch;           //��ȫ��Ԫ�س�ʼ�����趨��ֵ
		}
	}
}

//��ӡ����
void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	printf("-------------------\n");
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);    //�к�
	}
	printf("\n");
	for (int i = 1; i<=row; i++)
	{
		printf("%d ", i);    //�к�
		for (int j = 1;j <=col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("-------------------\n");
}

//������
void set_mine(char arr[ROWS][COLS], int row, int col, int size)
{
	srand((unsigned int)time(NULL));
	while (size)
	{
		//�õ����������0-8������1�ͱ��������1-9����
		int x = rand() % row + 1;    
		int y = rand() % col + 1;

		//�ж�x��y��������û���ף�û�׾������
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			size--;
		}
	}
}


//ͳ��x��y��Χ�׵ĸ���
int Getmine_size(char mine[ROWS][COLS], int x, int y)
{
	int i = 0, j = 0;
	int sum = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			sum += mine[i][j];
		}
	}
	return sum - 9 * '0';

}
void show_recusion(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = 0, j = 0;

	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (show[i][j] != ' ' && i >= 1 && i <= ROW && j >= 1 && j <= COL)
			{
				int temp = Getmine_size(mine, i, j);
				show[i][j] = temp + '0';
				if (show[i][j] == '0')
				{
					show[x][y] = ' ';
					show_recusion(mine, show, i, j);//�ݹ�ʵ��ɨ�׵���չ
				}
			}
		}
	}
}

//����
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int isWin = 0;
	while (isWin<row*col-mine_size)
	{
		printf("������Ҫ�Ų��׵�����:\n");
		int x = 0, y = 0;
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)   //-------����Ϸ������
		{
			if (mine[x][y] == '1')
			{
				printf("boom�����ź����㱻ը����\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//2.�����괦�ǲ����ף������ף���ͳ����Χ�׵ĸ���
				show[x][y] = Getmine_size(mine, x, y)+'0';
				if (show[x][y] == '0')
				{
					show[x][y] = ' ';
					show_recusion(mine, show, x, y);
				}
				DisplayBoard(show, row, col);
				isWin++;
			}
		}
		else                                            //-------���겻�Ϸ������
		{
			printf("������������������\n");
		}
	}
	if (isWin == row * col - mine_size)
	{
		printf("��ϲ����ʤ�ˣ�\n");
	}
}