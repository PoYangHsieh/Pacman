#include <bits/stdc++.h>
#include "Interface.h"
#include "reference.cpp"

using namespace std;
bool _mycomp( const pair<int,int> &n1, const pair<int,int> &n2 )
///比較 pair<score,time>，第一對分數較高為true，分數相同則看是不是第一對時間較少
{
    if(n1.first==n2.first)
    	return n1.second<n2.second;
	else
		return n1.first>n2.first;
}
bool mycomp( const pair<string,pair<int,int> > &nr1, const pair<string,pair<int,int> > &nr2 )
{
    return _mycomp(nr1.second,nr2.second);
}

Interface::Interface()
{
    ///初始化參數
    choice=2;
    level=-1;

    ///初始化界面
    initialize();


    ///開始處理排行榜紀錄
    name_score_time.push_back( vector< pair<string,pair<int,int> > >(0) );
    name_score_time.push_back( vector< pair<string,pair<int,int> > >(0) );
    name_score_time.push_back( vector< pair<string,pair<int,int> > >(0) );
    name_score_time.push_back( vector< pair<string,pair<int,int> > >(0) );
    name_score_time.push_back( vector< pair<string,pair<int,int> > >(0) );

    ///開始讀取排行榜紀錄
    fstream file;
    string _name;
    int _score;
    int _time;
    file.open( "Pacman_rank_easy.txt", ios::in );
    while( file.peek()!=EOF )
    {
        file>>_name;
        if( file.peek()==EOF )
            break;
        file>>_score;
        file>>_time;
        if( !file )
        {
            name_score_time[1].clear();
            break;
        }
        name_score_time[1].push_back( make_pair(_name,make_pair(_score,_time)) );
    }
    sort( name_score_time[1].begin(), name_score_time[1].end(), mycomp );
    name_score_time[1].resize(5);

    ///檢查讀取到的紀錄有無被竄改
    if( _name!=verification(name_score_time[1],1))
        name_score_time[1].clear();
    file.close();

    ///重複以上過程
    file.open( "Pacman_rank_medium.txt", ios::in );
    while( file.peek()!=EOF )
    {
        file>>_name;
        if( file.peek()==EOF )
            break;
        file>>_score;
        file>>_time;
        if( !file )
        {
            name_score_time[2].clear();
            break;
        }
        name_score_time[2].push_back( make_pair(_name,make_pair(_score,_time)) );
    }
    sort( name_score_time[2].begin(), name_score_time[2].end(), mycomp );
    name_score_time[2].resize(5);
    if( _name!=verification(name_score_time[2],2))
        name_score_time[2].clear();
    file.close();
    file.open( "Pacman_rank_hard.txt", ios::in );
    while( file.peek()!=EOF )
    {
        file>>_name;
        if( file.peek()==EOF )
            break;
        file>>_score;
        file>>_time;
        if( !file )
        {
            name_score_time[3].clear();
            break;
        }
        name_score_time[3].push_back( make_pair(_name,make_pair(_score,_time)) );
    }
    sort( name_score_time[3].begin(), name_score_time[3].end(), mycomp );
    name_score_time[3].resize(5);
    if( _name!=verification(name_score_time[3],3))
        name_score_time[3].clear();
    file.close();
    file.open( "Pacman_rank_annoying.txt", ios::in );
    while( file.peek()!=EOF )
    {
        file>>_name;
        if( file.peek()==EOF )
            break;
        file>>_score;
        file>>_time;
        if( !file )
        {
            name_score_time[4].clear();
            break;
        }
        name_score_time[4].push_back( make_pair(_name,make_pair(_score,_time)) );
    }
    sort( name_score_time[4].begin(), name_score_time[4].end(), mycomp );
    name_score_time[4].resize(5);
    if( _name!=verification(name_score_time[4],4))
        name_score_time[4].clear();
    file.close();
}

int Interface::getLevel() const
{
    return level;
}

