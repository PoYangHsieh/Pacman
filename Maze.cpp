#include <bits/stdc++.h>
#include "Maze.h"
#include "reference.cpp"

using namespace std;



Maze::Maze(const int n)///根據難度初始
{
    ///初始化參數
    initialTime=clock();
    score=0;
    windDirection=0;
    if( n>0 && n<=4 )
        level=n;
    else
        level=1;

    if( n==4 )
        annoyingMode = (rand()%4) + 1;
    else
        annoyingMode = 0;

    food=0;

    ///分配給距離參數記憶體
    _distance=new short***[70];
    for( int i=0; i<70; i++ )
    {
        _distance[i]=new short**[16];
        for( int j=0; j<16; j++ )
        {
            _distance[i][j]=new short*[70];
            for( int k=0; k<70; k++ )
            {
                _distance[i][j][k]=new short[16];
                for( int l=0; l<16; l++ )
                    _distance[i][j][k][l]=-1;
            }
        }
    }

    ///分配給迷宮記憶體
    maze = new int*[70];
    for( int i=0; i<70; i++ )
        maze[i] = new int[16];

    ///初始化迷宮
    static char map1[16][71]={
        "######################################################################",
        "#1111111111111111111111#    #1111111111111111111111111#  #11111111111#",
        "########1#########1###1#    #1##########1############1#  #1#########1#",
        "#      #1#111111111# #1#    #111111111111#          #1####1###     #1#",
        "#      #1#1#######1# #1#    #1##########1#          #11111111#######1#",
        "########1#1#     #1# #1######1##########1############1######111111111#",
        "#11111111#1#     #1# #11111111111111111111111111111111#    #1#########",
        "#1######1#1#######1# #1######1##############1########1#    #1#       #",
        "#1#    #11111111111###1######1#            #1#      #1#    #1#       #",
        "#1#    #1#########111111111111##########   #1# #### #1######1#########",
        "#1#    #1#       #1##########1111111111#   #1# #  # #1111111111111111#",
        "#1######1#########1#        #1########1#   #1# #### #1#######1######1#",
        "#111111111111111111# ###### #1#      #1#   #1#      #1#     #1#    #1#",
        "#1################1# ###### #1########1#####1########1#     #1######1#",
        "#111111111111111111#        #1111111111111111111111111#     #11111111#",
        "######################################################################"
    };

    static char map2[16][71]={
        "######################################################################",
        "# #1111111111111111111111111111                      11111111111111# #",
        "#1#1################################################ #1#1#########1###",
        "#1#1#                   #111111                      #1#1111111111111#",
        "#1#1##################################################1#1###########1#",
        "#1#1#                   111111#                      #1#1#         #1#",
        "#1#1# ################################################1#############1#",
        "#1#111111111111111111111#     #111111111111#      #1111#1111111111111#",
        "#1################1####1#######1###1##1###1########1##1#1###########1#",
        "#111111111111111111111111111111111#11111111111111111111#1111111111111#",
        "#1########1######################1#1##1####1########1###############1#",
        "#1#      #1#                    #1#1##1#  #1#111111#111#111#       #1#",
        "#1#      #1#                    #111##1####1###1####1#1#1#1#       #1#",
        "#1########1######################1#111111111111111111#1#1#1#########1#",
        "#111111111111111111111111111111111##################111#1#11111111111#",
        "######################################################################"
    };

    if( level==4 && annoyingMode==4 )
    {
        for( int i=0; i<70; i++ )
            for( int j=0; j<16; j++ ){
                if(map2[j][i]=='#')
                    maze[i][j]=1;
                else if(map2[j][i]=='1' )
                {
                    maze[i][j]=2;
                    food++;
                }
                else
                    maze[i][j]=0;
            }
    }
    else
    {
        for( int i=0; i<70; i++ )
            for( int j=0; j<16; j++ ){
                if(map1[j][i]=='#')
                    maze[i][j]=1;
                else if(map1[j][i]=='1' )
                {
                    maze[i][j]=2;
                    food++;
                }
                else
                    maze[i][j]=0;
            }
    }


    for( int i=0; i<70; i++ ){
        for( int j=0; j<16; j++ )
            distance(i,j,i,j);///算好距離
    }

}

Maze::~Maze()
{
    for( int i=0; i<71; i++ )
        delete maze[i];
    delete maze;
    for( int i=0; i<70; i++ )
    {
        for( int j=0; j<16; j++ )
        {
            for( int k=0; k<70; k++ )
            {
                delete _distance[i][j][k];
            }
            delete _distance[i][j];
        }
        delete _distance[i];
    }
    delete _distance;
}

Maze &Maze::setup(const pair<int,int> n)///把pac-man的位置的食物淨空，input: pac-man 位置
{
    initialTime=clock();
    eatFood(n.first,n.second);///把pac-man的位置的食物淨空
    score=0;///分數設好
    windDirection=0;
    system("mode con cols=140 lines=20");
    SetConsoleTextAttribute(hConsole, 15);
    system("cls");
    return *this;
}

