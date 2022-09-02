#include "reference.cpp"
#include "Monster.h"

using namespace std;


set< pair<int,int> > Monster::nowPositions;///儲存所有怪物位置，避免相撞
bool Monster::lose=false;///撞到pacman後為1
Pacman *Monster::pacmanPtr=NULL;
Maze *Monster::mazePtr=NULL;
int Monster::count=0;///紀錄現在有幾隻怪物


Monster::Monster(const int a,const int b)///初始位置和pacman pointer
    : Walker(a,b)
{
    targeting=false;
    srand(time(NULL));
    number=(++count);
    direction=-1;
}

void Monster::setMaze(Maze&m)
{
    mazePtr=&m;
}
void Monster::setPacman(Pacman&p)
{
    pacmanPtr=&p;
}

Monster &Monster::updateConsole()///在畫面上更新現在位置(要先刪除之前在的地方)
{
    if( xLast!=x || yLast!=y ){
        gotoxy(2*xLast,yLast+1);

        if( (*mazePtr)[xLast][yLast]==0 )
        {
            SetConsoleTextAttribute(hConsole, 15);
            cout<<"  ";
        }
        else if( (*mazePtr)[xLast][yLast]==2 )
        {
            SetConsoleTextAttribute(hConsole, 6);
            cout<<"．";
        }
    }
    gotoxy(2*x,y+1);
    switch( number )
    {
        case 1:
            SetConsoleTextAttribute(hConsole, 155);
            cout<<"  ";
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, 199);
            cout<<"  ";
            break;
        case 3:
            SetConsoleTextAttribute(hConsole, 230);
            cout<<"  ";
            break;
        default:
            SetConsoleTextAttribute(hConsole, 167);
            cout<<"  ";
            break;

    }
    return *this;
}

Monster &Monster::move()///移動，檢查有沒有碰到
{
    if( lose )
        return *this;
    if( (x==pacmanPtr->getX()) && (y==pacmanPtr->getY()) )
    {
        lose=true;
        return *this;
    }
    xLast=x;
    yLast=y;
    nowPositions.erase( make_pair(x,y) );
    bool dir[5]={0,0,0,0,0};
    int count=0;
    targeting=false;

    for( int i=1; i<5; i++ )
        if(direction!=5-i&&(*mazePtr)[next(x,y,i)]!=1
           &&(nowPositions.find(next(x,y,i))==nowPositions.end()))
        {
            dir[i]=1;
            count++;
        }

    ///看有哪些方向可以走
    if( count!=0 )
    {
        count=rand()%count;
        for( int i=1; i<5; i++ )
        {
            if( dir[i]==1 )
                --count;
            if( count<0 )
            {
                direction=i;
                break;
            }
        }
    }
    else
    {
        if( (nowPositions.find(next(x,y,5-direction))==nowPositions.end()) )
            direction=5-direction;
        else
            direction=0;
    }


    ///移動
    x=next(x,y,direction).first;
    y=next(x,y,direction).second;


    if( mazePtr->getLevel()==4 )///看是不是有風的annoying mode
    {
        if( direction+mazePtr->getWindDirection()!=5 )
        {
            if( (x==pacmanPtr->getX()) && (y==pacmanPtr->getY()) )
            {
                lose=true;
                return *this;
            }
        }
        if( (*mazePtr)[next(x,y,mazePtr->getWindDirection())]!=1 )
        {
            x=next(x,y,mazePtr->getWindDirection()).first;
            y=next(x,y,mazePtr->getWindDirection()).second;

            ///檢查有沒有碰到pacman
            if( (x==pacmanPtr->getX()) && (y==pacmanPtr->getY()) )
            {
                lose=true;
                return *this;
            }
        }
    }
    else
    {
        ///檢查有沒有碰到pacman
        if( (x==pacmanPtr->getX()) && (y==pacmanPtr->getY()) )
        {
            lose=true;
            return *this;
        }

    }

    nowPositions.insert( make_pair(x,y) );
    return *this;
}
void Monster::clear()
{
    nowPositions.clear();
    lose=0;
    pacmanPtr=NULL;
    mazePtr=NULL;
    count=0;
}

bool Monster::isLose()
{
    return lose;
}

