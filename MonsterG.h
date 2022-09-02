#ifndef MONSTERG_H
#define MONSTERG_H

using namespace std;

class MonsterG : public Monster
{
public:
    MonsterG(const int,const int);
    MonsterG &move();///移動，檢查有沒有碰到

private:

};



#endif // MONSTERG_H
