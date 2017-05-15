#include <ncurses.h>
#include "Pane.h"
#include "BoardPane.h"
#include "Block.h"

BoardPane::BoardPane(int x,int y,int w,int h)
        : Pane(x,y,w,h){
}

void BoardPane::draw()
{
        init_pair(5,COLOR_WHITE,COLOR_WHITE);

        wattron(win_,COLOR_PAIR(5));
        for(int i=0; i<height_; i++)
        {
                mvwhline(win_,i,0,ACS_CKBOARD,width_);
        }
        wattroff(win_,COLOR_PAIR(5));


        wborder(win_,'*', '*', '*', '*', '*', '*', '*', '*');

        wrefresh(win_);



}
