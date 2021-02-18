#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "routine.h"
void start()
{
	printf("*******************************\n");
	printf("*****1.play           0.end****\n");
	printf("*******************************\n");
}
void game()
{
	char num = 0;
	char chessboard[ROW][LINE] = { 0 };
	InitBoard(chessboard, ROW, LINE);
	DisplayBoard(chessboard, ROW, LINE);
	iswin(chessboard, ROW, LINE);
	while (1)
	{
		playermove(chessboard, ROW, LINE);
		DisplayBoard(chessboard, ROW, LINE);
		num = iswin(chessboard, ROW, LINE);
		if (num != 'C')
		{
			break;
		}
		computermove(chessboard, ROW, LINE);
		DisplayBoard(chessboard, ROW, LINE);
		num = iswin(chessboard, ROW, LINE);
		if (num != 'C')
		{
			break;
		}
	}
	if (num == '*')
	{
		printf("玩家赢了\n");
	}
	else if (num == '#')
		printf("电脑赢了\n");
	else if (num == 'Q')
	{
		printf("平局\n");
	}
}
void routine()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		start();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("无效，请重新输入\n");
			break;
		}
	} while (input);
}
int main(void)
{
	routine();
	return 0;
}