Interface &Interface::home()///進入主選單
{
    system("mode con cols=140 lines=20");
    showConsoleCursor(false);

    ///畫出主選單
    SetConsoleTextAttribute(hConsole, 15);
    system("cls");
    SetConsoleTextAttribute(hConsole, 115);
    gotoxy(92,5);
    cout<<" ";
    gotoxy(44,8);
    cout<<"    ";
    gotoxy(3,2);
    cout<<"          ";
    gotoxy(22,2);
    cout<<"    ";
    gotoxy(33,2);
    cout<<"          ";
    gotoxy(50,2);
    cout<<"   ";
    gotoxy(66,2);
    cout<<"   ";
    gotoxy(76,2);
    cout<<"    ";
    gotoxy(87,2);
    cout<<"   ";
    gotoxy(102,2);
    cout<<" ";
    gotoxy(3,3);
    cout<<" ";
    gotoxy(13,3);
    cout<<"  ";
    gotoxy(21,3);
    cout<<" ";
    gotoxy(26,3);
    cout<<" ";
    gotoxy(33,3);
    cout<<" ";
    gotoxy(50,3);
    cout<<" ";
    gotoxy(53,3);
    cout<<" ";
    gotoxy(65,3);
    cout<<" ";
    gotoxy(68,3);
    cout<<" ";
    gotoxy(75,3);
    cout<<" ";
    gotoxy(80,3);
    cout<<" ";
    gotoxy(87,3);
    cout<<" ";
    gotoxy(90,3);
    cout<<" ";
    gotoxy(102,3);
    cout<<" ";
    gotoxy(3,4);
    cout<<" ";
    gotoxy(14,4);
    cout<<" ";
    gotoxy(20,4);
    cout<<" ";
    gotoxy(27,4);
    cout<<" ";
    gotoxy(33,4);
    cout<<" ";
    gotoxy(50,4);
    cout<<" ";
    gotoxy(54,4);
    cout<<" ";
    gotoxy(64,4);
    cout<<" ";
    gotoxy(68,4);
    cout<<" ";
    gotoxy(74,4);
    cout<<" ";
    gotoxy(81,4);
    cout<<" ";
    gotoxy(87,4);
    cout<<" ";
    gotoxy(91,4);
    cout<<" ";
    gotoxy(102,4);
    cout<<" ";
    gotoxy(3,5);
    cout<<" ";
    gotoxy(14,5);
    cout<<" ";
    gotoxy(19,5);
    cout<<" ";
    gotoxy(28,5);
    cout<<" ";
    gotoxy(33,5);
    cout<<" ";
    gotoxy(50,5);
    cout<<" ";
    gotoxy(55,5);
    cout<<" ";
    gotoxy(63,5);
    cout<<" ";
    gotoxy(68,5);
    cout<<" ";
    gotoxy(73,5);
    cout<<" ";
    gotoxy(82,5);
    cout<<" ";
    gotoxy(87,5);
    cout<<" ";
    gotoxy(87,5);
    cout<<" ";
    gotoxy(102,5);
    cout<<" ";
    gotoxy(3,6);
    cout<<" ";
    gotoxy(14,6);
    cout<<" ";
    gotoxy(18,6);
    cout<<" ";
    gotoxy(29,6);
    cout<<" ";
    gotoxy(33,6);
    cout<<" ";
    gotoxy(50,6);
    cout<<" ";
    gotoxy(56,6);
    cout<<" ";
    gotoxy(62,6);
    cout<<" ";
    gotoxy(68,6);
    cout<<" ";
    gotoxy(72,6);
    cout<<" ";
    gotoxy(83,6);
    cout<<" ";
    gotoxy(87,6);
    cout<<" ";
    gotoxy(93,6);
    cout<<" ";
    gotoxy(102,6);
    cout<<" ";
    gotoxy(3,7);
    cout<<" ";
    gotoxy(13,7);
    cout<<"  ";
    gotoxy(17,7);
    cout<<" ";
    gotoxy(30,7);
    cout<<" ";
    gotoxy(33,7);
    cout<<" ";
    gotoxy(50,7);
    cout<<" ";
    gotoxy(57,7);
    cout<<" ";
    gotoxy(61,7);
    cout<<" ";
    gotoxy(68,7);
    cout<<" ";
    gotoxy(71,7);
    cout<<" ";
    gotoxy(84,7);
    cout<<" ";
    gotoxy(87,7);
    cout<<" ";
    gotoxy(94,7);
    cout<<" ";
    gotoxy(102,7);
    cout<<" ";
    gotoxy(3,8);
    cout<<"           ";
    gotoxy(17,8);
    cout<<"              ";
    gotoxy(33,8);
    cout<<" ";
    gotoxy(50,8);
    cout<<" ";
    gotoxy(58,8);
    cout<<" ";
    gotoxy(60,8);
    cout<<" ";
    gotoxy(68,8);
    cout<<" ";
    gotoxy(71,8);
    cout<<"              ";
    gotoxy(87,8);
    cout<<" ";
    gotoxy(95,8);
    cout<<" ";
    gotoxy(102,8);
    cout<<" ";
    gotoxy(3,9);
    cout<<" ";
    gotoxy(16,9);
    cout<<" ";
    gotoxy(31,9);
    cout<<" ";
    gotoxy(33,9);
    cout<<" ";
    gotoxy(50,9);
    cout<<" ";
    gotoxy(59,9);
    cout<<" ";
    gotoxy(68,9);
    cout<<" ";
    gotoxy(70,9);
    cout<<" ";
    gotoxy(85,9);
    cout<<" ";
    gotoxy(87,9);
    cout<<" ";
    gotoxy(96,9);
    cout<<" ";
    gotoxy(102,9);
    cout<<" ";
    gotoxy(3,10);
    cout<<" ";
    gotoxy(16,10);
    cout<<" ";
    gotoxy(31,10);
    cout<<" ";
    gotoxy(33,10);
    cout<<" ";
    gotoxy(50,10);
    cout<<" ";
    gotoxy(59,10);
    cout<<" ";
    gotoxy(68,10);
    cout<<" ";
    gotoxy(70,10);
    cout<<" ";
    gotoxy(85,10);
    cout<<" ";
    gotoxy(87,10);
    cout<<" ";
    gotoxy(97,10);
    cout<<" ";
    gotoxy(102,10);
    cout<<" ";
    gotoxy(3,11);
    cout<<" ";
    gotoxy(16,11);
    cout<<" ";
    gotoxy(31,11);
    cout<<" ";
    gotoxy(33,11);
    cout<<" ";
    gotoxy(50,11);
    cout<<" ";
    gotoxy(59,11);
    cout<<" ";
    gotoxy(68,11);
    cout<<" ";
    gotoxy(70,11);
    cout<<" ";
    gotoxy(85,11);
    cout<<" ";
    gotoxy(87,11);
    cout<<" ";
    gotoxy(98,11);
    cout<<" ";
    gotoxy(102,11);
    cout<<" ";
    gotoxy(3,12);
    cout<<" ";
    gotoxy(16,12);
    cout<<" ";
    gotoxy(31,12);
    cout<<" ";
    gotoxy(33,12);
    cout<<" ";
    gotoxy(50,12);
    cout<<" ";
    gotoxy(59,12);
    cout<<" ";
    gotoxy(68,12);
    cout<<" ";
    gotoxy(70,12);
    cout<<" ";
    gotoxy(85,12);
    cout<<" ";
    gotoxy(87,12);
    cout<<" ";
    gotoxy(99,12);
    cout<<" ";
    gotoxy(102,12);
    cout<<" ";
    gotoxy(3,13);
    cout<<" ";
    gotoxy(16,13);
    cout<<" ";
    gotoxy(31,13);
    cout<<" ";
    gotoxy(33,13);
    cout<<"          ";
    gotoxy(50,13);
    cout<<" ";
    gotoxy(59,13);
    cout<<" ";
    gotoxy(68,13);
    cout<<" ";
    gotoxy(70,13);
    cout<<" ";
    gotoxy(85,13);
    cout<<" ";
    gotoxy(87,13);
    cout<<" ";
    gotoxy(100,13);
    cout<<"   ";
    SetConsoleTextAttribute(hConsole, 113);
    gotoxy(5,16);
    cout<<"               ";
    gotoxy(23,16);
    cout<<"                ";
    gotoxy(42,16);
    cout<<"                ";
    gotoxy(61,16);
    cout<<"                ";
    gotoxy(80,16);
    cout<<"                ";
    gotoxy(99,16);
    cout<<"                ";
    gotoxy(118,16);
    cout<<"                ";
    gotoxy(5,17);
    cout<<"     ABOUT     ";
    gotoxy(23,17);
    cout<<"  INTRODUCTION  ";
    gotoxy(42,17);
    cout<<"      EASY      ";
    gotoxy(61,17);
    cout<<"     MEDIUM     ";
    gotoxy(80,17);
    cout<<"      HARD      ";
    gotoxy(99,17);
    cout<<"    ANNOYING    ";
    gotoxy(118,17);
    cout<<"      EXIT      ";
    gotoxy(5,18);
    cout<<"               ";
    gotoxy(23,18);
    cout<<"                ";
    gotoxy(42,18);
    cout<<"                ";
    gotoxy(61,18);
    cout<<"                ";
    gotoxy(80,18);
    cout<<"                ";
    gotoxy(99,18);
    cout<<"                ";
    gotoxy(118,18);
    cout<<"                ";
    updateChoice();


    ///清空input buffer
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));///ref: https://stackoverflow.com/questions/23129870/how-do-i-clean-input-buffer-before-using-getch


    ///開始讀input
    int ch;
    while( ch=getch() )
    {
        if( getTerminalSize()!=make_pair(140,20) ){
                SetConsoleTextAttribute(hConsole, 15);
                system("cls");
                Sleep(10);
                showConsoleCursor(false);
                return home();
        }
        if( ch==27 )///esc
        {
            if( choice==6 ){
                SetConsoleTextAttribute(hConsole, 15);
                system("mode con cols=100 lines=10");
                exit(1);
            }
            else
                choice=6;
            updateChoice();
        }
        else if( ch==224 )///方向鍵
        {
            ch=getch();
            if( ch==72 || ch==75 )///上or左
            {
                if( choice>0 ){
                    choice--;
                updateChoice();
                }
            }
            else if( ch==80 || ch==77 )///下or右
            {
                if( choice<6 ){
                    choice++;
                    updateChoice();
                }
            }
        }
        else if( ch==13 )///enter鍵
        {
            if( choice==6 ){
                SetConsoleTextAttribute(hConsole, 15);
                system("mode con cols=100 lines=10");
                exit(1);
            }
            else if( choice==1 )
                return introduce();
            else if( choice==0 )
                return about();
            else
            {
                level = choice - 1;
                return *this;
            }
        }
    }
    return *this;
}
void Interface::updateChoice()///在主選單時更新當前的選項
{
    SetConsoleTextAttribute(hConsole, 113);
    gotoxy(5,16);
    cout<<"               ";
    gotoxy(23,16);
    cout<<"                ";
    gotoxy(42,16);
    cout<<"                ";
    gotoxy(61,16);
    cout<<"                ";
    gotoxy(80,16);
    cout<<"                ";
    gotoxy(99,16);
    cout<<"                ";
    gotoxy(118,16);
    cout<<"                ";
    gotoxy(5,17);
    cout<<"     ABOUT     ";
    gotoxy(23,17);
    cout<<"  INTRODUCTION  ";
    gotoxy(42,17);
    cout<<"      EASY      ";
    gotoxy(61,17);
    cout<<"     MEDIUM     ";
   gotoxy(80,17);
    cout<<"      HARD      ";
    gotoxy(99,17);
    cout<<"    ANNOYING    ";
    gotoxy(118,17);
    cout<<"      EXIT      ";
    gotoxy(5,18);
    cout<<"               ";
    gotoxy(23,18);
    cout<<"                ";
    gotoxy(42,18);
    cout<<"                ";
    gotoxy(61,18);
    cout<<"                ";
    gotoxy(80,18);
    cout<<"                ";
    gotoxy(99,18);
    cout<<"                ";
    gotoxy(118,18);
    cout<<"                ";
    SetConsoleTextAttribute(hConsole, 227);
    switch( choice )
    {
        case 0:
            gotoxy(5,16);
            cout<<"               ";
            gotoxy(5,17);
            cout<<"     ABOUT     ";
            gotoxy(5,18);
            cout<<"               ";
            break;

        case 1:
            gotoxy(23,16);
            cout<<"                ";
            gotoxy(23,17);
            cout<<"  INTRODUCTION  ";
            gotoxy(23,18);
            cout<<"                ";
            break;

        case 2:
            gotoxy(42,16);
            cout<<"                ";
            gotoxy(42,17);
            cout<<"      EASY      ";
            gotoxy(42,18);
            cout<<"                ";
            break;

        case 3:
            gotoxy(61,16);
            cout<<"                ";
            gotoxy(61,17);
            cout<<"     MEDIUM     ";
            gotoxy(61,18);
            cout<<"                ";
            break;

        case 4:
            gotoxy(80,16);
            cout<<"                ";
            gotoxy(80,17);
            cout<<"      HARD      ";
            gotoxy(80,18);
            cout<<"                ";
            break;

        case 5:
            gotoxy(99,16);
            cout<<"                ";
            gotoxy(99,17);
            cout<<"    ANNOYING    ";
            gotoxy(99,18);
            cout<<"                ";
            break;

        case 6:
            gotoxy(118,16);
            cout<<"                ";
            gotoxy(118,17);
            cout<<"      EXIT      ";
            gotoxy(118,18);
            cout<<"                ";
            break;
        }
    printRank(choice-1);
}


