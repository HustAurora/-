#include "settings.h"

struct Piece piece;
int a, b;
PIMAGE img;


//生成棋盘
//从（50,50）开始生成，每个格子大小为25*25
void displayboard()
{
    //generate the background
    PIMAGE img = newimage();
    getimage(img, "D:\\Algorithm&&System\\gobang_game\\background.jpg" );
    putimage( 0, 0, img );

    int i = 0;
    for( i = 0; i < N; i++ )
    {
        //generate vertical lines
        line(50 + SQUARE_SIZE*i, 50, 50 + SQUARE_SIZE*i, 400 );
        //generate horizontal lines
        line(50, 50 + SQUARE_SIZE*i, 400, 50 + SQUARE_SIZE*i );
    }

}

//生成开始界面
//return 1:双人对战
//return 2:人机对战
int welcome()
{
    PIMAGE welcomeimg;
    welcomeimg = newimage();
    getimage( welcomeimg, "D:\\Algorithm&&System\\gobang_game\\welcome.jpg" );
    putimage(0, 0, welcomeimg );

    key_msg k = {0};
    for ( ; k.key != key_esc; ) // key_esc是ege定义的按键常数
    {
        k = getkey();
        break;
    }
    delimage(welcomeimg);

    //1的键值
    if ( k.key ==  49 )
    {
        return 1;
    }
    //2的键值
    if ( k.key == 50 )
    {
        return 2;
    }
    //esc的键值
    if ( k.key == VK_ESCAPE )
    {
        return 3;
    }
}

//判断落子位置是否已经有棋子
//1.不是棋盘上的，返回0
//2.是棋盘上，无子，返回1
//x,y 是鼠标点击位置的像素坐标
int isValidMouse(int *x, int *y)
{
    int i = 0, j = 0;
    int valid = 0;
    for( i = 50; i <= 400; i += SQUARE_SIZE )
    {
        if ( abs(*x - i) <= 5 )//5是点击位置的误差允许
        {
            for( j = 50; j <= 400; j += SQUARE_SIZE )
            {
                if( abs(*y - j) <= 5 )
                    //是棋盘上的交叉点,该交叉点上无棋子,修订x,y的坐标值
                {
                    *x = i;
                    *y = j;
                    a = (i - 50)/SQUARE_SIZE;
                    b = (j - 50)/SQUARE_SIZE;
                    if( piece.state[a][b] == 0 )
                        //无子
                    {
                        valid = 1;
                    }
                    break;
                }
            }
        }
    }

    return valid;
}

//生成棋子
void generateChess()
{
    if ( piece.player == 1 )
    {
        setfillcolor(BLACK);
        fillellipse( piece.x, piece.y, CHESS_SIZE, CHESS_SIZE );//draw a black circle
    }

    if ( piece.player  == 2 )
    {
        setfillcolor(WHITE);
        fillellipse( piece.x, piece.y, CHESS_SIZE, CHESS_SIZE );//draw a white circle
    }

}

void mouseControl()
{
    mouse_msg msg = {0};
    for ( ; is_run(); delay_fps(60) )
    {
        while (mousemsg())
        {
            msg = getmouse();
        }

        if ( msg.is_down() == 1 )
        {
            piece.x = msg.x;
            piece.y = msg.y;
            break;
        }
    }//end for

    return;
}
//播放背景音乐
void playMelody()
{
    mciSendString("open \"D:\\Algorithm&&System\\gobang_game\\纯音乐 - 柔美古筝曲.mp3\" alias file", NULL, 0, NULL );
    mciSendString("play file", NULL, 0, NULL );
}

void restartGame()
{
    delimage(img);
    cleardevice();
    PIMAGE imgwin;
    //if black win, load the game_over image of black_win
    if( piece.player == 1 )
    {
        xyprintf(0,0,"1");
        imgwin = newimage();
        getimage (imgwin, "D:\\Algorithm&&System\\gobang_game\\blackwin.jpg");
        putimage (0, 0, imgwin);
        delay_ms(2000);
    }

    //if white win, load the game_over image of white_win
    if( piece.player  == 2 )
    {
        xyprintf(0,0,"2");
        imgwin = newimage();
        getimage (imgwin, "D:\\Algorithm&&System\\gobang_game\\whitewin.jpg");
        putimage (0, 0, imgwin);
        delay_ms(2000);
    }
}

