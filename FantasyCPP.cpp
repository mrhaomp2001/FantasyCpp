#include "./class/lib.cpp"

int gameState;

#include "./class/map.cpp"
#include "./class/player.cpp"
#include "./class/menu.cpp"

Player player = Player();

void start()
{
    srand(time(NULL));

    gameState = 1;

    loadMapToGame();
}

void update()
{
    int u, i, j;
    for (u = 0; u < mapLoadCount; u++)
    {
        cout << mapNameLoad[u];
        for (i = 0; i < mapHLoad[u]; i++)
        {
            for (j = 0; j < mapWLoad[u]; j++)
            {
                cout << mapLoad[i][j][u] << " ";
            }
            cout << "\n";
        }
        cout << "--\n";
    }
}

int main()
{
    start();
    update();
    return 0;
}