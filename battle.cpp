#include "battle.h"

//struct Piece piece;

//双人对战
//（1）按esc可以终止游戏（2）按上下左右的按键，改变棋子位置（3）按回车键或空格键落子
void playTwoPersonChess(struct Piece &piece)
{
    setcaption("五子棋小游戏--双人对战");
    displayboard();
    randomize();//随机数初始化
    playMelody();
    /**
    第一步：判断是否点击鼠标左键
    第二步：获取鼠标点击位置
    第三步：判断鼠标点击位置是否在棋格上，是否已经有子
    第四步：落子
    第五步：在结构体中更改state的值
    **/
    piece.player = 1;//黑棋先下

    while(1)
    {
        mouseControl();
        if(isValidMouse(&piece.x, &piece.y) == 1)//判断能否落子
        {
            generateChess();
            piece.state[a][b] = piece.player;
            //改变数据状态

            if( judgeWinLoss( a, b , piece) == 1 )//判断是否出现胜负
            {
                delay_ms(1000);
                break;
            }

            //切换黑白双方
            piece.player = (piece.player == 1) ? 2 : 1;
        }

    }
    return;
}


void playAIChess(struct Piece &piece)
{

    setcaption("五子棋小游戏--人机对战");
    displayboard();
    randomize();//随机数初始化
    playMelody();
    //人先走棋

    while(1)
    {
            mouseControl();
            //判断能否落子
            if(isValidMouse(&piece.x, &piece.y) == 1){

                piece.player = MAN;
                //改变数据状态
                generateChess();
                piece.state[a][b] = MAN;

                //判断是否出现胜负
                if( judgeWinLoss( a, b, piece) == 1 ){
                    delay_ms(1000);
                    return;
                }

                ChessEngine::nextStep(a,b);
                ChessEngine::Position tmp;
                tmp = ChessEngine::getLastPosition();
                piece.state[tmp.x][tmp.y] = AI;
                piece.x = 50 + 25 * tmp.x;
                piece.y = 50 + 25 * tmp.y;
                piece.player = AI;
                generateChess();

                //判断是否出现胜负
                if( judgeWinLoss( tmp.x, tmp.y, piece) == 1 ){
                    delay_ms(1000);
                    return;
                }

            }//end inner if
    }//end outer if

    //game ended
    return;
}

