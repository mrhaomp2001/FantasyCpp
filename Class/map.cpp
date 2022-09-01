#define mapMaxCout 16
int mapLoadCount;

string mapNameLoad[mapMaxCout];
int mapHLoad[mapMaxCout];
int mapWLoad[mapMaxCout];
int mapLoad[64][64][mapMaxCout];

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
        mapNameLoad[u] = toString(mapName);
        fscanf(f, "%d", &mapWLoad[u]);
        fscanf(f, "%d", &mapHLoad[u]);

        for (i = 0; i < mapHLoad[u]; i++)
        {
            for (j = 0; j < mapWLoad[u]; j++)
            {
                fscanf(f, "%i", &mapLoad[i][j][u]);
            }
        }
        u++;
        mapLoadCount++;
        fclose(f);
    } while (1);

    return 0;
}
