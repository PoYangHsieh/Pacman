#ifndef MONSTERH_H
#define MONSTERH_H

using namespace std;

class MonsterH : public Monster
{
public:
    MonsterH(const int,const int);
    MonsterH &move();///���ʡA�ˬd���S���I��

private:
    int t;
    MonsterH &MoveRandom();
    MonsterH &MoveAim();

};



#endif // MONSTERH_H
