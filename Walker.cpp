#include "Pacman.h"
#include "reference.cpp"
#include <time.h>

using namespace std;

Walker::Walker(const int a,const int b)///ªì©lx,y
{
    xLast2=xLast=x=a;
    yLast2=yLast=y=b;
    direction=0;
}
int Walker::getX() const
{
    return x;
}
int Walker::getY() const
{
    return y;
}
int Walker::getDirection() const
{
    return direction;
}
pair<int,int> Walker::getXY() const
{
    return make_pair(x,y);
}


pair<int,int> Walker::next(int xc,int yc, int dir)
{
    switch(dir)
    {
        case 1:
            return make_pair(xc,max(0,yc-1));
        case 2:
            return make_pair(max(0,xc-1),yc);
        case 3:
            return make_pair(min(xc+1,69),yc);
        case 4:
            return make_pair(xc,min(yc+1,15));
        default:
            return make_pair(xc,yc);
    }
}
pair<int,int> Walker::next(pair<int,int> n, int dir)
{
    return next(n.first,n.second,dir);
}