Maze &Maze::updateConsoleMaze()///在畫面上印出地圖
{
    for( int i=0; i<70; i++ )
        for( int j=0; j<16; j++ )
        {
            gotoxy(2*i,j+1);
            if( maze[i][j]==1 && (annoyingMode!=4||i==0||j==0||i==69||j==15) )
            {
                SetConsoleTextAttribute(hConsole, 128);
                cout<<"  ";
            }
            else if( maze[i][j]==2 )
            {
                SetConsoleTextAttribute(hConsole, 6);
                cout<<"．";
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 6);
                cout<<"  ";
            }
        }
    SetConsoleTextAttribute(hConsole, 15);
    switch(level)
    {
        case 1:
            gotoxy(131,0);
            cout<<"EASY MODE";
            break;
        case 2:
            gotoxy(129,0);
            cout<<"MEDIUM MODE";
            break;
        case 3:
            gotoxy(131,0);
            cout<<"HARD MODE";
            break;
        case 4:
            gotoxy(127,0);
            cout<<"ANNOYING MODE";
            break;
    }
    return *this;
}
inline int* &Maze::operator[](int n) const{
    return maze[n];
}
inline int &Maze::operator[](pair<int,int> n) const{
    return maze[n.first][n.second];
}

int Maze::getLevel() const
{
    return level;
}
bool Maze::isWin() const
{
    return food==0;
}
bool Maze::eatFood(const int x,const int y)
{
    if( maze[x][y]==2 )
    {
        maze[x][y]=0;
        score++;
        food--;
        return true;
    }
    else
        return false;
}


int Maze::distance(int x_a,int y_a,int x_b,int y_b)///回傳(x_a,y_a)和(x_b,y_b)間最短路徑長
{
    helpRecordDistance(x_a,y_a,x_a,y_a,0);
    int x=_distance[x_a][y_a][x_b][y_b];
    return (x<0)? SHRT_MAX : x;
}
int Maze::distance(const pair<int,int> a,const pair<int,int> b)///回傳a,b間最短路徑長
{
    return distance(a.first,a.second,b.first,b.second);
}

void Maze::helpRecordDistance(int xTarget,int yTarget,int xScan,int yScan,int length)
///以recursion計算出所有點距離
{
    if( maze[xScan][yScan]==1||maze[xTarget][yTarget]==1 )
        return;

    if( _distance[xTarget][yTarget][xScan][yScan]==-1 || _distance[xTarget][yTarget][xScan][yScan]>length )
    {
        _distance[xTarget][yTarget][xScan][yScan]=length;
        helpRecordDistance(xTarget,yTarget,xScan-1,yScan,length+1);
        helpRecordDistance(xTarget,yTarget,xScan+1,yScan,length+1);
        helpRecordDistance(xTarget,yTarget,xScan,yScan-1,length+1);
        helpRecordDistance(xTarget,yTarget,xScan,yScan+1,length+1);
    }
    return;
}

Maze &Maze::updateConsoleInfo()///更新分數etc
{
    time=(clock()-initialTime)/1000;


    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(0,0);
    cout<<"Score: "<<getScore()<<"        ";
    cout<<"Time: "<<getTime()<<" (s)    ";
    if( level==4 )
        updateAnnoyingMode();
}

void Maze::updateAnnoyingMode()
{
    if( annoyingMode==1 )
    {
            windDirection=((time/4)%5);
        gotoxy(80,0);
        SetConsoleTextAttribute(hConsole, 15 );
        cout<<"Wind Direction: ";
        switch(windDirection)
        {
            case 0:
                cout<<"X ";
                break;
            case 1:
                cout<<"↑";
                break;
            case 2:
                cout<<"←";
                break;
            case 3:
                cout<<"→";
                break;
            case 4:
                cout<<"↓";
                break;
        }
    }

}

string Maze::getScore() const
{
    string str;
    int temp=score;
    while( temp>0 )
    {
        str+=(temp%10)+'0';
        temp/=10;
    }
    if( score==0 )
        str="000";
    else if( score<10 )
        str+="00";
    else if( score<100 )
        str+="0";
    reverse(str.begin(),str.end());
    return str;
}

string Maze::getTime() const
{
    string str;
    int temp=time;
    while( temp>0 )
    {
        str+=(temp%10)+'0';
        temp/=10;
    }
    if( time==0 )
        str="000";
    else if( time<10 )
        str+="00";
    else if( time<100 )
        str+="0";
    reverse(str.begin(),str.end());
    return str;
}

int Maze::getWindDirection() const
{
    return windDirection;
}
int Maze::getAnnoyingMode() const///如果不是在annoying mode，回傳0；否則回傳是在哪個annoying mode
{
    return annoyingMode;
}
int Maze::getFood() const
{
    return food;
}
