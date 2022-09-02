#ifndef WALKER_H
#define WALKER_H
#include <vector>

using namespace std;

class Walker
{
public:
    Walker(const int,const int);///��lx,y
    int getX() const;
    int getY() const;
    pair<int,int> getXY() const;
    int getDirection() const;///0:X�B1:�W�B2:���B3:�k�B4:�U

protected:
    int x,y,xLast,yLast,xLast2,yLast2;///last�Ψ����U���M���ù��W���e��m
    int direction;///0:X�B1:�W�B2:���B3:�k�B4:�U
    pair<int,int> next(int,int,int);///input: x,y,dir; output: x_next,y_next
    pair<int,int> next(pair<int,int>,int);///input: <x,y>,dir; output: x_next,y_next


};



#endif // WALKER_H
