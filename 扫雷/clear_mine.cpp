#include"clear_mine.h"

//菜单函数
void menu()
{
	printf("↑→→→→→→→→→→→→→→→↓\n");
	printf("↑          1.玩游戏            ↓\n");
	printf("↑←←←←←←←←←←←←←←←↓\n");
	printf("↑          0.退出程序          ↓\n");
	printf("↑←←←←←←←←←←←←←←←↓\n");
}

//初始化棋盘函数
void InitBoard(char arr[ROWS][COLS],int rows, int cols, char ch)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = ch;           //把全部元素初始化你设定的值
		}
	}
}

//打印棋盘
void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	printf("-------------------\n");
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);    //列号
	}
	printf("\n");
	for (int i = 1; i<=row; i++)
	{
		printf("%d ", i);    //行号
		for (int j = 1;j <=col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("-------------------\n");
}

//布置雷
void set_mine(char arr[ROWS][COLS], int row, int col, int size)
{
	srand((unsigned int)time(NULL));
	while (size)
	{
		//让电脑随机生成0-8的数加1就变成了生成1-9的数
		int x = rand() % row + 1;    
		int y = rand() % col + 1;

		//判断x、y坐标下有没有雷，没雷就埋个雷
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			size--;
		}
	}
}


//统计x、y周围雷的个数
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
					show_recusion(mine, show, i, j);//递归实现扫雷的扩展
				}
			}
		}
	}
}

//排雷
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int isWin = 0;
	while (isWin<row*col-mine_size)
	{
		printf("请输入要排查雷的坐标:\n");
		int x = 0, y = 0;
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)   //-------坐标合法的情况
		{
			if (mine[x][y] == '1')
			{
				printf("boom！很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//2.该坐标处是不是雷？不是雷，就统计周围雷的个数
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
		else                                            //-------坐标不合法的情况
		{
			printf("坐标有误，请重现输入\n");
		}
	}
	if (isWin == row * col - mine_size)
	{
		printf("恭喜您获胜了！\n");
	}
}