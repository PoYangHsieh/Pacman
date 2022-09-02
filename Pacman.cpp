#include "reference.cpp"
#include "Pacman.h"
#include <time.h>

using namespace std;

Maze* Pacman::mazePtr=NULL;
int Pacman::timeLevel=120;///預設時間間隔

Pacman::Pacman(const int a,const int b) : Walker(a,b)///初始x,y
{
    if( mazePtr->getLevel()==4 )
        updateAnnoyingMode();
}

void Pacman::setMaze(Maze &m)///設定地圖
{
    mazePtr=&m;
    if( m.getLevel()==1 )
        timeLevel=120;
    if( m.getLevel()==2 )
        timeLevel=110;
    if( m.getLevel()==3 )
        timeLevel=90;
    if( m.getLevel()==4 )
        timeLevel=100;
}

Pacman &Pacman::updateConsole() const///在畫面上更新現在位置(要先刪除之前在的地方)
{
    SetConsoleTextAttribute(hConsole,15);
    gotoxy(2*x,y+1);
    cout<<"●";
    if( xLast!=x || yLast!=y ){
        gotoxy(2*xLast,yLast+1);
        cout<<"  ";
    }
    if( mazePtr->getLevel()==4 )
    {
        gotoxy(2*xLast2,yLast2+1);
        cout<<"  ";
    }
    gotoxy(2*x,y+1);
    cout<<"●";
    if( mazePtr->getLevel()==4 )
        updateAnnoyingMode();
}

Pacman &Pacman::move()///接收上下左右鍵，然後移動
{
    int n=0;
    xLast=x;
    yLast=y;
    time_t now = clock();
    while( clock()-now<timeLevel )
    {
        if( mazePtr->getAnnoyingMode()==3 )
        {
            if( GetAsyncKeyState(VK_RIGHT)&0x8000 ){
                if((*mazePtr)[x-1][y]!=1)
                    direction=2;
            }
            else if( GetAsyncKeyState(VK_LEFT)&0x8000 ){
                if((*mazePtr)[x+1][y]!=1)
                    direction=3;
            }
            else if( GetAsyncKeyState(VK_DOWN)&0x8000 ){
                if( (*mazePtr)[x][y-1]!=1)
                    direction=1;
            }
            else if( GetAsyncKeyState(VK_UP)&0x8000 ){
                if( (*mazePtr)[x][y+1]!=1)
                    direction=4;
        }
        }
        else
        {
            if( GetAsyncKeyState(VK_LEFT)&0x8000 ){
                if((*mazePtr)[x-1][y]!=1)
                    direction=2;
            }
            else if( GetAsyncKeyState(VK_RIGHT)&0x8000 ){
                if((*mazePtr)[x+1][y]!=1)
                    direction=3;
            }
            else if( GetAsyncKeyState(VK_UP)&0x8000 ){
                if( (*mazePtr)[x][y-1]!=1)
                    direction=1;
            }
            else if( GetAsyncKeyState(VK_DOWN)&0x8000 ){
                if( (*mazePtr)[x][y+1]!=1)
                    direction=4;
            }
        }

    }

    if( (*mazePtr)[next(x,y,direction)]==1 )
        direction=0;
    else
    {
        x=next(x,y,direction).first;
        y=next(x,y,direction).second;
    }

    if( mazePtr->getLevel()==4 )
    {
        if( direction+mazePtr->getWindDirection()!=5 )
            mazePtr->eatFood(x,y);
        if( (*mazePtr)[next(x,y,mazePtr->getWindDirection())]!=1 )
        {
            xLast2=x;
            yLast2=y;
            x=next(x,y,mazePtr->getWindDirection()).first;
            y=next(x,y,mazePtr->getWindDirection()).second;
            mazePtr->eatFood(x,y);
        }
    }
    else
        mazePtr->eatFood(x,y);


    return *this;
}

void Pacman::updateAnnoyingMode() const
{
    if( mazePtr->getAnnoyingMode()==4 )
    {
        for( int i=x-8; i<x+9; i++ )
        {
            for( int j=y-8; j<y+9; j++ )
            {
                if( i<=0 || j<=0 || i>=69 || j>=15 )
                    continue;
                if( (*mazePtr)[i][j]!=1 )
                    continue;
                gotoxy(2*i,j+1);
                if( abs(i-x)+abs(j-y)<=mazePtr->getFood()/80+2 )
                {
                    SetConsoleTextAttribute(hConsole, 128);
                    cout<<"  ";
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, 6);
                    cout<<"  ";
                }
            }
        }
    }
}
