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

        myInterface.home();///進到首頁，並讓使用者選擇遊戲關卡
        Maze maze(myInterface.getLevel());///選擇完後，創建maze
        Pacman::setMaze(maze);///將maze傳給pacman
        Pacman pacman(1,1);///新增pacman
        Monster::clear();///清除monster之前的紀錄
        Monster::setMaze(maze);///將maze傳給monster
        Monster::setPacman(pacman);///髒pacman傳給monster
        maze.setup(pacman.getXY()).updateConsoleMaze();///maze設定好並印出地圖在螢幕上
        Monster* monsterPtr;
        list<Monster*> monsters;///存monster

        ///根據關卡設定monster
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


        ///開始遊戲，直到遊戲結束條件觸發
        while( !Monster::isLose() && !maze.isWin() )
        {
            if( getTerminalSize()!=make_pair(140,20) )///檢查畫面大小是否被亂調
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
            pacman.move().updateConsole();///讀取使用者操作並在螢幕上更新pacman
            for( list<Monster*>::iterator it=monsters.begin(); it!=monsters.end(); it++ )
                (*it)->move().updateConsole();///在螢幕上更新monster
            maze.updateConsoleInfo();///在螢幕上更新maze資訊
        }

        ///判斷輸贏，給出對應介面
        if( maze.isWin() )
            myInterface.win(maze.getScore(),maze.getTime(),maze.getLevel());
        else
            myInterface.lose(maze.getScore(),maze.getTime(),maze.getLevel());

    }
}