Interface &Interface::printRank(const int k)///印出排行榜，k是當前level
{
    SetConsoleTextAttribute(hConsole, 15);
    for( int i=1;i<15; i++ ){
        gotoxy(105,i);
        cout<<"                                 ";
    }
    if( k<1||k>4 )
        return *this;

    SetConsoleTextAttribute(hConsole, 143);
    gotoxy(105,1);
    cout<<"           Leaderboard           ";
    gotoxy(105,2);
    cout<<"                                 ";
    gotoxy(105,2);
    switch( k )
    {
        case 1:
            cout<<"           (EASY MODE)           ";
            break;
        case 2:
            cout<<"          (MEDIUM MODE)          ";
            break;
        case 3:
            cout<<"           (HARD MODE)           ";
            break;
        case 4:
            cout<<"         (ANNOYING MODE)         ";
            break;
    }
    gotoxy(105,3);
    pair<int,int> ppp=name_score_time[k][0].second;
	if( name_score_time[k].empty() || ppp.second==0 )
    {
        gotoxy(105,4);
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"   (There is no record yet.)    ";
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 135);
        cout<<" Rank          Name  Score  Time ";
        for( int i=0; i<min(5,(int)name_score_time[k].size()); i++ )
        {
        	ppp=name_score_time[k][i].second;
            if( ppp.second==0 )
                break;
            if( i==0 )
                SetConsoleTextAttribute(hConsole, 14);
            if( i==1 )
                SetConsoleTextAttribute(hConsole, 7);
            if( i==2 )
                SetConsoleTextAttribute(hConsole, 6);
            if( i==3 )
                SetConsoleTextAttribute(hConsole, 11);
            if( i==4 )
                SetConsoleTextAttribute(hConsole, 11);
            gotoxy(109,5+2*i);
            cout<<i+1<<" "<<setw(13)<<name_score_time[k][i].first;
            gotoxy(125,5+2*i);
            cout<<setw(6)<<int_to_string(ppp.first)<<setw(6)<<int_to_string(ppp.second);
        }
    }
}


Interface &Interface::introduce()///進入遊戲介紹頁面
{
    system("mode con cols=140 lines=20");
    SetConsoleTextAttribute(hConsole, 15);
    system("cls");
    SetConsoleTextAttribute(hConsole, 135);
    gotoxy(57, 1);
    cout<<"   INTRODUCTION   ";
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(24, 5);
    cout<<"In this game, you need to control a Pac-Man    to eat all dots inside the maze without being ";
    gotoxy(24, 7);
    cout<<"caught by the monsters   ,   , and   .";
    gotoxy(68, 5);
    cout<<"●";
    gotoxy(47, 7);
    SetConsoleTextAttribute(hConsole, 155);
    cout<<"  ";
    gotoxy(51, 7);
    SetConsoleTextAttribute(hConsole, 199);
    cout<<"  ";
    gotoxy(59, 7);
    SetConsoleTextAttribute(hConsole, 230);
    cout<<"  ";
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(85, 16);
    cout<<"Press the enter key to continue...";

    int ch;
    while( ch=getch() )
        if( ch==13 || ch==27 )
            break;
    return home();
}


