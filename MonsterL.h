#ifndef MONSTERL_H
#define MONSTERL_H

using namespace std;

class MonsterL : public Monster
{
public:
    MonsterL(const int,const int);
    MonsterL &move();///移動，檢查有沒有碰到

private:

};



#endif // MONSTERL_H
