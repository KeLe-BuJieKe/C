#pragma once
#include"worker.h"
class Boss :public Worker
{
public:

	//���캯��
	Boss(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string GetDeptName();
};