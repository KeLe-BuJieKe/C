#pragma once
#include"worker.h"
class Manager :public Worker
{
public:

	//���캯��
	Manager(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string GetDeptName();
};