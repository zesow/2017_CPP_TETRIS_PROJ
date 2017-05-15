#include <ncurses.h>
#include "Pane.h"
#include "InfoPane.h"

InfoPane::InfoPane(int x,int y,int w,int h)
        : Pane(x,y,w,h){
}

void InfoPane::draw()
{
        init_pair(9,COLOR_GREEN,COLOR_BLACK);
        wattron(win_,COLOR_PAIR(9));
        for(int i=0; i<height_; i++)
        {
                mvwhline(win_,i,0,ACS_CKBOARD,width_);
        }
        mvwprintw(win_,0,0,"INFO PANE");
        wattroff(win_,COLOR_PAIR(9));
        wrefresh(win_);
}
