#ifndef MONSTERH_H
#define MONSTERH_H

using namespace std;

class MonsterH : public Monster
{
public:
    MonsterH(const int,const int);
    MonsterH &move();///移動，檢查有沒有碰到

private:
    int t;
    MonsterH &MoveRandom();
    MonsterH &MoveAim();

};



#endif // MONSTERH_H
