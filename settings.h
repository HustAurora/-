#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#ifndef _SETTINGS_
#define _SETTINGS_



#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

//用于鼠标控制的函数
#include <Windows.h> //电脑键盘感应
#include <math.h>    //确定鼠标位置
#include <mmsystem.h>//获取鼠标位置

#define N 15         //the width of the piece.state
#define CHESS_SIZE 10
#define SQUARE_SIZE 25 //棋格大小
#define AI 2
#define MAN 1
#define INFINITE 100000000

struct Piece
{
    int x;
    int y;
    int state[N][N] = {{0}};//show whether the cell is filled with a chess piece
    //0->no piece 1->black piece 2->white piece
    int player;//1->ready to put down a black piece 2->ready to put down a white piece
};

extern struct Piece piece;
extern int a,b;
extern PIMAGE img;


int welcome();
void displayboard();
void generateChess();

void playMelody();
void restartGame();
void mouseControl();

int isValidMouse( int *x, int *y );//x,y are pixels

#endif // _SETTINGS_


#endif // SETTINGS_H_INCLUDED
