#pragma GCC optimize(3)
/**
���ߣ���׿1801��ӳ��

���ƣ�������С��Ϸ(14*14����)

ʱ�䣺2019.1.22

���򣺣�һ��˫�˶�ս
��������ʹ���������
���������ӣ���Ϸ����
����;�˳���Ϸ���ɰ�Esc��
������������������δ�ֳ�ʤ������ʾƽ�֡�
    �������˻���ս
�����У������Զ�Ӧ��
�����㷨��
������,alpha-beta��֦,��������ʽ����,ÿ��ѡȡ���п��ܳ��ֵ�10�ֿ���,����ʽ�������㷨,�û���,AC�㷨������ģʽƥ�䣩
Ӧ�ã�
1.�ṹ������
2.ȫ�ֱ�����Ӧ��
3.�����Ĵ���
4.ͼ�ο�
**/

#include "battle.h"
#include "settings.h"

int main()
{
    initgraph( 640, 449 );//��һ����640���أ���600���صĴ���
    setcaption("������С��Ϸ");
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
    closegraph();//�رջ�ͼ����
    return 0;
}






