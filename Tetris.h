#ifndef __TETRIS_H__
#define __TETRIS_H__

#include "Pane.h"
#include "Block.h"
class Tetris
{

  Pane* infoPane_;
  Pane* helpPane_;
  Pane* nextPane_;
  Pane* mainPane_;
  Pane* statPane_;

  Block* o_Block_;
  Block* stacked_block_;

  // Model쪽 20*10 배열
  int map[20][10];

  public:
      Tetris();
      ~Tetris();
      void play();
      void updateScreen();
      bool updateArray(int input,int (*map)[10]);
      void updateBlock(int (*map)[10]);
};

#endif