Interface &Interface::about()///進入關於頁面
{
    system("mode con cols=140 lines=20");
    SetConsoleTextAttribute(hConsole, 15);
    system("cls");
    SetConsoleTextAttribute(hConsole, 135);
    gotoxy(61, 1);
    cout<<"    ABOUT    ";
    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(24, 3);
    cout<<"Editors (listed in the order of the number of strokes in the surnames):";
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(24, 5);
    cout<<" 李秉鴻 (Department of Mathematics, National Taiwan University)";
    gotoxy(24, 7);
    cout<<" 郭宇誠 (Department of Electrical Engineering, National Taiwan University)";
    gotoxy(24, 9);
    cout<<" 謝博揚 (Department of Electrical Engineering, National Taiwan University)";
    gotoxy(24, 11);
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"Date of Publication:";
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(24, 13);
    cout<<"   6 January 2021";

    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(85, 16);
    cout<<"Press the enter key to continue...";

    int ch;
    while( ch=getch() )
        if( ch==13 || ch==27 )
            break;
    return home();
}


Interface &Interface::win(const string score, const string time, const int k)///進入贏頁面
{
    system("mode con cols=140 lines=20");
    SetConsoleTextAttribute(hConsole, 224);
    system("cls");
    SetConsoleTextAttribute(hConsole, 96);
    gotoxy(119,1);
    cout<<"  ";
    gotoxy(66,2);
    cout<<"                ";
    gotoxy(85,2);
    cout<<"      ";
    gotoxy(109,2);
    cout<<"  ";
    gotoxy(118,2);
    cout<<" ";
    gotoxy(120,2);
    cout<<"  ";
    gotoxy(4,3);
    cout<<"   ";
    gotoxy(35,3);
    cout<<"   ";
    gotoxy(65,3);
    cout<<" ";
    gotoxy(73,3);
    cout<<"  ";
    gotoxy(85,3);
    cout<<"  ";
    gotoxy(90,3);
    cout<<" ";
    gotoxy(109,3);
    cout<<"  ";
    gotoxy(118,3);
    cout<<" ";
    gotoxy(120,3);
    cout<<"  ";
    gotoxy(5,4);
    cout<<"   ";
    gotoxy(34,4);
    cout<<" ";
    gotoxy(36,4);
    cout<<"   ";
    gotoxy(64,4);
    cout<<" ";
    gotoxy(73,4);
    cout<<"  ";
    gotoxy(85,4);
    cout<<"  ";
    gotoxy(90,4);
    cout<<"  ";
    gotoxy(109,4);
    cout<<"  ";
    gotoxy(118,4);
    cout<<" ";
    gotoxy(120,4);
    cout<<"  ";
    gotoxy(6,5);
    cout<<"   ";
    gotoxy(33,5);
    cout<<" ";
    gotoxy(37,5);
    cout<<"   ";
    gotoxy(63,5);
    cout<<" ";
    gotoxy(73,5);
    cout<<"  ";
    gotoxy(85,5);
    cout<<"  ";
    gotoxy(91,5);
    cout<<"  ";
    gotoxy(109,5);
    cout<<"  ";
    gotoxy(118,5);
    cout<<" ";
    gotoxy(120,5);
    cout<<"  ";
    gotoxy(7,6);
    cout<<"   ";
    gotoxy(32,6);
    cout<<" ";
    gotoxy(38,6);
    cout<<"   ";
    gotoxy(62,6);
    cout<<" ";
    gotoxy(73,6);
    cout<<"  ";
    gotoxy(85,6);
    cout<<"  ";
    gotoxy(92,6);
    cout<<"  ";
    gotoxy(109,6);
    cout<<"  ";
    gotoxy(118,6);
    cout<<" ";
    gotoxy(120,6);
    cout<<"  ";
    gotoxy(8,7);
    cout<<"   ";
    gotoxy(31,7);
    cout<<" ";
    gotoxy(39,7);
    cout<<"   ";
    gotoxy(61,7);
    cout<<" ";
    gotoxy(73,7);
    cout<<"  ";
    gotoxy(85,7);
    cout<<"  ";
    gotoxy(93,7);
    cout<<"  ";
    gotoxy(109,7);
    cout<<"  ";
    gotoxy(118,7);
    cout<<" ";
    gotoxy(120,7);
    cout<<"  ";
    gotoxy(9,8);
    cout<<"   ";
    gotoxy(30,8);
    cout<<" ";
    gotoxy(40,8);
    cout<<"   ";
    gotoxy(60,8);
    cout<<" ";
    gotoxy(73,8);
    cout<<"  ";
    gotoxy(85,8);
    cout<<"  ";
    gotoxy(94,8);
    cout<<"  ";
    gotoxy(109,8);
    cout<<"  ";
    gotoxy(118,8);
    cout<<" ";
    gotoxy(120,8);
    cout<<"  ";
    gotoxy(10,9);
    cout<<"   ";
    gotoxy(29,9);
    cout<<" ";
    gotoxy(41,9);
    cout<<"   ";
    gotoxy(59,9);
    cout<<" ";
    gotoxy(73,9);
    cout<<"  ";
    gotoxy(85,9);
    cout<<"  ";
    gotoxy(95,9);
    cout<<"  ";
    gotoxy(109,9);
    cout<<"  ";
    gotoxy(118,9);
    cout<<" ";
    gotoxy(120,9);
    cout<<"  ";
    gotoxy(11,10);
    cout<<"   ";
    gotoxy(28,10);
    cout<<" ";
    gotoxy(42,10);
    cout<<"   ";
    gotoxy(58,10);
    cout<<" ";
    gotoxy(73,10);
    cout<<"  ";
    gotoxy(85,10);
    cout<<"  ";
    gotoxy(96,10);
    cout<<"  ";
    gotoxy(109,10);
    cout<<"  ";
    gotoxy(118,10);
    cout<<" ";
    gotoxy(120,10);
    cout<<"  ";
    gotoxy(12,11);
    cout<<"   ";
    gotoxy(27,11);
    cout<<" ";
    gotoxy(43,11);
    cout<<"   ";
    gotoxy(57,11);
    cout<<" ";
    gotoxy(73,11);
    cout<<"  ";
    gotoxy(85,11);
    cout<<"  ";
    gotoxy(97,11);
    cout<<"  ";
    gotoxy(109,11);
    cout<<"  ";
    gotoxy(118,11);
    cout<<" ";
    gotoxy(120,11);
    cout<<"  ";
    gotoxy(13,12);
    cout<<"   ";
    gotoxy(26,12);
    cout<<" ";
    gotoxy(44,12);
    cout<<"   ";
    gotoxy(56,12);
    cout<<" ";
    gotoxy(73,12);
    cout<<"  ";
    gotoxy(85,12);
    cout<<"  ";
    gotoxy(98,12);
    cout<<"  ";
    gotoxy(109,12);
    cout<<"  ";
    gotoxy(118,12);
    cout<<" ";
    gotoxy(120,12);
    cout<<"  ";
    gotoxy(14,13);
    cout<<"   ";
    gotoxy(25,13);
    cout<<" ";
    gotoxy(45,13);
    cout<<"   ";
    gotoxy(55,13);
    cout<<" ";
    gotoxy(73,13);
    cout<<"  ";
    gotoxy(85,13);
    cout<<"  ";
    gotoxy(99,13);
    cout<<"  ";
    gotoxy(109,13);
    cout<<"  ";
    gotoxy(118,13);
    cout<<" ";
    gotoxy(120,13);
    cout<<"  ";
    gotoxy(15,14);
    cout<<"   ";
    gotoxy(24,14);
    cout<<" ";
    gotoxy(46,14);
    cout<<"   ";
    gotoxy(54,14);
    cout<<" ";
    gotoxy(73,14);
    cout<<"  ";
    gotoxy(85,14);
    cout<<"  ";
    gotoxy(100,14);
    cout<<"  ";
    gotoxy(109,14);
    cout<<"  ";
    gotoxy(118,14);
    cout<<"    ";
    gotoxy(16,15);
    cout<<"   ";
    gotoxy(23,15);
    cout<<" ";
    gotoxy(47,15);
    cout<<"   ";
    gotoxy(53,15);
    cout<<" ";
    gotoxy(73,15);
    cout<<"  ";
    gotoxy(85,15);
    cout<<"  ";
    gotoxy(101,15);
    cout<<"  ";
    gotoxy(109,15);
    cout<<"  ";
    gotoxy(17,16);
    cout<<"   ";
    gotoxy(22,16);
    cout<<" ";
    gotoxy(48,16);
    cout<<"   ";
    gotoxy(52,16);
    cout<<" ";
    gotoxy(73,16);
    cout<<"  ";
    gotoxy(85,16);
    cout<<"  ";
    gotoxy(102,16);
    cout<<"  ";
    gotoxy(109,16);
    cout<<"  ";
    gotoxy(118,16);
    cout<<"    ";
    gotoxy(18,17);
    cout<<"    ";
    gotoxy(49,17);
    cout<<"   ";
    gotoxy(73,17);
    cout<<"  ";
    gotoxy(85,17);
    cout<<"  ";
    gotoxy(103,17);
    cout<<"   ";
    gotoxy(109,17);
    cout<<"  ";
    gotoxy(118,17);
    cout<<" ";
    gotoxy(120,17);
    cout<<"  ";
    gotoxy(19,18);
    cout<<"  ";
    gotoxy(50,18);
    cout<<" ";
    gotoxy(66,18);
    cout<<"                     ";
    gotoxy(105,18);
    cout<<"      ";
    gotoxy(118,18);
    cout<<"    ";
    gotoxy(42,19);
    SetConsoleTextAttribute(hConsole, 232);
    cout<<"Your score is "<<score<<"; the time you spent is "<<time<<" seconds.";
    time_t now = clock();
    while( clock()-now<3000 )
    {
        if( GetAsyncKeyState(VK_RETURN)&0x8000 )
           break;
    }
    if( GetAsyncKeyState(VK_RETURN)&0x8000 )
        getch();

    int newscore=string_to_int(score);
    int newtime=string_to_int(time);

    ///詢問玩家名稱
	return askForName(k,make_pair(newscore,newtime));
}

