#ifndef MONSTERJ_H
#define MONSTERJ_H

using namespace std;

class MonsterJ : public Monster
{
public:
    MonsterJ(const int,const int);
    MonsterJ &move();///���ʡA�ˬd���S���I��

private:
    int t;
    MonsterJ &MoveRandom();
    MonsterJ &MoveAim();

};



#endif // MONSTERJ_H
