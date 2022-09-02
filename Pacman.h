#ifndef PACMAN_H
#define PACMAN_H
#include "Maze.h"
#include "Walker.h"
#include <vector>

using namespace std;

class Pacman : public Walker
{
public:
    Pacman(const int,const int);///初始x,y
    Pacman &updateConsole() const;///在畫面上更新現在位置(要先刪除之前在的地方)
    Pacman &move();///接收上下左右鍵，然後移動
    static void setMaze(Maze&);///設定地圖

private:
    static Maze* mazePtr;
    static int timeLevel;///每步時間間隔
    void updateAnnoyingMode() const;///更新annoying mode時的特殊效果

};



#endif // PACMAN_H
