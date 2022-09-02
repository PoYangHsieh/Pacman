#ifndef MONSTERM_H
#define MONSTERM_H

using namespace std;

class MonsterM : public Monster
{
public:
    MonsterM(const int,const int);
    MonsterM &move();///移動，檢查有沒有碰到

private:
    int t;
    MonsterM &MoveRandom();
    MonsterM &MoveAim();
    MonsterM &MoveThroughWall();

};



#endif // MONSTERM_H

