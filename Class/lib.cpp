#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iomanip>
#include <tchar.h>
using namespace std;

int setColor(int code)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, code);
    return 0;
}

char printC(string info, int color)
{
    setColor(color);
    std::cout << info;
    setColor(15);
    return ' ';
}

char printC(char info, int color)
{
    setColor(color);
    std::cout << info;
    setColor(15);
    return ' ';
}

char hr(char symbol, int color)
{
    int i;
    setColor(color);
    for (i = 0; i < 70; i++)
    {
        cout << symbol;
    }
    setColor(15);
    return '\0';
}

int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

int randomChoice(int option1, int option2)
{
    int temp;
    temp = random(1, 2);
    if (temp == 1)
        return option1;
    return option2;
}

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = {0, 0};
        return invalid;
    }
}

SHORT messageCurrentPosX, messageCurrentPosY;
COORD pastPosition;

void messageStart(SHORT posY)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;

    pastPosition = GetConsoleCursorPosition(hStdout);

    messageCurrentPosY = posY;
    messageCurrentPosX = 70;
    
    Position.X = messageCurrentPosX;
    Position.Y = messageCurrentPosY;

    SetConsoleCursorPosition(hStdout, Position);
}

void messageBr()
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;

    messageCurrentPosX = 70;
    messageCurrentPosY++;

    Position.X = messageCurrentPosX;
    Position.Y = messageCurrentPosY;
    SetConsoleCursorPosition(hStdout, Position);
}

void messageEnd()
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hStdout, pastPosition);
}
string toString(char *a)
{
    int i;
    int size;
    size = strlen(a);
    string s = "";
    for (i = 0; i < size; i++)
    {
        s = s + a[i];
    }
    return s;
}