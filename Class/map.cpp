#define mapMaxCout 16
int mapLoadCount;

typedef struct
{
    string mapName;
    int mapH;
    int mapW;
    int mapStruct[64][64];

    void setMapStruct(int x, int y, int num)
    {
        mapStruct[x][y] = num;
    }
} Map;

Map mapLoad[mapMaxCout];

string toString(char *a)
{
    int i;
    int size;
    size = strlen(a);
    string s = "";
    for (i = 0; i < size; i++)
    {
        s = s + a[i];
    }
    return s;
}

int loadMapToGame()
{
    int i, j, u = 0;
    char s1[32] = "./map/map";
    char s2[3];
    char s3[32] = ".txt";
    char mapName[32];

    do
    {
        FILE *f;
        strcpy(s1, "./map/map");
        strcpy(s2, "");
        strcpy(s3, ".txt");

        itoa(u, s2, 10);
        strcat(s1, s2);
        strcat(s1, s3);

        if ((f = fopen(s1, "r")) == NULL)
        {
            system("cls");
            cout << "Xong roi ban \n";
            fclose(f);
            break;
        }

        fgets(mapName, 64, f);
        if (mapName[strlen(mapName) - 1] == '\n')
        {
            mapName[strlen(mapName) - 1] = '\0';
        }

        mapLoad[u].mapName = toString(mapName);

        fscanf(f, "%d", &mapLoad[u].mapW);
        fscanf(f, "%d", &mapLoad[u].mapH);

        for (i = 0; i < mapLoad[u].mapH; i++)
        {
            for (j = 0; j < mapLoad[u].mapW; j++)
            {
                fscanf(f, "%i", &mapLoad[u].mapStruct[i][j]);
            }
        }
        u++;
        mapLoadCount++;
        fclose(f);
    } while (1);

    return 0;
}

void showMap(Map map)
{
    int y, x;

    for (y = 0; y < map.mapH; y++)
    {
        for (x = 0; x < map.mapW; x++)
        {
            if (x == player.getLocalX() && y == player.getLocalY())
                printC("P", 9);
            else if (map.mapStruct[y][x] == -1)
                printC("#", 7);
            else if (map.mapStruct[y][x] == 0)
                printC("/", 7);
            else if (map.mapStruct[y][x] == -2)
                printC("-", 7);
            else if (map.mapStruct[y][x] == -4)
                printC("E", 4);
            else if (map.mapStruct[y][x] == -5)
                printC("~", 1);
            else if (map.mapStruct[y][x] == 4)
                printC("S", 23); // Slime
            else if (map.mapStruct[y][x] == 6)
                printC("R", 23); // Rabbit
            else if (map.mapStruct[y][x] == 8)
                printC("W", 23); // Wofl
            else if (map.mapStruct[y][x] == 9)
                printC("B", 23); // Bee
            else if (map.mapStruct[y][x] == 10)
                printC("O", 9); // Call dungeonGen()
            else if (map.mapStruct[y][x] == 11)
                printC("C", 23);
            else
                printC("?", 14);
        }
        cout << "\n";
    }
    return;
}