Interface &Interface::lose(const string score, const string time, const int k)///進入輸頁面
{
    system("mode con cols=140 lines=20");
    SetConsoleTextAttribute(hConsole, 112);
    system("cls");
    SetConsoleTextAttribute(hConsole, 12);

    gotoxy(0,0);
    cout<<"                                                                                                                                            ";
    gotoxy(0,1);
    cout<<"                                                                                                                                            ";
    gotoxy(0,2);
    cout<<"    ";
    gotoxy(136,2);
    cout<<"    ";
    gotoxy(0,3);
    cout<<"    ";
    gotoxy(136,3);
    cout<<"    ";
    gotoxy(0,4);
    cout<<"    ";
    gotoxy(136,4);
    cout<<"    ";
    gotoxy(0,5);
    cout<<"    ";
    gotoxy(136,5);
    cout<<"    ";
    gotoxy(0,6);
    cout<<"    ";
    gotoxy(136,6);
    cout<<"    ";
    gotoxy(0,7);
    cout<<"    ";
    gotoxy(136,7);
    cout<<"    ";
    gotoxy(0,8);
    cout<<"    ";
    gotoxy(136,8);
    cout<<"    ";
    gotoxy(0,9);
    cout<<"    ";
    gotoxy(136,9);
    cout<<"    ";
    gotoxy(0,10);
    cout<<"    ";
    gotoxy(136,10);
    cout<<"    ";
    gotoxy(0,11);
    cout<<"    ";
    gotoxy(136,11);
    cout<<"    ";
    gotoxy(0,12);
    cout<<"    ";
    gotoxy(136,12);
    cout<<"    ";
    gotoxy(0,13);
    cout<<"    ";
    gotoxy(136,13);
    cout<<"    ";
    gotoxy(0,14);
    cout<<"    ";
    gotoxy(136,14);
    cout<<"    ";
    gotoxy(0,15);
    cout<<"    ";
    gotoxy(136,15);
    cout<<"    ";
    gotoxy(0,16);
    cout<<"    ";
    gotoxy(136,16);
    cout<<"    ";
    gotoxy(0,17);
    cout<<"    ";
    gotoxy(136,17);
    cout<<"    ";
    gotoxy(0,18);
    cout<<"                                                                                                                                            ";
    gotoxy(0,19);
    cout<<"                                                                                                                                            ";
    SetConsoleTextAttribute(hConsole, 128);

    gotoxy(4,2);
    cout<<"                                                                                                                                    ";
    gotoxy(4,3);
    cout<<"  ";
    gotoxy(134,3);
    cout<<"  ";
    gotoxy(4,4);
    cout<<"  ";
    gotoxy(134,4);
    cout<<"  ";
    gotoxy(4,5);
    cout<<"  ";
    gotoxy(134,5);
    cout<<"  ";
    gotoxy(4,6);
    cout<<"  ";
    gotoxy(134,6);
    cout<<"  ";
    gotoxy(4,7);
    cout<<"  ";
    gotoxy(134,7);
    cout<<"  ";
    gotoxy(4,8);
    cout<<"  ";
    gotoxy(134,8);
    cout<<"  ";
    gotoxy(4,9);
    cout<<"  ";
    gotoxy(134,9);
    cout<<"  ";
    gotoxy(4,10);
    cout<<"  ";
    gotoxy(134,10);
    cout<<"  ";
    gotoxy(4,11);
    cout<<"  ";
    gotoxy(134,11);
    cout<<"  ";
    gotoxy(4,12);
    cout<<"  ";
    gotoxy(134,12);
    cout<<"  ";
    gotoxy(4,13);
    cout<<"  ";
    gotoxy(134,13);
    cout<<"  ";
    gotoxy(4,14);
    cout<<"  ";
    gotoxy(134,14);
    cout<<"  ";
    gotoxy(4,15);
    cout<<"  ";
    gotoxy(134,15);
    cout<<"  ";
    gotoxy(4,16);
    cout<<"  ";
    gotoxy(134,16);
    cout<<"  ";
    gotoxy(4,17);
    cout<<"                                                                                                                                    ";


    gotoxy(24, 5);
    SetConsoleTextAttribute(hConsole, 112);
    if( k==1 )
        cout<<"Hey! Isn't it easy? How could you lose...\n\n";
    else if( k==2 )
        cout<<"Hey! Is it hard? How could you lose...\n\n";
    else if( k==3 )
        cout<<"So sad! You lose... Work harder!\n\n";
    else if( k==4 )
        cout<<"You lose... It's funny, right?\n\n";
    else
        cout<<"You lose...\n\n";
    gotoxy(24, 7);
    cout<<"Your score is "<<score<<".";
    int newscore=string_to_int(score);
    int newtime=string_to_int(time);
    if(newscore>100)
	{
		gotoxy(24,12);
		cout<<"Your score is over 100!";
		time_t now=clock();
	    while( clock()-now<3000 )
	    {
	        if( GetAsyncKeyState(VK_RETURN)&0x8000 )
	           break;
	    }
	}

    time_t now=clock();
    while( clock()-now<3000 )
    {
        if( GetAsyncKeyState(VK_RETURN)&0x8000 )
           break;
    }


    if(newscore>100)///超過100分但沒贏時特製畫面
	{
		return score100(k,make_pair(newscore,newtime));
	}

	///詢問玩家名稱
	return askForName(k,make_pair(newscore,newtime));
}


