#ifndef PACMAN_H
#define PACMAN_H
#include "Maze.h"
#include "Walker.h"
#include <vector>

using namespace std;

class Pacman : public Walker
{
public:
    Pacman(const int,const int);///��lx,y
    Pacman &updateConsole() const;///�b�e���W��s�{�b��m(�n���R�����e�b���a��)
    Pacman &move();///�����W�U���k��A�M�Ჾ��
    static void setMaze(Maze&);///�]�w�a��

private:
    static Maze* mazePtr;
    static int timeLevel;///�C�B�ɶ����j
    void updateAnnoyingMode() const;///��sannoying mode�ɪ��S��ĪG

};



#endif // PACMAN_H
