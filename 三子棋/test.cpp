#include"sanzi_chess.h"

//��������Ϸ����
void sanzi_chess_game()
{
	//�ַ�����----����������̵���Ϣ
	char board[ROW][COL] = {0};   
	char ret=0;
	//��ʼ������
	InitBoard(board);

	//��ӡ����
	DisChessBoard(board);
	while (true)
	{
		//���������󣬴�ӡһ��������Ϣ�����ж�һ�����Ӯ��û��
		playerMove(board);
		DisChessBoard(board);
		ret=isWin(board);
		if (ret != 'C')
		{
			break;
		}
		//����������󣬴�ӡһ��������Ϣ�����ж�һ�µ���Ӯ��û��
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
		cout << "���Ӯ" << endl;
		cout << "��ã�������5��󽫻�����" << endl;
		Sleep(5000);
		system("cls");
	}
	else if (ret == '#')
	{
		cout << "����Ӯ" << endl;
		cout << "��ã�������5��󽫻�����" << endl;
		Sleep(5000);
		system("cls");
	}
	else
	{
		cout << "ƽ��" << endl;
		cout << "��ã�������5��󽫻�����" << endl;
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
		cout << "��ѡ��:>" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			sanzi_chess_game();
			break;
		case 0:
			exit(0);
		default:
			cout << "��������������������" << endl;
			cout << "����������󣬽�������" << endl;
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}