#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdio.h>
#define ROW 3   //����
#define COL 3   //����
#include<ctime>
#include<Windows.h>
//�˵�����
void menu();

//��ʼ������
void InitBoard(char board[ROW][COL]);

//��ӡ���̺���
void DisChessBoard(char board[ROW][COL]);

//�������
void playerMove(char board[ROW][COL]);

//��������
void computerMove(char board[ROW][COL]);

//�ж�˭Ӯ��˭�䡢ƽ�ֵĽ��
//��������4�ֽ��
//1.���Ӯ----*	
//2.����Ӯ----#
//3.ƽ��------Q
//4.����-----C����˭��û��Ӯ����������Ҳû����
char isWin(char board[ROW][COL]);

//�ж��Ƿ�����
bool isFull(char board[ROW][COL]);
