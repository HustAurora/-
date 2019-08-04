#include "settings.h"

struct Piece piece;
int a, b;
PIMAGE img;


//��������
//�ӣ�50,50����ʼ���ɣ�ÿ�����Ӵ�СΪ25*25
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

//���ɿ�ʼ����
//return 1:˫�˶�ս
//return 2:�˻���ս
int welcome()
{
    PIMAGE welcomeimg;
    welcomeimg = newimage();
    getimage( welcomeimg, "D:\\Algorithm&&System\\gobang_game\\welcome.jpg" );
    putimage(0, 0, welcomeimg );

    key_msg k = {0};
    for ( ; k.key != key_esc; ) // key_esc��ege����İ�������
    {
        k = getkey();
        break;
    }
    delimage(welcomeimg);

    //1�ļ�ֵ
    if ( k.key ==  49 )
    {
        return 1;
    }
    //2�ļ�ֵ
    if ( k.key == 50 )
    {
        return 2;
    }
    //esc�ļ�ֵ
    if ( k.key == VK_ESCAPE )
    {
        return 3;
    }
}

//�ж�����λ���Ƿ��Ѿ�������
//1.���������ϵģ�����0
//2.�������ϣ����ӣ�����1
//x,y �������λ�õ���������
int isValidMouse(int *x, int *y)
{
    int i = 0, j = 0;
    int valid = 0;
    for( i = 50; i <= 400; i += SQUARE_SIZE )
    {
        if ( abs(*x - i) <= 5 )//5�ǵ��λ�õ��������
        {
            for( j = 50; j <= 400; j += SQUARE_SIZE )
            {
                if( abs(*y - j) <= 5 )
                    //�������ϵĽ����,�ý������������,�޶�x,y������ֵ
                {
                    *x = i;
                    *y = j;
                    a = (i - 50)/SQUARE_SIZE;
                    b = (j - 50)/SQUARE_SIZE;
                    if( piece.state[a][b] == 0 )
                        //����
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

//��������
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
//���ű�������
void playMelody()
{
    mciSendString("open \"D:\\Algorithm&&System\\gobang_game\\������ - ����������.mp3\" alias file", NULL, 0, NULL );
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

