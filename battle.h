#ifndef BATTLE_H_INCLUDED
#define BATTLE_H_INCLUDED


#include "settings.h"
#include "ChessEngine.h"

void playTwoPersonChess();
int judgeWinLoss( int a, int b ,struct Piece &piece);
void playTwoPersonChess(struct Piece &piece);

void playAIChess(struct Piece &piece);
#endif // BATTLE_H_INCLUDED
