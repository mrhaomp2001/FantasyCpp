#include <iostream>
#include <string.h> 
using namespace std;

class Player
{
protected:
    /* data */
    string name;
    int hp;

public:
    Player()
    {
    }
    Player(const Player &playerT)
    {
        hp = playerT.hp;
    };
    ~Player()
    {
       //cout << "Huy" << endl;
    };
};
