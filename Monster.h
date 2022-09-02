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
    Monster(const int,const int);///��l��m
    Monster &updateConsole();///�b�e���W��s�{�b��m(�n���R�����e�b���a��)
    virtual Monster &move();///���ʡA�ˬd���S���I��
    static void clear();///�M���Ҧ��ܼ�
    static void setMaze(Maze&);
    static void setPacman(Pacman&);
    static bool isLose();

protected:
    static set< pair<int,int> > nowPositions;///�x�s�Ҧ��Ǫ���m�A�קK�ۼ�
    static bool lose;///����pacman�ᬰ1�A�_�h��0
    static Pacman *pacmanPtr;
    static Maze* mazePtr;
    static int count;///�����{�b���X���Ǫ�
    bool targeting;///�������~���S���w�g��w�n�ؼ�
    int number;///�����Ǫ��s��
};



#endif // MONSTER_H
