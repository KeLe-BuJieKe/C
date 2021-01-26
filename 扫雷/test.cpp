#include"clear_mine.h"

//ɨ����Ϸ����
void clear_mine()
{
	//�������̶�Ӧ������
	char mine[ROWS][COLS];    //--------��Ų��ú��׵���Ϣ
	char show[ROWS][COLS];    //--------��ŵ����Ų���׵���Ϣ

	//��ʼ������
	InitBoard(mine,ROWS,COLS,'0');   
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//������
	set_mine(mine, ROW, COL, mine_size);
	//DisplayBoard(mine, ROW, COL);     //������Ҫ�����Խ⿪ע�Ͳ鿴���õ��׵���Ϣ

	//����
	find_mine(mine,show,ROW,COL);
}

int main()
{
	while (true)
	{
		int select = 0;
		menu();   //��ӡ�˵�
		printf("��ѡ��");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			clear_mine();
			printf("�����������\n");
			system("pause");
			system("cls");
			break;
		case 0:
			exit(0);
		default:
			printf("������������������,�����������\n");
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}