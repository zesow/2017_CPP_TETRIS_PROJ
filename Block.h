#ifndef __Block_H__
#define __Block_H__
class Block
{

  // 변수 들어갈 자리.무슨 변수가 필요할까?
public:
  Block();
  ~Block();
  virtual void draw(int (*map)[10]);
};

#endif
