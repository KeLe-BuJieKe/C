#include"sanzi_chess.h"

//三子棋游戏函数
void sanzi_chess_game()
{
	//字符数组----用来存放棋盘的信息
	char board[ROW][COL] = {0};   
	char ret=0;
	//初始化棋盘
	InitBoard(board);

	//打印棋盘
	DisChessBoard(board);
	while (true)
	{
		//玩家下完棋后，打印一下棋盘信息，并判断一下玩家赢了没有
		playerMove(board);
		DisChessBoard(board);
		ret=isWin(board);
		if (ret != 'C')
		{
			break;
		}
		//电脑下完棋后，打印一下棋盘信息，并判断一下电脑赢了没有
		computerMove(board);
		DisChessBoard(board);
		ret=isWin(board);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		cout << "玩家赢" << endl;
		cout << "你好，程序将在5秒后将会清屏" << endl;
		Sleep(5000);
		system("cls");
	}
	else if (ret == '#')
	{
		cout << "电脑赢" << endl;
		cout << "你好，程序将在5秒后将会清屏" << endl;
		Sleep(5000);
		system("cls");
	}
	else
	{
		cout << "平局" << endl;
		cout << "你好，程序将在5秒后将会清屏" << endl;
		Sleep(5000);
		system("cls");
	}

}

int main()
{
	srand((unsigned int)time(NULL));
	while (true)
	{
		menu();
		int select = 0;
		cout << "请选择:>" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			sanzi_chess_game();
			break;
		case 0:
			exit(0);
		default:
			cout << "您输入有误，请重新输入" << endl;
			cout << "您按任意键后，将会清屏" << endl;
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}