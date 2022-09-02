#include <iostream>
#include "reference.cpp"
#include "Maze.h"
#include "Maze.cpp"
#include "Interface.h"
#include "Interface.cpp"
#include "Walker.h"
#include "Walker.cpp"
#include "Pacman.h"
#include "Pacman.cpp"
#include "Monster.h"
#include "Monster.cpp"
#include "MonsterL.h"
#include "MonsterH.h"
#include "MonsterG.h"
#include "MonsterJ.h"
#include "MonsterM.h"
#include "MonsterL.cpp"
#include "MonsterH.cpp"
#include "MonsterG.cpp"
#include "MonsterJ.cpp"
#include "MonsterM.cpp"

using namespace std;

int main()
{

    Interface myInterface;

    while( true ){

        myInterface.home();///�i�쭺���A�����ϥΪ̿�ܹC�����d
        Maze maze(myInterface.getLevel());///��ܧ���A�Ы�maze
        Pacman::setMaze(maze);///�Nmaze�ǵ�pacman
        Pacman pacman(1,1);///�s�Wpacman
        Monster::clear();///�M��monster���e������
        Monster::setMaze(maze);///�Nmaze�ǵ�monster
        Monster::setPacman(pacman);///żpacman�ǵ�monster
        maze.setup(pacman.getXY()).updateConsoleMaze();///maze�]�w�n�æL�X�a�Ϧb�ù��W
        Monster* monsterPtr;
        list<Monster*> monsters;///�smonster

        ///�ھ����d�]�wmonster
        if( myInterface.getLevel()==1 )
        {
            monsterPtr=new Monster(68,1);
            monsters.push_back(monsterPtr);
            monsterPtr=new Monster(35,1);
            monsters.push_back(monsterPtr);
            monsterPtr=new MonsterG(15,8);
            monsters.push_back(monsterPtr);
        }
        else if( myInterface.getLevel()==2 )
        {
            monsterPtr=new MonsterJ(35,1);
            monsters.push_back(monsterPtr);
            monsterPtr=new MonsterH(68,1);
            monsters.push_back(monsterPtr);
            monsterPtr=new MonsterJ(15,8);
            monsters.push_back(monsterPtr);
        }
        else if( myInterface.getLevel()==3 )
        {
            monsterPtr=new MonsterL(50,14);
            monsters.push_back(monsterPtr);
            monsterPtr=new MonsterL(68,1);
            monsters.push_back(monsterPtr);
            monsterPtr=new MonsterL(35,1);
            monsters.push_back(monsterPtr);
        }
        else if( myInterface.getLevel()==4 )
        {
            switch( maze.getAnnoyingMode() )
            {
                case 1:
                    monsterPtr=new MonsterL(68,1);
                    monsters.push_back(monsterPtr);
                    monsterPtr=new MonsterG(35,1);
                    monsters.push_back(monsterPtr);
                    monsterPtr=new MonsterG(52,14);
                    monsters.push_back(monsterPtr);
                    break;
                case 2:
                    monsterPtr=new MonsterM(68,1);
                    monsters.push_back(monsterPtr);
                    monsterPtr=new MonsterM(35,1);
                    monsters.push_back(monsterPtr);
                    monsterPtr=new MonsterM(52,14);
                    monsters.push_back(monsterPtr);
                    break;
                case 3:
                    monsterPtr=new MonsterG(68,1);
                    monsters.push_back(monsterPtr);
                    monsterPtr=new MonsterG(35,1);
                    monsters.push_back(monsterPtr);
                    monsterPtr=new MonsterJ(52,14);
                    monsters.push_back(monsterPtr);
                    break;
                case 4:
                    monsterPtr=new MonsterG(56,1);
                    monsters.push_back(monsterPtr);
                    monsterPtr=new MonsterG(42,3);
                    monsters.push_back(monsterPtr);
                    monsterPtr=new Monster(52,14);
                    monsters.push_back(monsterPtr);
                    break;


            }
        }


        ///�}�l�C���A����C����������Ĳ�o
        while( !Monster::isLose() && !maze.isWin() )
        {
            if( getTerminalSize()!=make_pair(140,20) )///�ˬd�e���j�p�O�_�Q�ý�
            {
                SetConsoleTextAttribute(hConsole, 15);
                system("cls");
                cout<<"Don't change the size please!\n\n";
                system("pause");
                showConsoleCursor(false);
                system("mode con cols=140 lines=20");
                SetConsoleTextAttribute(hConsole, 15);
                system("cls");
                maze.updateConsoleMaze();
            }
            pacman.move().updateConsole();///Ū���ϥΪ̾ާ@�æb�ù��W��spacman
            for( list<Monster*>::iterator it=monsters.begin(); it!=monsters.end(); it++ )
                (*it)->move().updateConsole();///�b�ù��W��smonster
            maze.updateConsoleInfo();///�b�ù��W��smaze��T
        }

        ///�P�_��Ĺ�A���X��������
        if( maze.isWin() )
            myInterface.win(maze.getScore(),maze.getTime(),maze.getLevel());
        else
            myInterface.lose(maze.getScore(),maze.getTime(),maze.getLevel());

    }
}
