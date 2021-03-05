#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdio.h>
#define ROW 3   //行数
#define COL 3   //列数
#include<ctime>
#include<Windows.h>
//菜单函数
void menu();

//初始化棋盘
void InitBoard(char board[ROW][COL]);

//打印棋盘函数
void DisChessBoard(char board[ROW][COL]);

//玩家下棋
void playerMove(char board[ROW][COL]);

//电脑下棋
void computerMove(char board[ROW][COL]);

//判断谁赢、谁输、平局的结果
//告诉我们4种结果
//1.玩家赢----*	
//2.电脑赢----#
//3.平局------Q
//4.继续-----C就是谁都没有赢，并且棋盘也没有满
char isWin(char board[ROW][COL]);

//判断是否满了
bool isFull(char board[ROW][COL]);
