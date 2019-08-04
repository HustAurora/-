#pragma GCC optimize(3)
/**
作者：信卓1801陈映李

名称：五子棋小游戏(14*14棋盘)

时间：2019.1.22

规则：（一）双人对战
两人轮流使用鼠标落子
若连成五子，游戏结束
若中途退出游戏，可按Esc键
若棋盘上落满棋子仍未分出胜负，显示平局。
    （二）人机对战
人先行，机器自动应对
采用算法：
博弈树,alpha-beta剪枝,加入启发式搜索,每层选取最有可能出现的10种可能,增量式的评分算法,置换表,AC算法（用于模式匹配）
应用：
1.结构体数组
2.全局变量的应用
3.按键的处理
4.图形库
**/

#include "battle.h"
#include "settings.h"

int main()
{
    initgraph( 640, 449 );//打开一个长640像素，宽600像素的窗口
    setcaption("五子棋小游戏");
    while(1)
    {
        if ( welcome() == 1 )
        {
            playTwoPersonChess(piece);
        }
        if ( welcome()  == 2 )
        {
            ChessEngine::beforeStart();
            ChessEngine::setLevel(3);
            playAIChess(piece);
            ChessEngine::reset(0);
        }
        if ( welcome() == 3 )
        {
            break;
        }
        restartGame();
    }
    closegraph();//关闭绘图窗口
    return 0;
}






