#include "reference.cpp"
#include "Monster.h"

using namespace std;


set< pair<int,int> > Monster::nowPositions;///�x�s�Ҧ��Ǫ���m�A�קK�ۼ�
bool Monster::lose=false;///����pacman�ᬰ1
Pacman *Monster::pacmanPtr=NULL;
Maze *Monster::mazePtr=NULL;
int Monster::count=0;///�����{�b���X���Ǫ�


Monster::Monster(const int a,const int b)///��l��m�Mpacman pointer
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

Monster &Monster::updateConsole()///�b�e���W��s�{�b��m(�n���R�����e�b���a��)
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
            cout<<"�D";
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

Monster &Monster::move()///���ʡA�ˬd���S���I��
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

    ///�ݦ����Ǥ�V�i�H��
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


    ///����
    x=next(x,y,direction).first;
    y=next(x,y,direction).second;


    if( mazePtr->getLevel()==4 )///�ݬO���O������annoying mode
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

            ///�ˬd���S���I��pacman
            if( (x==pacmanPtr->getX()) && (y==pacmanPtr->getY()) )
            {
                lose=true;
                return *this;
            }
        }
    }
    else
    {
        ///�ˬd���S���I��pacman
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

