#pragma once
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define LINE 3
void InitBoard(char chessboard[ROW][LINE], int row, int line);
void DisplayBoard(char chessboard[ROW][LINE], int row, int line);
void playermove(char chessboard[ROW][LINE], int row, int line);
void computermove(char chessboard[ROW][LINE], int row, int line);
char iswin(char chessboard[ROW][LINE], int row, int line);