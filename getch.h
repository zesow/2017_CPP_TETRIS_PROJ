#include <stdio.h>
#include <termios.h>
int getch_(void){
        int ch;
        struct termios buf, save;
        tcgetattr(0,&save);
        buf = save;
        buf.c_lflag &= ~(ICANON|ECHO);
        buf.c_cc[VMIN] = 1;
        buf.c_cc[VTIME] = 0;
        tcsetattr(0, TCSAFLUSH, &buf);
        ch = getchar();
        tcsetattr(0, TCSAFLUSH, &save);
        return ch;
}

int input_key()
{
        char c=getch_();
        int a=(int)c;

        if(a==65) return 0;//위
        else if(a==67) return 1;//오른쪽
        else if(a==66) return 2;//아래
        else if(a==68) return 3;//완쪽
        else if(a==113) return 4;//q
        else if(a==32) return 5;//스페이스바
        else return -1;//그 외
}
