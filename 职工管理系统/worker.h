#pragma once
#include<iostream>
using namespace std;
#include<string>

//ְ��������
class Worker
{
public:

	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;

	//��ȡ��λ����
	virtual string GetDeptName() = 0;

	//ְ�����
	int m_Id;

	//ְ������
	string m_Name;

	//���ű��
	int m_DeptId;
};