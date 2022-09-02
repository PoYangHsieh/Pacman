#ifndef WALKER_H
#define WALKER_H
#include <vector>

using namespace std;

class Walker
{
public:
    Walker(const int,const int);///初始x,y
    int getX() const;
    int getY() const;
    pair<int,int> getXY() const;
    int getDirection() const;///0:X、1:上、2:左、3:右、4:下

protected:
    int x,y,xLast,yLast,xLast2,yLast2;///last用來讓下次清掉螢幕上之前位置
    int direction;///0:X、1:上、2:左、3:右、4:下
    pair<int,int> next(int,int,int);///input: x,y,dir; output: x_next,y_next
    pair<int,int> next(pair<int,int>,int);///input: <x,y>,dir; output: x_next,y_next


};



#endif // WALKER_H
