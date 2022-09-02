#ifndef INTERFACE_H
#define INTERFACE_H
#include <vector>
using namespace std;

enum Theme{Dark,Red};

class Interface
{
public:
    Interface();
    Interface &home();///進入主選單
    Interface &win(const string,const string,const int=1);///進入贏頁面，input:score,time,level
    Interface &lose(const string,const string,const int=1);///進入輸頁面，input:score,time,level
    Interface &introduce();///進入遊戲介紹頁面
    Interface &printRank(const int);///印出排行榜，input:level
    Interface &about();///進入關於頁面
    Interface &score100(const int,const pair<int,int>);///超過100分但沒贏時特製畫面
    Interface &askForName(const int,const pair<int,int>);///詢問玩家名稱，用於紀錄排行榜，input:level，<score,time>
    int getLevel()const;


private:
    int choice;///0=SETTING,INTRODUCTION,EASY,MEDIUM,HARD,ANNOYING,EXIT
    void updateChoice();///在主選單時更新當前的選項
    void addRank(const int,const string,const pair<int,int>);///將新數據加入排行榜
                                    ///input:level,name,<score,time>
    int level;///紀錄遊戲難度
    string nameLast;///紀錄上次輸入的名字
    vector< vector< pair<string,pair<int,int> > > > name_score_time;///name_score_time[i]=the name_score_time vector of level i
    int string_to_int(const string) const;///transform string to int
    string int_to_string(const int) const;///transform int to string
    string verification(const vector< pair<string,pair<int,int> > >&,int);///根據排行榜數據製造驗證碼
};



#endif // INTERFACE_H
