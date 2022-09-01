class Player
{
protected:
    string name;
    int hp, hpMax;
    int localX, localY;
    int globalX, globalY;
    int mapLocation;

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

    int getMapLocation()
    {
        return mapLocation;
    }

    void setLocalX(int x)
    {
        localX = x;
    }

    void setLocalY(int y)
    {
        localY = y;
    }

    void setMapLocation(int mapIndex)
    {
        mapLocation = mapIndex;
    }
};