Interface &Interface::score100(const int k, const pair<int,int> st)///超過100分但沒贏時特製畫面
{
	system("mode con cols=140 lines=20");
    SetConsoleTextAttribute(hConsole, 240);
    system("cls");
    SetConsoleTextAttribute(hConsole, 192);
	gotoxy(15,1);
	cout<<"                   ";
	gotoxy(9,2);
	cout<<"                          ";
	gotoxy(8,3);
	cout<<"                  ";
	gotoxy(33,3);
	cout<<"   ";
	gotoxy(47,3);
	cout<<"            ";
	gotoxy(69,3);
	cout<<"      ";
	gotoxy(81,3);
	cout<<"      ";
	gotoxy(6,4);
	cout<<"         ";
	gotoxy(35,4);
	cout<<"  ";
	gotoxy(47,4);
	cout<<"            ";
	gotoxy(67,4);
	cout<<"  ";
	gotoxy(74,4);
	cout<<"  ";
	gotoxy(80,4);
	cout<<"  ";
	gotoxy(87,4);
	cout<<"  ";
	gotoxy(106,4);
	cout<<"        ";
	gotoxy(6,5);
	cout<<"  ";
	gotoxy(36,5);
	cout<<"  ";
	gotoxy(52,5);
	cout<<"  ";
	gotoxy(66,5);
	cout<<"  ";
	gotoxy(75,5);
	cout<<"  ";
	gotoxy(79,5);
	cout<<"  ";
	gotoxy(88,5);
	cout<<"  ";
	gotoxy(105,5);
	cout<<"  ";
	gotoxy(113,5);
	cout<<"  ";
	gotoxy(6,6);
	cout<<"  ";
	gotoxy(13,6);
	cout<<"        ";
	gotoxy(26,6);
	cout<<"       ";
	gotoxy(37,6);
	cout<<"   ";
	gotoxy(52,6);
	cout<<"  ";
	gotoxy(65,6);
	cout<<"  ";
	gotoxy(76,6);
	cout<<"    ";
	gotoxy(89,6);
	cout<<"  ";
	gotoxy(104,6);
	cout<<"  ";
	gotoxy(114,6);
	cout<<"  ";
	gotoxy(5,7);
	cout<<"   ";
	gotoxy(13,7);
	cout<<" ";
	gotoxy(16,7);
	cout<<" ";
	gotoxy(20,7);
	cout<<" ";
	gotoxy(26,7);
	cout<<" ";
	gotoxy(29,7);
	cout<<" ";
	gotoxy(32,7);
	cout<<" ";
	gotoxy(37,7);
	cout<<"  ";
	gotoxy(40,7);
	cout<<"  ";
	gotoxy(52,7);
	cout<<"  ";
	gotoxy(64,7);
	cout<<"  ";
	gotoxy(90,7);
	cout<<"  ";
	gotoxy(103,7);
	cout<<"  ";
	gotoxy(3,8);
	cout<<"  ";
	gotoxy(6,8);
	cout<<"  ";
	gotoxy(13,8);
	cout<<" ";
	gotoxy(17,8);
	cout<<" ";
	gotoxy(20,8);
	cout<<"       ";
	gotoxy(30,8);
	cout<<" ";
	gotoxy(32,8);
	cout<<" ";
	gotoxy(37,8);
	cout<<"  ";
	gotoxy(42,8);
	cout<<" ";
	gotoxy(52,8);
	cout<<"  ";
	gotoxy(64,8);
	cout<<"  ";
	gotoxy(90,8);
	cout<<"  ";
	gotoxy(103,8);
	cout<<"  ";
	gotoxy(121,8);
	cout<<" ";
	gotoxy(133,8);
	cout<<" ";
	gotoxy(3,9);
	cout<<" ";
	gotoxy(6,9);
	cout<<"  ";
	gotoxy(14,9);
	cout<<"      ";
	gotoxy(27,9);
	cout<<"      ";
	gotoxy(37,9);
	cout<<"  ";
	gotoxy(42,9);
	cout<<" ";
	gotoxy(52,9);
	cout<<"  ";
	gotoxy(65,9);
	cout<<"  ";
	gotoxy(89,9);
	cout<<"  ";
	gotoxy(102,9);
	cout<<"  ";
	gotoxy(121,9);
	cout<<" ";
	gotoxy(133,9);
	cout<<" ";
	gotoxy(4,10);
	cout<<" ";
	gotoxy(7,10);
	cout<<"  ";
	gotoxy(22,10);
	cout<<"  ";
	gotoxy(38,10);
	cout<<"    ";
	gotoxy(52,10);
	cout<<"  ";
	gotoxy(65,10);
	cout<<"  ";
	gotoxy(89,10);
	cout<<"  ";
	gotoxy(102,10);
	cout<<"  ";
	gotoxy(121,10);
	cout<<" ";
	gotoxy(133,10);
	cout<<" ";
	gotoxy(5,11);
	cout<<"    ";
	gotoxy(22,11);
	cout<<"  ";
	gotoxy(38,11);
	cout<<"  ";
	gotoxy(52,11);
	cout<<"  ";
	gotoxy(65,11);
	cout<<"  ";
	gotoxy(89,11);
	cout<<"  ";
	gotoxy(102,11);
	cout<<"  ";
	gotoxy(117,11);
	cout<<"         ";
	gotoxy(129,11);
	cout<<"         ";
	gotoxy(8,12);
	cout<<"  ";
	gotoxy(38,12);
	cout<<"  ";
	gotoxy(52,12);
	cout<<"  ";
	gotoxy(66,12);
	cout<<"  ";
	gotoxy(88,12);
	cout<<"  ";
	gotoxy(102,12);
	cout<<"  ";
	gotoxy(121,12);
	cout<<" ";
	gotoxy(133,12);
	cout<<" ";
	gotoxy(8,13);
	cout<<"  ";
	gotoxy(19,13);
	cout<<"        ";
	gotoxy(37,13);
	cout<<"  ";
	gotoxy(52,13);
	cout<<"  ";
	gotoxy(67,13);
	cout<<"  ";
	gotoxy(87,13);
	cout<<"  ";
	gotoxy(103,13);
	cout<<"  ";
	gotoxy(121,13);
	cout<<" ";
	gotoxy(133,13);
	cout<<" ";
	gotoxy(9,14);
	cout<<"  ";
	gotoxy(19,14);
	cout<<"  ";
	gotoxy(26,14);
	cout<<"  ";
	gotoxy(36,14);
	cout<<"   ";
	gotoxy(52,14);
	cout<<"  ";
	gotoxy(68,14);
	cout<<"   ";
	gotoxy(85,14);
	cout<<"   ";
	gotoxy(103,14);
	cout<<"  ";
	gotoxy(121,14);
	cout<<" ";
	gotoxy(133,14);
	cout<<" ";
	gotoxy(10,15);
	cout<<"    ";
	gotoxy(20,15);
	cout<<"        ";
	gotoxy(35,15);
	cout<<"   ";
	gotoxy(52,15);
	cout<<"  ";
	gotoxy(70,15);
	cout<<"   ";
	gotoxy(83,15);
	cout<<"   ";
	gotoxy(104,15);
	cout<<"  ";
	gotoxy(114,15);
	cout<<"  ";
	gotoxy(13,16);
	cout<<"   ";
	gotoxy(32,16);
	cout<<"     ";
	gotoxy(52,16);
	cout<<"  ";
	gotoxy(72,16);
	cout<<"   ";
	gotoxy(81,16);
	cout<<"   ";
	gotoxy(105,16);
	cout<<"  ";
	gotoxy(113,16);
	cout<<"  ";
	gotoxy(14,17);
	cout<<"     ";
	gotoxy(30,17);
	cout<<"    ";
	gotoxy(47,17);
	cout<<"            ";
	gotoxy(74,17);
	cout<<"   ";
	gotoxy(79,17);
	cout<<"   ";
	gotoxy(106,17);
	cout<<"        ";
	gotoxy(17,18);
	cout<<"  ";
	gotoxy(29,18);
	cout<<"   ";
	gotoxy(47,18);
	cout<<"            ";
	gotoxy(76,18);
	cout<<"    ";
	gotoxy(18,19);
	cout<<"  ";
	gotoxy(29,19);
	cout<<"  ";


	time_t now=clock();
	while( clock()-now<3000 )
	{
	    if( GetAsyncKeyState(VK_RETURN)&0x8000 )
	        break;
	}


	return askForName(k,st);
}


