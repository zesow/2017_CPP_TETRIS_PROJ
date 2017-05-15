#include <ncurses.h>
#include "Pane.h"
#include "StatPane.h"

StatPane::StatPane(int x,int y,int w,int h)
        : Pane(x,y,w,h){
}

void StatPane::draw()
{
        init_pair(6,COLOR_RED,COLOR_BLACK);
        wattron(win_,COLOR_PAIR(6));
        box(win_,0,0);
        mvwprintw(win_,0,5,"STATISTICS");
        mvwprintw(win_,1,1,"SCORE : ");
        wattroff(win_,COLOR_PAIR(6));
        wrefresh(win_);
}
