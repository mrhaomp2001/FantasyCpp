#include "./class/lib.cpp"
int screenStage;
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
    player.setAtk(1);
    player.setDef(1);
    player.setEp(0);
    player.setExp(0);
    player.setGold(0);
    player.setHp(100);
    player.setHpMax(100);
    player.setMp(100);
    player.setMpMax(100);
    player.setName("MR");
}

void update()
{
    do
    {
        if (screenStage == 1)
        {
            travelScreen();
        }
        if (screenStage == 2)
        {
            
        }
    } while (screenStage != 0);
}

int main()
{
    start();
    update();

    return 0;
}