Interface &Interface::askForName(const int k,const pair<int,int> st)///詢問玩家名稱，用於紀錄排行榜
{
    ///檢查是否進入排行榜，沒有就不問名字
    if( st.first==0 )
        return *this;
    if( !_mycomp( st, name_score_time[k][4].second ) )
        return *this;

	system("mode con cols=140 lines=20");
    showConsoleCursor(false);
    SetConsoleTextAttribute(hConsole, 112);
    system("cls");
    SetConsoleTextAttribute(hConsole, 12);

    gotoxy(0,0);
    cout<<"                                                                                                                                            ";
    gotoxy(0,1);
    cout<<"                                                                                                                                            ";
    gotoxy(0,2);
    cout<<"    ";
    gotoxy(136,2);
    cout<<"    ";
    gotoxy(0,3);
    cout<<"    ";
    gotoxy(136,3);
    cout<<"    ";
    gotoxy(0,4);
    cout<<"    ";
    gotoxy(136,4);
    cout<<"    ";
    gotoxy(0,5);
    cout<<"    ";
    gotoxy(136,5);
    cout<<"    ";
    gotoxy(0,6);
    cout<<"    ";
    gotoxy(136,6);
    cout<<"    ";
    gotoxy(0,7);
    cout<<"    ";
    gotoxy(136,7);
    cout<<"    ";
    gotoxy(0,8);
    cout<<"    ";
    gotoxy(136,8);
    cout<<"    ";
    gotoxy(0,9);
    cout<<"    ";
    gotoxy(136,9);
    cout<<"    ";
    gotoxy(0,10);
    cout<<"    ";
    gotoxy(136,10);
    cout<<"    ";
    gotoxy(0,11);
    cout<<"    ";
    gotoxy(136,11);
    cout<<"    ";
    gotoxy(0,12);
    cout<<"    ";
    gotoxy(136,12);
    cout<<"    ";
    gotoxy(0,13);
    cout<<"    ";
    gotoxy(136,13);
    cout<<"    ";
    gotoxy(0,14);
    cout<<"    ";
    gotoxy(136,14);
    cout<<"    ";
    gotoxy(0,15);
    cout<<"    ";
    gotoxy(136,15);
    cout<<"    ";
    gotoxy(0,16);
    cout<<"    ";
    gotoxy(136,16);
    cout<<"    ";
    gotoxy(0,17);
    cout<<"    ";
    gotoxy(136,17);
    cout<<"    ";
    gotoxy(0,18);
    cout<<"                                                                                                                                            ";
    gotoxy(0,19);
    cout<<"                                                                                                                                            ";
    SetConsoleTextAttribute(hConsole, 128);

    gotoxy(4,2);
    cout<<"                                                                                                                                    ";
    gotoxy(4,3);
    cout<<"  ";
    gotoxy(134,3);
    cout<<"  ";
    gotoxy(4,4);
    cout<<"  ";
    gotoxy(134,4);
    cout<<"  ";
    gotoxy(4,5);
    cout<<"  ";
    gotoxy(134,5);
    cout<<"  ";
    gotoxy(4,6);
    cout<<"  ";
    gotoxy(134,6);
    cout<<"  ";
    gotoxy(4,7);
    cout<<"  ";
    gotoxy(134,7);
    cout<<"  ";
    gotoxy(4,8);
    cout<<"  ";
    gotoxy(134,8);
    cout<<"  ";
    gotoxy(4,9);
    cout<<"  ";
    gotoxy(134,9);
    cout<<"  ";
    gotoxy(4,10);
    cout<<"  ";
    gotoxy(134,10);
    cout<<"  ";
    gotoxy(4,11);
    cout<<"  ";
    gotoxy(134,11);
    cout<<"  ";
    gotoxy(4,12);
    cout<<"  ";
    gotoxy(134,12);
    cout<<"  ";
    gotoxy(4,13);
    cout<<"  ";
    gotoxy(134,13);
    cout<<"  ";
    gotoxy(4,14);
    cout<<"  ";
    gotoxy(134,14);
    cout<<"  ";
    gotoxy(4,15);
    cout<<"  ";
    gotoxy(134,15);
    cout<<"  ";
    gotoxy(4,16);
    cout<<"  ";
    gotoxy(134,16);
    cout<<"  ";
    gotoxy(4,17);
    cout<<"                                                                                                                                    ";


	string name;
	name="";
    gotoxy(24, 5);
    SetConsoleTextAttribute(hConsole, 112);
    cout << "Please enter your name:";
    gotoxy(24, 7);
    cout << "(Maximum length of name: 10)";
    gotoxy(24, 8);
    if( !nameLast.empty() )
        cout<<"(You may press enter directly to use the same name as last time.)";
    gotoxy(48, 5);
    SetConsoleTextAttribute(hConsole, 143);
    cout << "          ";
    gotoxy(48, 5);
    gotoxy(48, 5);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));///ref: https://stackoverflow.com/questions/23129870/how-do-i-clean-input-buffer-before-using-getch
    getline(cin,name);
    if( name.empty() )
        name=nameLast;
    if( name.empty() )
        name="(Default)";
    for( int i=0; i<name.length(); i++ )
        if( isspace(name.at(i)) )
            name="xxxxxxxxxxxxxxxxxxxxxxx";
    if(name.length()>10)
	{
		SetConsoleTextAttribute(hConsole, 112);
	    gotoxy(85, 15);
	    cout<<"Error!  Please follow the rule.";
	    gotoxy(85, 16);
	    cout<<"Press the enter key to enter your name again...";

	    int ch;
	    while( ch=getch() )
	        if( ch==13 || ch==27 )
	            break;

	    return askForName(k,st);
	}
	nameLast=name;
    addRank(k,name,st);///加入排行榜
    return *this;
}


