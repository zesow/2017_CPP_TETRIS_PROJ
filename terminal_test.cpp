#include <iostream>
#include "getch.h"
using namespace std;

int score=0;
int input_key()
{
        char c=getch();
        int a=(int)c;

        if(a==65) return 0;
        else if(a==67) return 1;
        else if(a==66) return 2;
        else if(a==68) return 3;
        else if(a==113) return 4;
        else if(a==32) return 5;
        else return -1;
}
void delete_row(int (*board)[10])
{
        int count=0;
        int row=0;
        // 지울 row 찾는 부분
        for(int i=19; i>=0; i--)
        {
                for(int j=0; j<10; j++)
                {
                        if(board[i][j]==1) count++;
                }
                if(count==10)
                {
                        row=i;
                        count=0;

                        // 여기서 지워줘야 됨.
                        // row 전 줄부터 0번째 줄까지 한 칸씩 밑으로 밀어주는 코드
                        for(int k=row; k>0; k--)
                        {
                                for(int l=0; l<10; l++)
                                {
                                        board[k][l]=board[k-1][l];
                                }

                        }
                        //맨 윗 줄 0으로 채워줌.
                        for(int k=0; k<10; k++)
                        {
                                board[0][k]=0;
                        }
                        score++;
                        i=20;
                }
                else{
                        count=0;
                }
        }

}
void print_board(const int (*board)[10])
{
        cout<<"----20123075 유문상---- "<<endl;
        for(int i=0; i<20; i++)
        {
                cout<<"| ";
                for(int j=0; j<10; j++)
                {
                        cout<<board[i][j]<<" ";
                }
                cout<<"|";
                if(i==10)
                {
                        cout<<"        ";
                        cout<<"없앤 줄 수 : "<<score<<" 개";
                }
                if(i==11)
                {
                        cout<<"        ";
                        cout<<"q를 누르시면 게임을 종료합니다.";
                }
                cout<<endl;
        }
        cout<<"----------------------"<<endl;

        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}
void game_over()
{

        cout<<"game over! 게임이 종료됩니다."<<endl;
        exit(1);
}
void new_block(int (*board)[10],int& row,int& col)
{
        board[0][4]=1;
        board[0][5]=1;
        board[1][4]=1;
        board[1][5]=1;
        row=0;
        col=4;
}
void fixed_block(int (*board)[10],int row,int col)
{
        board[row][col]=1;
        board[row][col+1]=1;
        board[row+1][col]=1;
        board[row+1][col+1]=1;
        for(int i=0; i<10; i++)
        {
                if(board[0][i]==1)
                {
                        game_over();
                }
        }

        //없앨 줄 있나 판단하는 곳. 일단 한번 블럭 고정될 때 마다 전체 판 다 검사하도록 함.
        delete_row(board);
}

void crush(int (*board)[10],int& row,int& col)
{
        if(row+2==20)
        {//바닥에 닿으면
                fixed_block(board,row,col);
                new_block(board,row,col);
        }
        else if(board[row+2][col]==1 || board[row+2][col+1]==1)
        {//다른 블럭 위에 닿으면
                fixed_block(board,row,col);
                new_block(board,row,col);
        }
}

void play(int (*board)[10],int input,int& row,int& col)
{
        if(input==0)//위
        {
                if(row-1<0) return;

                board[row+1][col]=0;
                board[row+1][col+1]=0;

                board[row-1][col]=1;
                board[row-1][col+1]=1;

                row--;
                crush(board,row,col);
        }
        else if(input==1)//오
        {
                if(col+1>8) return;
                else if(board[row+1][col+2]==1 || board[row][col+2]==1) return; //다른블럭

                board[row][col]=0;
                board[row+1][col]=0;

                board[row][col+2]=1;
                board[row+1][col+2]=1;

                col++;
                crush(board,row,col);
        }
        else if(input==2)//아래
        {
                if(row+1>18) return;

                board[row][col]=0;
                board[row][col+1]=0;

                board[row+2][col]=1;
                board[row+2][col+1]=1;

                row++;
                crush(board,row,col);

        }
        else if(input==3)//왼
        {
                if(col-1<0) return; //벽
                else if(board[row+1][col-1]==1 || board[row][col-1]==1) return; //다른블럭

                board[row][col+1]=0;
                board[row+1][col+1]=0;

                board[row][col-1]=1;
                board[row+1][col-1]=1;

                col--;
                crush(board,row,col);
        }
        else if(input==5)//스페이스바
        {
                board[row][col]=0;
                board[row][col+1]=0;

                board[row+1][col]=0;
                board[row+1][col+1]=0;

                row=18;
                for(int i=19; i>=0; i--)
                {
                        if(board[i][col]==1 ||board[i][col+1]==1) row=i-2;
                }
                board[row][col]=1;
                board[row][col+1]=1;

                board[row+1][col]=1;
                board[row+1][col+1]=1;

                crush(board,row,col);
        }


        print_board(board);
}
int main(int argc, char const *argv[]) {

        int board[20][10];
        for(int i=0; i<20; i++)
        {
                for(int j=0; j<10; j++)
                {
                        board[i][j]=0;
                }
        }

        int row=0,col=0;
        new_block(board,row,col);
        int input;
        int count=0;
        print_board(board);
        while(true)
        {
                input=input_key();
                if(input==4) break;
                if(input==-1) continue;
                play(board,input,row,col);

        }
        return 0;
}
