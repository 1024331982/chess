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
		printf("���Ӯ��\n");
	}
	else if (num == '#')
		printf("����Ӯ��\n");
	else if (num == 'Q')
	{
		printf("ƽ��\n");
	}
}
void routine()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		start();
		printf("������:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("��Ч������������\n");
			break;
		}
	} while (input);
}
int main(void)
{
	routine();
	return 0;
}