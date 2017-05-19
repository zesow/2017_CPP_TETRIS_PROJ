// 클래스 구조를 못 잡는다.

class Tetris
{
public:
enum Status {kEmpty, kWillBeErase,kFill} //0,1,2에 이름 붙여 줌.
private:
Status map[20][10];
// 맵을 가지고 있음.

public:
void moveLeft();
void moveRight();
void moveDown();

bool movable(int r_inc,int c_inc) const;
// 이거 가장중요. 현재 블락은 그리지 말고 움직이는거 판단 끝낸 다음에 그리기.
//
};

class O_Block
{

};

int main(int argc, char const *argv[]) {
        /* code */
        return 0;
}
