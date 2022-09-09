#define mapMaxCout 16
int mapLoadCount;

struct Map
{
    std::string mapName;
    int mapH;
    int mapW;
    int mapStruct[64][64];

    int mapPortalCount;
    int mapPortalX[mapMaxCout];
    int mapPortalY[mapMaxCout];
    int mapPortalDestination[mapMaxCout];

    void setMapStruct(int x, int y, int num)
    {
        mapStruct[x][y] = num;
    }

    void setPortalOnMap()
    {
        int i;
        for (int i = 0; i < mapPortalCount; i++)
        {
            setMapStruct(mapPortalX[i], mapPortalY[i], -3);
        }
    }
};

Map mapLoad[mapMaxCout];

int loadMapToGame()
{
    int i, j, u = 0;
    char s1[32] = "./map/map";
    char s2[3];
    char s3[32] = ".txt";
    char mapName[64];

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
            // cout << "Xong roi ban \n";
            fclose(f);
            break;
        }

        fgets(mapName, 64, f);
        if (mapName[strlen(mapName) - 1] == '\n')
        {
            mapName[strlen(mapName) - 1] = '\0';
        }

        mapLoad[u].mapName = toString(mapName);

        fscanf(f, "%3d", &mapLoad[u].mapW);
        fscanf(f, "%3d", &mapLoad[u].mapH);

        for (i = 0; i < mapLoad[u].mapH; i++)
        {
            for (j = 0; j < mapLoad[u].mapW; j++)
            {
                fscanf(f, "%3d", &mapLoad[u].mapStruct[j][i]);
            }
        }

        fscanf(f, "%3d", &mapLoad[u].mapPortalCount);

        for (i = 0; i < mapLoad[u].mapPortalCount; i++)
        {
            fscanf(f, "%3d", &mapLoad[u].mapPortalX[i]);
            fscanf(f, "%3d", &mapLoad[u].mapPortalY[i]);
            fscanf(f, "%3d", &mapLoad[u].mapPortalDestination[i]);
        }
        mapLoad[u].setPortalOnMap();

        u++;
        mapLoadCount++;
        fclose(f);
    } while (1);

    return 0;
}

void playerChangeMap(int mapIndex)
{
    player.setLocalX(2);
    player.setLocalY(2);
    player.setMapLocation(mapIndex);
}

void mapReset()
{
    player.setLocalX(2);
    player.setLocalY(2);
    loadMapToGame();
}
