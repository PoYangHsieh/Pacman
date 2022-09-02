#ifndef INTERFACE_H
#define INTERFACE_H
#include <vector>
using namespace std;

enum Theme{Dark,Red};

class Interface
{
public:
    Interface();
    Interface &home();///�i�J�D���
    Interface &win(const string,const string,const int=1);///�i�JĹ�����Ainput:score,time,level
    Interface &lose(const string,const string,const int=1);///�i�J�魶���Ainput:score,time,level
    Interface &introduce();///�i�J�C�����Э���
    Interface &printRank(const int);///�L�X�Ʀ�]�Ainput:level
    Interface &about();///�i�J���󭶭�
    Interface &score100(const int,const pair<int,int>);///�W�L100�����SĹ�ɯS�s�e��
    Interface &askForName(const int,const pair<int,int>);///�߰ݪ��a�W�١A�Ω�����Ʀ�]�Ainput:level�A<score,time>
    int getLevel()const;


private:
    int choice;///0=SETTING,INTRODUCTION,EASY,MEDIUM,HARD,ANNOYING,EXIT
    void updateChoice();///�b�D���ɧ�s��e���ﶵ
    void addRank(const int,const string,const pair<int,int>);///�N�s�ƾڥ[�J�Ʀ�]
                                    ///input:level,name,<score,time>
    int level;///�����C������
    string nameLast;///�����W����J���W�r
    vector< vector< pair<string,pair<int,int> > > > name_score_time;///name_score_time[i]=the name_score_time vector of level i
    int string_to_int(const string) const;///transform string to int
    string int_to_string(const int) const;///transform int to string
    string verification(const vector< pair<string,pair<int,int> > >&,int);///�ھڱƦ�]�ƾڻs�y���ҽX
};



#endif // INTERFACE_H
