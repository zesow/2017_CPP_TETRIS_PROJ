#include <ncurses.h>
#include "Tetris.h"
#include "Pane.h"
#include "StatPane.h"
#include "NextPane.h"
#include "InfoPane.h"
#include "HelpPane.h"
#include "BoardPane.h"
#include "Block.h"

Block::Block(int x,int y,int w,int h)
        : Pane(x,y,w,h){
}

void Block::draw()
{
        init_pair(2,COLOR_BLACK,COLOR_BLACK);
        wattron(win_,COLOR_PAIR(2));
        for(int i=0; i<height_; i++)
        {
                mvwhline(win_,i,0,ACS_CKBOARD,width_);
        }
        wattroff(win_,COLOR_PAIR(2));
        wrefresh(win_);
}
