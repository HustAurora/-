#include "battle.h"

//struct Piece piece;

//˫�˶�ս
//��1����esc������ֹ��Ϸ��2�����������ҵİ������ı�����λ�ã�3�����س�����ո������
void playTwoPersonChess(struct Piece &piece)
{
    setcaption("������С��Ϸ--˫�˶�ս");
    displayboard();
    randomize();//�������ʼ��
    playMelody();
    /**
    ��һ�����ж��Ƿ���������
    �ڶ�������ȡ�����λ��
    ���������ж������λ���Ƿ�������ϣ��Ƿ��Ѿ�����
    ���Ĳ�������
    ���岽���ڽṹ���и���state��ֵ
    **/
    piece.player = 1;//��������

    while(1)
    {
        mouseControl();
        if(isValidMouse(&piece.x, &piece.y) == 1)//�ж��ܷ�����
        {
            generateChess();
            piece.state[a][b] = piece.player;
            //�ı�����״̬

            if( judgeWinLoss( a, b , piece) == 1 )//�ж��Ƿ����ʤ��
            {
                delay_ms(1000);
                break;
            }

            //�л��ڰ�˫��
            piece.player = (piece.player == 1) ? 2 : 1;
        }

    }
    return;
}


void playAIChess(struct Piece &piece)
{

    setcaption("������С��Ϸ--�˻���ս");
    displayboard();
    randomize();//�������ʼ��
    playMelody();
    //��������

    while(1)
    {
            mouseControl();
            //�ж��ܷ�����
            if(isValidMouse(&piece.x, &piece.y) == 1){

                piece.player = MAN;
                //�ı�����״̬
                generateChess();
                piece.state[a][b] = MAN;

                //�ж��Ƿ����ʤ��
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

                //�ж��Ƿ����ʤ��
                if( judgeWinLoss( tmp.x, tmp.y, piece) == 1 ){
                    delay_ms(1000);
                    return;
                }

            }//end inner if
    }//end outer if

    //game ended
    return;
}

//�ж���Ӯ
//������Ӯ����1��δ���ַ���0
//�����Ӻ����̲������ӡ���ʾƽ��
int judgeWinLoss( int a, int b, struct Piece &piece)
{
    int winloss = 0;
    //in total there are 20 situations
    //��һ���ࣺ��
    //@####
    if( a + 4 < N//��ֹԽ��
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

    //�ڶ����ࣺ��
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

    //�������ࣺ��
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

    //���Ĵ��ࣺƲ
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