void Interface::addRank(const int k, const string name, const pair<int,int> st)///將新數據加入排行榜
{
    name_score_time[k].push_back(make_pair(name,st));
    sort( name_score_time[k].begin(), name_score_time[k].end(), mycomp );
    name_score_time[k].resize(5);
	fstream fffile;
	switch(k)
	{
        case 1:
            fffile.open("Pacman_rank_easy.txt",ios::out|ios::trunc);
            break;
        case 2:
            fffile.open("Pacman_rank_medium.txt",ios::out|ios::trunc);
            break;
        case 3:
            fffile.open("Pacman_rank_hard.txt",ios::out|ios::trunc);
            break;
        case 4:
            fffile.open("Pacman_rank_annoying.txt",ios::out|ios::trunc);
            break;

	}
	if( fffile ){
        for( int i=0; i<5; i++ )
            if( name_score_time[k][i].second.first!=0 )
            fffile<<name_score_time[k][i].first<<" "<<name_score_time[k][i].second.first
                <<" "<<name_score_time[k][i].second.second<<"\n";
        fffile<<verification(name_score_time[k],k);
	}
}

int Interface::string_to_int(const string s) const///transform string to int
{
	int n=s.length();
	int x=0;
	for(int i=0;i<n;i++)
	{
		x=10*x+(s[i]-'0');
	}
	return x;
}
string Interface::int_to_string(const int x) const///transform int to string
{
    string str;
    int temp=x;
    while( temp>0 )
    {
        str+=(temp%10)+'0';
        temp/=10;
    }
    if( x==0 )
        str="000";
    else if( x<10 )
        str+="00";
    else if( x<100 )
        str+="0";
    reverse(str.begin(),str.end());
    return str;
}

string Interface::verification( const vector< pair<string,pair<int,int> > > &vec, int level )
///根據排行榜數據製造驗證碼
{
    unsigned long int p=7*(3+level)+level*level;
    unsigned long long int q=5+12*vec.size();
    for( int i=0; i<vec.size(); i++ )
    {
        for( int j=0; j<vec.at(i).first.length(); j++ )
            q+=(i*j+3)*(i+1)*(i+j*3+2+(q%(j+2)))*vec.at(i).first[j];
        p+=(2*i+3)*q*(vec.at(i).second.first+(i+1)*(i+2));
        q=(q+2)+(p+1)*(q+3+(p%4));
        p=q-(i+1)*(i+3)*(i+level+2)*(vec.at(i).second.second+(i+(level+2)*level+2));
        q+=(p+7)*(p+level+1);
        if( p>12345678 )
            p-=21322;
        else if( p>LONG_MAX/(7*level+5) )
            p%=(LONG_MAX/(14*level+2));
        if( q>LONG_LONG_MAX/500000 )
            q/=(100000*(i+1));
    }
    unsigned int n=3;
    q*=(level*level*level+3)%7+level+3;


    while( q<LONG_LONG_MAX/500000 )
    {
        if( q==0 )
            q=1728+(n+1)*(n+3)*(n+3+vec.size())+7*(3+level)+(vec.size()+level)*(12-level+55*vec.size());
        n=n*n-n;
        n%=30000;
        n+=23;
        p=q%n;
        p+=n;
        q*=p;
    }
    n%=12;
    if( q>LONG_LONG_MAX/5000 )
    {
        q%=LONG_LONG_MAX/(5012+n);
    }
    string str;
    while( q>0 )
    {
        p=40+q%82;
        q/=83;
        str+=p;
    }
    return str;
}

