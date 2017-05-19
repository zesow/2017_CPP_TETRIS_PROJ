#ifndef __PANE_H__
#define __PANE_H__
class Pane {
protected:
  int width_,height_;
  int x_,y_;
  WINDOW* win_;
public:
  Pane(int x,int y,int w,int h);
  ~Pane();
  virtual void draw();
};
#endif
