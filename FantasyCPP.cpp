#include "./class/lib.cpp"

int screenStage;

#include "./class/player.cpp"
Player player = Player();

#include "./class/map.cpp"
#include "./class/menu.cpp"

void start()
{
    SetConsoleTitleA("Fantasy Opening");
    srand(time(NULL));

    screenStage = 1;

    loadMapToGame();
    player.setLocalX(33);
    player.setLocalY(8);
    player.setMapLocation(4);
}
void update()
{
    do
    {
        if (screenStage == 1)
        {
            system("cls");
            showMap(mapLoad[player.getMapLocation()]);
            message("Cpp-chan: ", 11, 1);
            message(" - Hello U!", 11, 2);
            playerMove();
            
        }
    } while (screenStage != 0);
}

int main()
{
    start();
    update();

    return 0;
}