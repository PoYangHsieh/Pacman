#include <bits/stdc++.h>
#include "Pacman.h"
#include "MonsterH.h"

using namespace std;
MonsterH::MonsterH(const int a,const int b)///初始位置和pacman pointer
    : Monster(a,b)
{
    t=0;
}

MonsterH &MonsterH::move()///移動，檢查有沒有碰到
{
    nowPositions.erase( make_pair(x,y) );
    t++;
    if(t%200 < 50)
        MoveRandom();
    else
        MoveAim();

    nowPositions.insert( make_pair(x,y) );

    return *this;
}


MonsterH &MonsterH::MoveRandom()///移動，檢查有沒有碰到
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
    //if( mazePtr->level==1 && number==1 )
    {
        bool dir[4]={0,0,0,0};
        int count=0;
        if(direction!=1&&mazePtr->maze[x][y-1]!=1)
        {
            dir[0]=1;
            count++;
        }
        if(direction!=0&&mazePtr->maze[x][y+1]!=1)
        {
            dir[1]=1;
            count++;
        }
        if(direction!=3&&mazePtr->maze[x-1][y]!=1)
        {
            dir[2]=1;
            count++;
        }
        if(direction!=2&&mazePtr->maze[x+1][y]!=1)
        {
            dir[3]=1;
            count++;
        }
        if( count!=0 )
        {
            count=rand()%count;
            for( int i=0; i<4; i++ )
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
            if(direction==0)
                direction=1;
            else if(direction==1)
                direction=0;
            else if(direction==2)
                direction=3;
            else if(direction==3)
                direction=2;
        }
        switch( direction )
        {
        case 0:
            --y;
            break;
        case 1:
            ++y;
            break;
        case 2:
            --x;
            break;
        case 3:
            ++x;
            break;

        }
    }
    if( (x==pacmanPtr->getX()) && (y==pacmanPtr->getY()) )
    {
        lose=true;
        return *this;
    }
    return *this;
}
MonsterH &MonsterH::MoveAim()
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
    bool dir[4]={0,0,0,0};
    int count=0;
    int backdir;
    switch (direction) {
    	case 3:
    		backdir=2;
    		break;
    	case 2:
    		backdir=3;
    		break;
    	case 1:
    		backdir=0;
    		break;
    	case 0:
    		backdir=1;
    		break;
	}
    if(mazePtr->maze[x][y-1]!=1){
    	dir[0]=1;
    	count++;
	}
	if(mazePtr->maze[x][y+1]!=1){
    	dir[1]=1;
    	count++;
	}
	if(mazePtr->maze[x-1][y]!=1){
    	dir[2]=1;
    	count++;
	}
	if(mazePtr->maze[x+1][y]!=1){
    	dir[3]=1;
    	count++;
	}
	if(count==1){//只有一條路可以走
		for(int j=0;j<4;j++){
			if(dir[j]==1){
				direction=j;
				break;
			}
		}
		switch( direction )
        {
        case 0:
            --y;
            break;
        case 1:
            ++y;
            break;
        case 2:
            --x;
            break;
        case 3:
            ++x;
            break;

        }
	}else if(count==2){
		for(int j=0;j<4;j++){
			if(dir[j]==1 && j!=backdir){
				direction=j;
				break;
			}
		}
		switch( direction )
        {
        case 0:
            --y;
            break;
        case 1:
            ++y;
            break;
        case 2:
            --x;
            break;
        case 3:
            ++x;
            break;
        }
	}else if(count==3 || count==4){
		if(x>(pacmanPtr->getX()) && y>(pacmanPtr->getY())){
			if(mazePtr->maze[x-1][y]!=1 && mazePtr->maze[x][y-1]==1){
				direction=2;
			}else if(mazePtr->maze[x-1][y]==1 && mazePtr->maze[x][y-1]!=1){
				direction=0;
			}else if(mazePtr->maze[x-1][y]!=1 && mazePtr->maze[x][y-1]!=1){
				int temp=rand()%2;
				if(temp==0){
					direction=2;
				}else{
					direction=0;
				}
			}
		}else if(x>(pacmanPtr->getX()) && y<(pacmanPtr->getY())){
			if(mazePtr->maze[x-1][y]!=1 && mazePtr->maze[x][y+1]==1){
				direction=2;
			}else if(mazePtr->maze[x-1][y]==1 && mazePtr->maze[x][y+1]!=1){
				direction=1;
			}else if(mazePtr->maze[x-1][y]!=1 && mazePtr->maze[x][y+1]!=1){
				int temp=rand()%2;
				if(temp==0){
					direction=2;
				}else{
					direction=1;
				}
			}
		}else if(x<(pacmanPtr->getX()) && y>(pacmanPtr->getY())){
			if(mazePtr->maze[x+1][y]!=1 && mazePtr->maze[x][y-1]==1){
				direction=3;
			}else if(mazePtr->maze[x+1][y]==1 && mazePtr->maze[x][y-1]!=1){
				direction=0;
			}else if(mazePtr->maze[x+1][y]!=1 && mazePtr->maze[x][y-1]!=1){
				int temp=rand()%2;
				if(temp==0){
					direction=3;
				}else{
					direction=0;
				}
			}
		}else if(x<(pacmanPtr->getX()) && y<(pacmanPtr->getY())){
			if(mazePtr->maze[x+1][y]!=1 && mazePtr->maze[x][y+1]==1){
				direction=3;
			}else if(mazePtr->maze[x+1][y]==1 && mazePtr->maze[x][y+1]!=1){
				direction=1;
			}else if(mazePtr->maze[x+1][y]!=1 && mazePtr->maze[x][y+1]!=1){
				int temp=rand()%2;
				if(temp==0){
					direction=3;
				}else{
					direction=1;
				}
			}
		}else if(x>(pacmanPtr->getX()) && y==(pacmanPtr->getY())){
			if(mazePtr->maze[x-1][y]!=1){
				direction=2;
			}else{
				if(mazePtr->maze[x][y+1]!=1 && mazePtr->maze[x][y-1]==1){
					direction=1;
				}else if(mazePtr->maze[x][y-1]!=1 && mazePtr->maze[x][y+1]==1){
					direction=0;
				}else{
					int temp=rand()%2;
					if(temp==0){
						direction=0;
					}else{
						direction=1;
					}
				}
			}
		}else if(x<(pacmanPtr->getX()) && y==(pacmanPtr->getY())){
			if(mazePtr->maze[x+1][y]!=1){
				direction=3;
			}else{
				if(mazePtr->maze[x][y+1]!=1 && mazePtr->maze[x][y-1]==1){
					direction=1;
				}else if(mazePtr->maze[x][y-1]!=1 && mazePtr->maze[x][y+1]==1){
					direction=0;
				}else{
					int temp=rand()%2;
					if(temp==0){
						direction=0;
					}else{
						direction=1;
					}
				}
			}
		}else if(x==(pacmanPtr->getX()) && y>(pacmanPtr->getY())){
			if(mazePtr->maze[x][y-1]!=1){
				direction=0;
			}else{
				if(mazePtr->maze[x+1][y]!=1 && mazePtr->maze[x-1][y]==1){
					direction=3;
				}else if(mazePtr->maze[x+1][y]==1 && mazePtr->maze[x-1][y]!=1){
					direction=2;
				}else{
					int temp=rand()%2;
					if(temp==0){
						direction=3;
					}else{
						direction=2;
					}
				}
			}
		}else if(x==(pacmanPtr->getX()) && y<(pacmanPtr->getY())){
			if(mazePtr->maze[x][y+1]!=1){
				direction=1;
			}else{
				if(mazePtr->maze[x+1][y]!=1 && mazePtr->maze[x-1][y]==1){
					direction=3;
				}else if(mazePtr->maze[x+1][y]==1 && mazePtr->maze[x-1][y]!=1){
					direction=2;
				}else{
					int temp=rand()%2;
					if(temp==0){
						direction=3;
					}else{
						direction=2;
					}
				}
			}
		}
		switch( direction ){
	        case 0:
	            --y;
	            break;
	        case 1:
	            ++y;
	            break;
	        case 2:
	            --x;
	            break;
	        case 3:
	            ++x;
	            break;
	    }

	}

    if( (x==pacmanPtr->getX()) && (y==pacmanPtr->getY()) )
    {
        lose=true;
        return *this;
    }
    return *this;
}
