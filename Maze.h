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
    Maze(const int=1);///�ھ����ת�l
    ~Maze();
    bool eatFood(const int,const int);///�Y������(�p�G��)�æ^�Ǧ��S������
    Maze &updateConsoleMaze();///�b�e���W�L�X�a��
    Maze &updateConsoleInfo();///��s����etc
    Maze &setup(const pair<int,int>);///��pac-man����m�������b�šAinput: pac-man ��m
    int getLevel() const;
    string getScore() const;
    string getTime() const;
    int getFood() const;
    int getWindDirection() const;
    int getAnnoyingMode() const;///�p�G���O�bannoying mode�A�^��0�F�_�h�^�ǬO�b����annoying mode
    bool isWin() const;
    inline int* &operator[](const int) const;///�^�� maze[i]
    inline int &operator[](const pair<int,int>) const;///�^�� maze[i][j]
    int distance(const int,const int,const int,const int);///�^��(x_a,y_a)�M(x_b,y_b)���̵u���|��
    int distance(const pair<int,int>,const pair<int,int>);///�^��(x_a,y_a)�M(x_b,y_b)���̵u���|��

private:
    int** maze;///0:�S�F��A1:�O��A2:�O����
    int score;
    int level;
    int time;
    time_t initialTime;///�C���}�l���ɶ�
    int food;///�ѤU������
    int annoyingMode;///1:wind�F2:����monster�F3:��V��M�������P
    int windDirection;///annoying mode 1��
    short**** _distance;///�sdistance
    void helpRecordDistance(int,int,int,int,int);///�p��ðO�����I���Z��
    void updateAnnoyingMode();
};

#endif // MAZE_H