//判断输赢
//出现输赢返回1，未出现返回0
//若落子后棋盘布满棋子。显示平局
int judgeWinLoss( int a, int b, struct Piece &piece)
{
    int winloss = 0;
    //in total there are 20 situations
    //第一大类：横
    //@####
    if( a + 4 < N//防止越界
            &&piece.state[a][b] == piece.state[a + 1][b]
            &&piece.state[a][b] == piece.state[a + 2][b]
            &&piece.state[a][b] == piece.state[a + 3][b]
            &&piece.state[a][b] == piece.state[a + 4][b])
    {
        winloss = 1;
        return winloss;
    }

    //#@###
    if( a + 3 < N
            &&a - 1 >= 0
            &&piece.state[a][b] == piece.state[a - 1][b]
            &&piece.state[a][b] == piece.state[a + 1][b]
            &&piece.state[a][b] == piece.state[a + 2][b]
            &&piece.state[a][b] == piece.state[a + 3][b])
    {
        winloss = 1;
        return winloss;
    }

    //##@##
    if( a - 2 >= 0
            &&a + 2 < N
            &&piece.state[a][b] == piece.state[a - 2][b]
            &&piece.state[a][b] == piece.state[a - 1][b]
            &&piece.state[a][b] == piece.state[a + 1][b]
            &&piece.state[a][b] == piece.state[a + 2][b])
    {
        winloss = 1;
        return winloss;
    }

    //###@#
    if( a + 1 < N
            &&a - 3 >= 0
            &&piece.state[a][b] == piece.state[a - 3][b]
            &&piece.state[a][b] == piece.state[a - 2][b]
            &&piece.state[a][b] == piece.state[a - 1][b]
            &&piece.state[a][b] == piece.state[a + 1][b])
    {
        winloss = 1;
        return winloss;
    }

    //####@
    if( a - 4 >= 0
            &&piece.state[a][b] == piece.state[a - 4][b]
            &&piece.state[a][b] == piece.state[a - 3][b]
            &&piece.state[a][b] == piece.state[a - 2][b]
            &&piece.state[a][b] == piece.state[a - 1][b])
    {
        winloss = 1;
        return winloss;
    }

    //第二大类：竖
    //@####
    if( a + 4 < N
            &&piece.state[a][b] == piece.state[a][b + 1]
            &&piece.state[a][b] == piece.state[a][b + 2]
            &&piece.state[a][b] == piece.state[a][b + 3]
            &&piece.state[a][b] == piece.state[a][b + 4])
    {
        winloss = 1;
        return winloss;
    }

    //#@###
    if( a + 3 < N
            &&a - 1 >= 0
            &&piece.state[a][b] == piece.state[a][b - 1]
            &&piece.state[a][b] == piece.state[a][b + 1]
            &&piece.state[a][b] == piece.state[a][b + 2]
            &&piece.state[a][b] == piece.state[a][b + 3])
    {
        winloss = 1;
        return winloss;
    }

    //##@##
    if( a - 2 >= 0
            &&a + 2 < N
            &&piece.state[a][b] == piece.state[a][b - 2]
            &&piece.state[a][b] == piece.state[a][b - 1]
            &&piece.state[a][b] == piece.state[a][b + 1]
            &&piece.state[a][b] == piece.state[a][b + 2])
    {
        winloss = 1;
        return winloss;
    }

    //###@#
    if( a - 3 >= 0
            &&a + 1 < N
            &&piece.state[a][b] == piece.state[a][b - 3]
            &&piece.state[a][b] == piece.state[a][b - 2]
            &&piece.state[a][b] == piece.state[a][b - 1]
            &&piece.state[a][b] == piece.state[a][b + 1])
    {
        winloss = 1;
        return winloss;
    }

    //####@
    if( a - 4 >= 0
            &&piece.state[a][b] == piece.state[a][b - 4]
            &&piece.state[a][b] == piece.state[a][b - 3]
            &&piece.state[a][b] == piece.state[a][b - 2]
            &&piece.state[a][b] == piece.state[a][b - 1])
    {
        winloss = 1;
        return winloss;
    }

    //第三大类：捺
    //@####
    if( a + 4 < N
            &&b + 4 < N
            &&piece.state[a][b] == piece.state[a + 1][b + 1]
            &&piece.state[a][b] == piece.state[a + 2][b + 2]
            &&piece.state[a][b] == piece.state[a + 3][b + 3]
            &&piece.state[a][b] == piece.state[a + 4][b + 4])
    {
        winloss = 1;
        return winloss;
    }

    //#@###
    if( a - 1 >= 0
            &&b - 1 >= 0
            &&a + 3 < N
            &&b + 3 < N
            &&piece.state[a][b] == piece.state[a - 1][b - 1]
            &&piece.state[a][b] == piece.state[a + 1][b + 1]
            &&piece.state[a][b] == piece.state[a + 2][b + 2]
            &&piece.state[a][b] == piece.state[a + 3][b + 3])
    {
        winloss = 1;
        return winloss;
    }

    //##@##
    if( a - 2 >= 0
            &&b - 2 >= 0
            &&a + 2 < N
            &&b + 2 < N
            &&piece.state[a][b] == piece.state[a - 2][b - 2]
            &&piece.state[a][b] == piece.state[a - 1][b - 1]
            &&piece.state[a][b] == piece.state[a + 1][b + 1]
            &&piece.state[a][b] == piece.state[a + 2][b + 2])
    {
        winloss = 1;
        return winloss;
    }

    //###@#
    if( a - 3 >= 0
            &&b - 3 >= 0
            &&a + 1 < N
            &&b + 1 < N
            &&piece.state[a][b] == piece.state[a - 3][b - 3]
            &&piece.state[a][b] == piece.state[a - 2][b - 2]
            &&piece.state[a][b] == piece.state[a - 1][b - 1]
            &&piece.state[a][b] == piece.state[a + 1][b + 1])
    {
        winloss = 1;
        return winloss;
    }

    //####@
    if( a - 4 >= 0
            &&b - 4 >= 0
            &&piece.state[a][b] == piece.state[a - 4][b - 4]
            &&piece.state[a][b] == piece.state[a - 3][b - 3]
            &&piece.state[a][b] == piece.state[a - 2][b - 2]
            &&piece.state[a][b] == piece.state[a - 1][b - 1])
    {
        winloss = 1;
        return winloss;
    }

    //第四大类：撇
    //@####
    if( a + 4 >= 0
            &&b - 4 >= 0
            &&piece.state[a][b] == piece.state[a + 1][b - 1]
            &&piece.state[a][b] == piece.state[a + 2][b - 2]
            &&piece.state[a][b] == piece.state[a + 3][b - 3]
            &&piece.state[a][b] == piece.state[a + 4][b - 4])
    {
        winloss = 1;
        return winloss;
    }

    //#@###
    if( a - 1 >= 0
            &&b - 3 >= 0
            &&a + 3 < N
            &&b + 1 < N
            &&piece.state[a][b] == piece.state[a - 1][b + 1]
            &&piece.state[a][b] == piece.state[a + 1][b - 1]
            &&piece.state[a][b] == piece.state[a + 2][b - 2]
            &&piece.state[a][b] == piece.state[a + 3][b - 3])
    {
        winloss = 1;
        return winloss;
    }

    //##@##
    if( a - 2 >= 0
            &&b - 2 >= 0
            &&a + 2 < N
            &&b + 2 < N
            &&piece.state[a][b] == piece.state[a - 2][b + 2]
            &&piece.state[a][b] == piece.state[a - 1][b + 1]
            &&piece.state[a][b] == piece.state[a + 1][b - 1]
            &&piece.state[a][b] == piece.state[a + 2][b - 2])
    {
        winloss = 1;
        return winloss;
    }

    //###@#
    if( a - 3 >= 0
            &&b - 1 >= 0
            &&a + 1 < N
            &&b + 3 < N
            &&piece.state[a][b] == piece.state[a - 3][b + 3]
            &&piece.state[a][b] == piece.state[a - 2][b + 2]
            &&piece.state[a][b] == piece.state[a - 1][b + 1]
            &&piece.state[a][b] == piece.state[a + 1][b - 1])
    {
        winloss = 1;
        return winloss;
    }

    //####@
    if( a - 4 >= 0
            &&b + 4 < N
            &&piece.state[a][b] == piece.state[a - 4][b + 4]
            &&piece.state[a][b] == piece.state[a - 3][b + 3]
            &&piece.state[a][b] == piece.state[a - 2][b + 2]
            &&piece.state[a][b] == piece.state[a - 1][b + 1])
    {
        winloss = 1;
        return winloss;
    }

    return winloss;
}
