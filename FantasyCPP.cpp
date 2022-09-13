#include "./class/lib.cpp"
int screenStage;
int errorCode;

#include "./class/player.cpp"
Player player = Player();
#include "./class/event.cpp"
#include "./class/map.cpp"
#include "./class/menu.cpp"

void start()
{
    SetConsoleTitleA("Fantasy Opening");
    srand(time(NULL));

    screenStage = 1;

    // listEvent[0].triggerEvent();
    loadEventToGame();
    loadMapToGame();
    playerChangeMap(0);
    player.setAtk(4);
    player.setDef(2);
    player.setEp(0);
    player.setExp(500000);
    player.setGold(50000);
    player.setHp(100);
    player.setHpMax(100);
    player.setMp(100);
    player.setMpMax(100);
    player.setName("MRGAMER");
    player.setHunger(100);
    player.setHungerMax(100);
    player.setLv(100);
    currentEvent = listEvent[1];
}

void update()
{
    char battleChoice;3
    do
    {
        if (screenStage == 1)
        {
            travelScreen();
        }
        if (screenStage == 2)
        {
            // 1. Show Enemy info
            // 2. Show Enemy output
            // 3. Show Choice

            battleScreen();
            battleScreenShowStatus(&battleChoice);
            battleScreenShowMenu(&battleChoice);
            
        }
    } while (screenStage != 0);
}

int main()
{
    start();
    update();

    return 0;
}
