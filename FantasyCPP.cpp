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

    listEvent[0] = Event(0, 0, "This is Text Event! \n", 0, 0, 0, 0, 0 );
    listEvent[1] = Event(1, 1, "Enemy Test", 3, 1, 0);
    listEvent[0].triggerEvent();
    //listEvent[0].triggerEvent();
    loadMapToGame();
    playerChangeMap(0);
}
void update()
{
    do
    {
        if (screenStage == 1)
        {
            // system("cls");
            showMap(mapLoad[player.getMapLocation()]);
            message("Cpp-chan: ", 11, 1);
            message(" - Hello U!", 11, 2);
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