#include <ncurses.h>
#include "getch.h"

#include "Tetris.h"

#include "Pane.h"
#include "StatPane.h"
#include "NextPane.h"
#include "InfoPane.h"
#include "HelpPane.h"
#include "BoardPane.h"

#include "Block.h"
#include "O_Block.h"
#include "Stacked_Block.h"


Tetris::Tetris()
{
        initscr();
        start_color();
        cbreak();
        mvprintw(25,30,"Press any key to exit");
        mvprintw(26,30,"20123075 Yhu MoonSang");
        refresh();

        infoPane_=new InfoPane(1,1,25,5);
        helpPane_=new HelpPane(1,6,25,12);
        nextPane_=new NextPane(1,18,25,5);
        mainPane_=new BoardPane(30,0,22,22);
        statPane_=new StatPane(60,3,20,20);

        curs_set(0);

        for(int i=0; i<20; i++)
        {
                for(int j=0; j<10; j++)
                        map[i][j]=0;
        }

        o_Block_=new O_Block();
        stacked_block_=new Stacked_Block();

}
Tetris::~Tetris()
{
        delete infoPane_;
        delete helpPane_;
        delete nextPane_;
        delete mainPane_;
        delete statPane_;

        delete o_Block_;
        delete stacked_block_;

        endwin();
}
void Tetris::play()
{
        int input=0;
        bool full=false;
        updateScreen();

        // argv[1]이 없으면 키보드 모드,있으면 리플레이 모드로 나눠주기.
        input=input_key();
        while(input_key()!=4)
        {
                // 여기서 계속 input 받으면서 array 먼저 업데이트 해주기
                // q(4)이면 out.
                full=updateArray(input,map);
                // map대로 쌓인블럭,현재 움직이는 블럭 업데이트 해주기
                updateBlock(map);
                if(full)break;
                input=input_key();
        }


}
void Tetris::updateScreen()
{
        infoPane_->draw();
        helpPane_->draw();
        nextPane_->draw();
        mainPane_->draw();
        statPane_->draw();

}

bool Tetris::updateArray(int input,int (*map)[10])
{
// 모델 부분.배열 업데이트 및 충돌,바닥 고정 탐지.
// 지금 블럭을 map에는 2로 저장하자. 고정된건 1, 없으면 0.
// 꽉 안찼으면 false,꽉 찼으면 true 반환.
}
void Tetris::updateBlock(int (*map)[10])
{
        o_Block_->draw(map);
        // 전체 스캔해서 2인거 그려주기. 현재 블럭.
        stacked_block_->draw(map);
        // 전체 스캔해서 1인거 그려주기. 밑에 쌓여있는 블럭.

}
