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
}
void update()
{
    do
    {
        if (screenStage == 1)
        {
            showMap(mapLoad[player.getMapLocation()]);
            playerMove();
        }
        if (screenStage == 2)
        {
            printC("Enemy: \n", 13);
        }
    } while (screenStage != 0);
}

int main()
{
    start();
    update();

    return 0;
}