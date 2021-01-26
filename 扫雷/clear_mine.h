#pragma once   //防止头文件重复包含
#define _CRT_SECURE_NO_WARNINGS 1
//设置棋盘的大小
#define ROW 9           
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define mine_size 10
#include<stdio.h>
#include <stdlib.h>
#include<time.h>

//菜单函数
void menu();


//初始化棋盘
/*
第二个参数rows-------需要操作的行数
第三个参数cols-------需要操作的列数
第四个参数ch  -------初始化的值
*/
void InitBoard(char arr[ROWS][COLS],int rows,int cols,char ch);


//打印棋盘
/*
第二个参数rows-------需要操作的行数
第三个参数cols-------需要操作的列数
*/
void DisplayBoard(char arr[ROWS][COLS], int row, int col);


//布置雷
/*
第一个参数arr ------存放雷的信息
第二个参数rows------需要操作的行数
第三个参数cols------需要操作的列数
第四个参数size------设置雷的个数
*/
void set_mine(char arr[ROWS][COLS],int row,int col,int size);


//排雷
/*
第三个参数rows------需要操作的行数
第四个参数cols------需要操作的列数
*/
void find_mine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);


//统计x、y周围雷的个数
/*
x---------横坐标
y---------纵坐标
*/
int Getmine_size(char mine[ROWS][COLS], int x, int y);
