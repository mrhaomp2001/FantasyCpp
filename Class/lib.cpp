#include <iostream>
#include <stdio.h>
#include <stdlib.h> // sometime we will need, but not now :D
#include <time.h>   // support random method
#include <math.h>
#include <string.h>

#include <windows.h> // 1. system("cls"); clear the screen. 2. exit(1); exit the program.

#include "../Class/Player.cpp"
#include "../Class/Menu.cpp"


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