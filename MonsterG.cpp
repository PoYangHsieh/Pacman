#include <bits/stdc++.h>
#include "Pacman.h"
#include "MonsterG.h"

using namespace std;
MonsterG::MonsterG(const int a,const int b)///初始位置和pacman pointer
    : Monster(a,b)
{}
MonsterG &MonsterG::move()///移動，檢查有沒有碰到
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
    if( mazePtr->getLevel()==2 || mazePtr->distance(make_pair(x,y),pacmanPtr->getXY())>40 )
    {
        int n[5]={0,SHRT_MAX,SHRT_MAX,SHRT_MAX,SHRT_MAX};
        for( int i=1; i<5; i++ )
            if((*mazePtr)[next(x,y,i)]!=1&&(nowPositions.find(next(x,y,i))==nowPositions.end()))
            {
                //if( number==1 || mazePtr->distance( pacmanPtr->getXY(), make_pair(x,y) )<5 ){
                if( number==1 ){
				    n[i]=mazePtr->distance( pacmanPtr->getXY(), next(x,y,i) );
                }
                else if( number==2 ){

                    /*pair<int,int> m=pacmanPtr->getXY();
                    while( pacmanPtr->getDirection()>0 && (*mazePtr)[next(m,pacmanPtr->getDirection())]!=1 )
                        m=next(m,pacmanPtr->getDirection());
                    n[i]=mazePtr->distance( m, next(x,y,i) );


					cout << "here!";*/
                    pair<int,int> m=pacmanPtr->getXY();
                    if(m.first>66) m.first -= 2;
                    if(m.second<2) m.second += 2;
                    m.first += 2;
                    m.second -= 2;
                    n[i]=mazePtr->distance( m, next(x,y,i) );

                }
                else if( number==3 ){

                	/*
                    pair<int,int> m=pacmanPtr->getXY();
                    if( (*mazePtr)[next(m,5-(pacmanPtr->getDirection()))]!=1 )
                        m=next(m,5-(pacmanPtr->getDirection()));
                    n[i]=mazePtr->distance( m, next(x,y,i) );
                    */


                    pair<int,int> m=pacmanPtr->getXY();
                    if(m.first<2) m.first += 2;
                    m.first -= 2;
                    if(m.second>13) m.second -= 2;
                    m.second += 2;
                    n[i]=mazePtr->distance( m, next(x,y,i) );

                }
                /*
				else{
                    n[i]=mazePtr->distance( pacmanPtr->getXY(), next(x,y,i) );
                }
                */
                else cout << "error!" << endl;
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
        for( int i=1; i<5; i++ )
            if(direction!=5-i&&(*mazePtr)[next(x,y,i)]!=1
               &&(nowPositions.find(next(x,y,i))==nowPositions.end()))
            {
                dir[i]=1;
                count++;
            }


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

    }

    x=next(x,y,direction).first;
    y=next(x,y,direction).second;
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
