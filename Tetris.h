#ifndef __TETRIS_H__
#define __TETRIS_H__

#include "Pane.h"
class Tetris
{

Pane* infoPane_;
Pane* helpPane_;
Pane* nextPane_;
Pane* mainPane_;
Pane* statPane_;

Pane* block_;

public:
Tetris();
~Tetris();
void play();
void updateScreen();
};

#endif
