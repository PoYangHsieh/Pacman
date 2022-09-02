#ifndef MAZE_H
#define MAZE_H

using namespace std;

class Maze
{
    friend class Monster;
    friend class MonsterH;
    friend class MonsterJ;
    friend class MonsterM;

public:
    Maze(const int=1);///根據難度初始
    ~Maze();
    bool eatFood(const int,const int);///吃掉食物(如果有)並回傳有沒有食物
    Maze &updateConsoleMaze();///在畫面上印出地圖
    Maze &updateConsoleInfo();///更新分數etc
    Maze &setup(const pair<int,int>);///把pac-man的位置的食物淨空，input: pac-man 位置
    int getLevel() const;
    string getScore() const;
    string getTime() const;
    int getFood() const;
    int getWindDirection() const;
    int getAnnoyingMode() const;///如果不是在annoying mode，回傳0；否則回傳是在哪個annoying mode
    bool isWin() const;
    inline int* &operator[](const int) const;///回傳 maze[i]
    inline int &operator[](const pair<int,int>) const;///回傳 maze[i][j]
    int distance(const int,const int,const int,const int);///回傳(x_a,y_a)和(x_b,y_b)間最短路徑長
    int distance(const pair<int,int>,const pair<int,int>);///回傳(x_a,y_a)和(x_b,y_b)間最短路徑長

private:
    int** maze;///0:沒東西，1:是牆，2:是食物
    int score;
    int level;
    int time;
    time_t initialTime;///遊戲開始的時間
    int food;///剩下的食物
    int annoyingMode;///1:wind；2:順移monster；3:方向鍵和平移不同
    int windDirection;///annoying mode 1用
    short**** _distance;///存distance
    void helpRecordDistance(int,int,int,int,int);///計算並記錄兩點間距離
    void updateAnnoyingMode();
};

#endif // MAZE_H
