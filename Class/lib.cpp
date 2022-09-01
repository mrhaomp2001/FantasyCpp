#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
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
    cout << info;
    setColor(15);
    return ' ';
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

