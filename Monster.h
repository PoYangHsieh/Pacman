#ifndef MONSTER_H
#define MONSTER_H
#include "reference.cpp"
#include "Walker.h"
#include "Pacman.h"
#include "Maze.h"
#include <set>

using namespace std;

class Monster : public Walker
{
public:
    Monster(const int,const int);///初始位置
    Monster &updateConsole();///在畫面上更新現在位置(要先刪除之前在的地方)
    virtual Monster &move();///移動，檢查有沒有碰到
    static void clear();///清掉所有變數
    static void setMaze(Maze&);
    static void setPacman(Pacman&);
    static bool isLose();

protected:
    static set< pair<int,int> > nowPositions;///儲存所有怪物位置，避免相撞
    static bool lose;///撞到pacman後為1，否則為0
    static Pacman *pacmanPtr;
    static Maze* mazePtr;
    static int count;///紀錄現在有幾隻怪物
    bool targeting;///紀錄怪獸有沒有已經鎖定好目標
    int number;///紀錄怪物編號
};



#endif // MONSTER_H
