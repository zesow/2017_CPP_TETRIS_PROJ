#include <ncurses.h>
#include "Tetris.h"
#include "Pane.h"
#include "StatPane.h"
#include "NextPane.h"
#include "InfoPane.h"
#include "HelpPane.h"
#include "BoardPane.h"
#include "Block.h"

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

        block_=new Block(40,2,4,2);

        curs_set(0);


}
Tetris::~Tetris()
{
        delete infoPane_;
        delete helpPane_;
        delete nextPane_;
        delete mainPane_;
        delete statPane_;

        delete block_;

        endwin();
}
void Tetris::play()
{
        int input;
        updateScreen();
        input=getch();
}
void Tetris::updateScreen()
{
        infoPane_->draw();
        helpPane_->draw();
        nextPane_->draw();
        mainPane_->draw();
        statPane_->draw();

        block_->draw();
}
