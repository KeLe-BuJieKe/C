#include"WorkerManager.h"
#include<iostream>
using namespace std;
int main()
{
	
	//ʵ���������߶���
	WorkerManager wm;

	int choice = 0;  //�����洢�û���ѡ��

	while (true)
	{
     //����չʾ�˵���Ա����
	 wm.Show_Menu();

	 cout << "����������ѡ��:  " << endl;
	 cin >> choice;   //�����û���ѡ��

	 switch (choice)
	 {
	 case 0:           //�˳�ϵͳ
		 wm.ExitSystem();
		 break;
	 case 1:           //����Ա��
		 wm.Add_Emp();
		 break;
	 case 2:           //��ʾԱ��
		 wm.Show_Emp();
		 break;
	 case 3:           //ɾ��Ա��
		 wm.Del_Emp();
		 break;
	 case 4:           //�޸�Ա��
		 wm.Mod_Emp();
		 break;
	 case 5:           //����Ա��
		 wm.Find_Emp();
		 break;
	 case 6:           //����Ա��
		 wm.Sort_Emp();
		 break;
	 case 7:           //����ĵ�
		 wm.Clean_File();
		 break;
	 default:
		 system("cls");
		 break;
	 }
	}
	system("pause");
	return 0;
}