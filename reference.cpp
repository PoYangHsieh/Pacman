#ifndef REFERENCE
#define REFERENCE

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <cwchar>
#include <iostream>
#include <fstream>
#include <wincon.h>
using namespace std;

///begin ref: http://www.cplusplus.com/forum/windows/204878/
typedef struct _CONSOLE_FONT_INFOEX
{
    ULONG cbSize;
    DWORD nFont;
    COORD dwFontSize;
    UINT  FontFamily;
    UINT  FontWeight;
    WCHAR FaceName[LF_FACESIZE];
}CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;
//the function declaration begins
#ifdef __cplusplus
extern "C" {
#endif
BOOL WINAPI SetCurrentConsoleFontEx(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX
lpConsoleCurrentFontEx);
#ifdef __cplusplus
}
#endif



///ref: https://flyingdc.pixnet.net/blog/post/24333750
void gotoxy(int xpos, int ypos)
{
  static COORD scrn;
  static HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos;
  scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}



///ref: https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt
void showConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}


///ref: https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



///ref: https://stackoverflow.com/questions/23369503/get-size-of-terminal-window-rows-columns
pair<int,int> getTerminalSize() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return make_pair((int)(csbi.dwSize.X),(int)(csbi.dwSize.Y));
}


void initialize()
{
    showConsoleCursor(false);

    ///ref: https://bbs.csdn.net/topics/370214607
    system("mode con cols=140 lines=20");


    ///ref: https://stackoverflow.com/questions/55497407/disable-quick-edit-mode-for-console-from-c
    HANDLE hInput;
    DWORD prev_mode;
    hInput = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hInput, &prev_mode);
    SetConsoleMode(hInput, prev_mode & ENABLE_EXTENDED_FLAGS);


}



#endif
