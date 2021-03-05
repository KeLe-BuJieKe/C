#include"sanzi_chess.h"

//菜单函数
void menu()
{
	cout << "-----------------------------" << endl;
	cout << "---1.玩游戏     0.退出程序---" << endl;
	cout << "-----------------------------" << endl;

}

//初始化棋盘
void InitBoard(char board[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisChessBoard(char board[ROW][COL])
{
	for (int i = 0; i <ROW; i++)
	{
		for (int j = 0; j <COL; j++)
		{
			//1.打印一行的数据
			cout << ' ' << board[i][j] << ' ';
			if (j<COL-1)
			{
				cout << '|';
			}
		}
		cout << endl;
		//2.打印分割行
		if (i <ROW- 1)
		{
			for (int j = 0; j <COL; j++)
			{
				printf("---");
				if (j <COL-1)
				{
					cout << '|';
				}
			}
			cout << endl;
		}
	}
}

//玩家下棋----*
void playerMove(char board[ROW][COL])
{
	int i, j;
	cout << "玩家下，请输入坐标:(x y)" << endl;
	while (true)
	{
		cin >> i >> j;
		if (i >= 1 && i <= ROW && j >= 1 && j <= COL)
		{
			if (board[i-1][j-1] == ' ')
			{
				board[i-1][j-1] = '*';
				break;
			}
			else
			{
				cout << "位置被占用,请重新输入" << endl;
			}
		}
		else
		{
			cout << "您输入的坐标有误,请重新输入" << endl;
		}
	}
}


//电脑下棋-----#
void computerMove(char board[ROW][COL])
{
	
	cout << "电脑走：>" << endl;
	while (true)
	{
		int i = rand() % 3;
		int j = rand() % 3;
		if (board[i][j ] == ' ')
		{
			board[i][j ] = '#';
			break;
		}
	}
}

//判断是否满了
bool isFull(char board[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				return false;         //没满
			}
		}
	}
	return true;      //满了
}


//判断谁赢、谁输、平局的结果
char isWin(char board[ROW][COL])
{
	//判断俩条对角线是否相等
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}

	//判断每一行是否相等
	for (int i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}

	//判断每一列是否相等
	for (int i = 0; i < ROW; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}

	//判断是否平局
	if (true == isFull(board))
	{
		return 'Q';
	}
	return 'C';
}