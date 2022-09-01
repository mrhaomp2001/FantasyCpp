#include "./class/lib.cpp"

int screenStage;

#include "./class/player.cpp"
Player player = Player();

#include "./class/map.cpp"
#include "./class/menu.cpp"


void start()
{
    srand(time(NULL));

    screenStage = 1;

    loadMapToGame();
    player.setLocalX(2);
    player.setLocalY(1);
}

void update()
{
    showMap(mapLoad[4]);
}

int main()
{
    start();
    update();

    return 0;
}