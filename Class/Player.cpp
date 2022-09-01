class Player
{
protected:
    string name;
    int hp, hpMax;
    int localX, localY;
    int globalX, globalY;

public:
    Player() {}
    Player(const Player &playerT)
    {
        hp = playerT.hp;
    }
    ~Player()
    {
        cout << "Huy Player" << endl;
    }

    int getHp()
    {
        return hp;
    }

    int getHpMax()
    {
        return hpMax;
    }

    int getLocalX()
    {
        return localX;
    }

    int getLocalY()
    {
        return localY;
    }
};
