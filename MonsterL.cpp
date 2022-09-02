#include "Pacman.h"
#include "MonsterL.h"

using namespace std;
MonsterL::MonsterL(const int a,const int b)///ªì©l¦ì¸m©Mpacman pointer
    : Monster(a,b)
{}


MonsterL &MonsterL::move()
{
    if( lose )
        return *this;
    if( getXY()==pacmanPtr->getXY() )
    {
        lose=true;
        return *this;
    }
    bool dir[5]={0,0,0,0,0};
    int count=0;
    targeting=false;
    if(    (mazePtr->getLevel()==3)
        || mazePtr->distance(make_pair(x,y),pacmanPtr->getXY())>29
        || mazePtr->distance(make_pair(x,y),pacmanPtr->getXY())==1 )
    {
        int n[5]={0,SHRT_MAX,SHRT_MAX,SHRT_MAX,SHRT_MAX};
        for( int i=1; i<5; i++ )
            if((*mazePtr)[next(x,y,i)]!=1&&(nowPositions.find(next(x,y,i))==nowPositions.end()))
            {
                if(  mazePtr->distance( pacmanPtr->getXY(), make_pair(x,y) )==1
                        || mazePtr->distance( pacmanPtr->getXY(), make_pair(x,y) )>21 ){
                    n[i]=mazePtr->distance( pacmanPtr->getXY(), next(x,y,i) );
                }/*
                else if( 0&&number==2 ){
                    pair<int,int> m=pacmanPtr->getXY();
                    while( pacmanPtr->getDirection()>0 && (*mazePtr)[next(m,pacmanPtr->getDirection())]!=1 )
                        m=next(m,pacmanPtr->getDirection());
                    n[i]=mazePtr->distance( m, next(x,y,i) );
                }*/
                else /*if( 1||number==3 )*/{
                    n[i]=mazePtr->distance( pacmanPtr->getXY(), next(x,y,i) );
                    for( set< pair<int,int> >::iterator it=nowPositions.begin(); it!=nowPositions.end(); ++it )
                    {
                        if( n[i]>mazePtr->distance( pacmanPtr->getXY(), *it )
                           &&n[i]>mazePtr->distance( next(x,y,i), *it )
                           && n[i]+2 >= mazePtr->distance( pacmanPtr->getXY(), *it )+mazePtr->distance( next(x,y,i), *it ) )
                        {
                            n[i]=1000;
                            break;
                        }
                        if( n[i] == mazePtr->distance( pacmanPtr->getXY(), *it )+mazePtr->distance( next(x,y,i), *it ) )
                        {
                            n[i]=1000;
                            break;
                        }
                        if( n[i]+1 == mazePtr->distance( pacmanPtr->getXY(), *it )+mazePtr->distance( next(x,y,i), *it ) )
                        {
                            n[i]=1000;
                            break;
                        }
                    }
                }/*
                else{
                    n[i]=mazePtr->distance( pacmanPtr->getXY(), next(x,y,i) );
                }*/
            }
        for( int i=1; i<5; i++ ){
            for( int j=1; j<5; j++ )
                if( n[j]<n[i] )
                    goto notMin;
            if( n[i]>=1000 )
                goto notMin;
            direction=i;
            targeting=true;
            break;

            notMin:;
        }
    }



    if( !targeting )
    {
        Monster::move();
        return *this;
    }

    xLast=x;
    yLast=y;
    x=next(x,y,direction).first;
    y=next(x,y,direction).second;
    nowPositions.erase( make_pair(xLast,yLast) );
    if( mazePtr->getLevel()==4 )
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
            if( (x==pacmanPtr->getX()) && (y==pacmanPtr->getY()) )
            {
                lose=true;
                return *this;
            }
        }
    }
    else
    {
        if( (x==pacmanPtr->getX()) && (y==pacmanPtr->getY()) )
        {
            lose=true;
            return *this;
        }

    }
    nowPositions.insert( make_pair(x,y) );



    return *this;
}
