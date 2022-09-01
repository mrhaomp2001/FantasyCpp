#include <iostream>
#include <stdio.h>
#include <stdlib.h> // sometime we will need, but not now :D
#include <time.h>   // support random method
#include <math.h>
#include <conio.h>
#include <string.h>

using namespace std;

class Menu
{
public:
    char menuIndex;
    Menu()
    {
        menuIndex = '0';
    };
    ~Menu(){};
    virtual void ShowMenu(){};
};

class MainMenu : Menu
{
public:
    MainMenu(){};
    ~MainMenu(){};
    void ShowMenu()
    {
        do
        {
            cout << "=====================================================================" << endl;
            cout << "Menu: \n" << endl;
            cout << "  " << "1. Phieu luu" << endl;

            menuIndex = getch();

            switch (menuIndex)
            {
                case '1':
                    cout << "Ban da an 1 \n";
                    break; 
            }

        } while (menuIndex != '0');
    };
};