class Player
{
private:
    std::string name;
    int hp, hpMax;
    int mp, mpMax;
    int hunger, hungerMax;
    int atk;
    int def;
    int exp, lv;
    int gold;
    int ep;
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

    void setName(std::string name) { this->name = name; }
    std::string getName() { return this->name; }
    void setHp(int hp) { this->hp = hp; }
    int getHp() { return this->hp; }
    void setHpMax(int hpMax) { this->hpMax = hpMax; }
    int getHpMax() { return this->hpMax; }
    void setMp(int mp) { this->mp = mp; }
    int getMp() { return this->mp; }
    void setMpMax(int mpMax) { this->mpMax = mpMax; }
    int getMpMax() { return this->mpMax; }
    void setAtk(int atk) { this->atk = atk; }
    int getAtk() { return this->atk; }
    void setDef(int def) { this->def = def; }
    int getDef() { return this->def; }
    void setExp(int exp) { this->exp = exp; }
    int getExp() { return this->exp; }
    void setGold(int gold) { this->gold = gold; }
    int getGold() { return this->gold; }
    void setEp(int ep) { this->ep = ep; }
    int getEp() { return this->ep; }
    void setLocalX(int localX) { this->localX = localX; }
    int getLocalX() { return this->localX; }
    void setLocalY(int localY) { this->localY = localY; }
    int getLocalY() { return this->localY; }
    void setGlobalX(int globalX) { this->globalX = globalX; }
    int getGlobalX() { return this->globalX; }
    void setGlobalY(int globalY) { this->globalY = globalY; }
    int getGlobalY() { return this->globalY; }
    void setMapLocation(int mapLocation) { this->mapLocation = mapLocation; }
    int getMapLocation() { return this->mapLocation; }
    void setHunger(int hunger) { this->hunger = hunger; }
    int getHunger() { return this->hunger; }
    void setHungerMax(int hungerMax) { this->hungerMax = hungerMax; }
    int getHungerMax() { return this->hungerMax; }
    void setLv(int lv) { this->lv = lv; }
    int getLv() { return this->lv; }
};
