#include"clear_mine.h"

//扫雷游戏函数
void clear_mine()
{
	//创建棋盘对应的数组
	char mine[ROWS][COLS];    //--------存放布置好雷的信息
	char show[ROWS][COLS];    //--------存放的是排查出雷的信息

	//初始化棋盘
	InitBoard(mine,ROWS,COLS,'0');   
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//布置雷
	set_mine(mine, ROW, COL, mine_size);
	//DisplayBoard(mine, ROW, COL);     //如有需要，可以解开注释查看布置的雷的信息

	//排雷
	find_mine(mine,show,ROW,COL);
}

int main()
{
	while (true)
	{
		int select = 0;
		menu();   //打印菜单
		printf("请选择：");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			clear_mine();
			printf("按任意键清屏\n");
			system("pause");
			system("cls");
			break;
		case 0:
			exit(0);
		default:
			printf("输入有误请重新输入,按任意键清屏\n");
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}