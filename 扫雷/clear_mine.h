#pragma once   //��ֹͷ�ļ��ظ�����
#define _CRT_SECURE_NO_WARNINGS 1
//�������̵Ĵ�С
#define ROW 9           
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define mine_size 10
#include<stdio.h>
#include <stdlib.h>
#include<time.h>

//�˵�����
void menu();


//��ʼ������
/*
�ڶ�������rows-------��Ҫ����������
����������cols-------��Ҫ����������
���ĸ�����ch  -------��ʼ����ֵ
*/
void InitBoard(char arr[ROWS][COLS],int rows,int cols,char ch);


//��ӡ����
/*
�ڶ�������rows-------��Ҫ����������
����������cols-------��Ҫ����������
*/
void DisplayBoard(char arr[ROWS][COLS], int row, int col);


//������
/*
��һ������arr ------����׵���Ϣ
�ڶ�������rows------��Ҫ����������
����������cols------��Ҫ����������
���ĸ�����size------�����׵ĸ���
*/
void set_mine(char arr[ROWS][COLS],int row,int col,int size);


//����
/*
����������rows------��Ҫ����������
���ĸ�����cols------��Ҫ����������
*/
void find_mine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);


//ͳ��x��y��Χ�׵ĸ���
/*
x---------������
y---------������
*/
int Getmine_size(char mine[ROWS][COLS], int x, int y);
