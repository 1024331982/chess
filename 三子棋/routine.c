#define _CRT_SECURE_NO_WARNINGS 1
#include "routine.h"
#include <stdio.h>
void InitBoard(char chessboard[ROW][LINE], int row, int line)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < line; j++)
		{
			chessboard[i][j] = ' ';
		}
	}
}

void DisplayBoard(char chessboard[ROW][LINE], int row, int line)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < line; j++)
		{
			printf(" %c ", chessboard[i][j]);
			if (j < line - 1)
				printf("|");
		}
		printf("\n");
		for (j = 0; j < line; j++)
		{
			printf("---");
			if (j < line - 1)
				printf("|");
		}
		printf("\n");
	}
}

void playermove(char chessboard[ROW][LINE], int row, int line)
{
	int x = 0;
	int y = 0;
	printf("玩家走\n");
	printf("请输入坐标:>");
aoa:scanf("%d%d", &x, &y);
	while (1)
	{
		if (x >= 1 && x <= row && y >= 1 && y <= line)
		{
			if (chessboard[x - 1][y - 1] == ' ')
			{
				chessboard[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用,请重新输入坐标:>");
				goto aoa;
			}
		}
		else
		{
			printf("请重新输入坐标:>");
		}
	}
}

void computermove(char chessboard[ROW][LINE], int row, int line)
{
	int x = 0;
	int y = 0;
	printf("电脑走\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % line;
		if (chessboard[x][y] == ' ')
		{
			chessboard[x][y] = '#';
			break;
		}
	}
}

int isfull(char chessboard[ROW][LINE], int row, int line)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < line; y++)
		{
			if (chessboard[x][y] == ' ')
				return 0;
		}
	}
	return 1;
}
char iswin(char chessboard[ROW][LINE], int row, int line)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (chessboard[i][0] == chessboard[i][1] && chessboard[i][1] == chessboard[i][2] && chessboard[i][1] != ' ')
		{
			return chessboard[i][0];
		}
	}
	for (i = 0; i < line; i++)
	{
		if (chessboard[0][i] == chessboard[1][i] && chessboard[1][i] == chessboard[2][i] && chessboard[1][i] != ' ')
		{
			return chessboard[0][i];
		}
	}
	if (chessboard[0][0] == chessboard[1][1] && chessboard[1][1] == chessboard[2][2] && chessboard[1][1] != ' ')
		return chessboard[0][0];
	if (chessboard[0][2] == chessboard[1][1] && chessboard[1][1] == chessboard[2][1] && chessboard[1][1] != ' ')
		return chessboard[1][1];
	if (isfull(chessboard, ROW, LINE) == 0)
	{
		return 'C';
	}
	if (isfull(chessboard, ROW, LINE) == 1)
	{
		return 'Q';
	}
}