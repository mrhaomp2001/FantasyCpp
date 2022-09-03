struct Event
{
    int eventType;
    int eventId;

    // type 0 = Text Event
    std::string eventName;
    std::string eventText;
    int eventPlayerHp;
    int eventPlayerMp;
    int eventPlayerGold;
    int eventPlayerEp;
    int eventPlayerExp;

    // type 1 = Enemy
    int eventEnemyHp;
    int eventEnemyAtk;
    int eventEnemyDef;

    char eventSymbol;
    int eventSymbolColor;

    Event() {}

    void triggerEvent()
    {
        if (eventType == 0)
        {
            printC("Event Text \n", 14);
            cout << "type: " << eventType << endl;
            cout << "Text: " << eventText << endl;
        }
        else if (eventType == 1)
        {
            printC("Event Enemy \n", 14);
            cout << "type: " << eventType << endl;
            cout << "Enemy name: " << eventText << endl;
        }
        else
        {
            printC("Loi Event\n", 14);
        }
    }
};

int eventLoadCount;
Event currentEvent = Event();
Event listEvent[16];

int loadEventToGame()
{
    int i, j, u = 0;
    char s1[32] = "./event/event";
    char s2[3];
    char s3[32] = ".txt";
    char eventLoadName[256];
    char eventLoadText[256];
    do
    {
        FILE *f;
        strcpy(s1, "./event/event");
        strcpy(s2, "");
        strcpy(s3, ".txt");

        itoa(u, s2, 10);
        strcat(s1, s2);
        strcat(s1, s3);
        int eventLoadType;

        if ((f = fopen(s1, "r")) == NULL)
        {
            fclose(f);
            break;
        }

        fscanf(f, "%d", &listEvent[u].eventType);

        listEvent[u].eventId = u;

        fscanf(f, "%d", &listEvent[u].eventPlayerHp);
        fscanf(f, "%d", &listEvent[u].eventPlayerMp);
        fscanf(f, "%d", &listEvent[u].eventPlayerGold);
        fscanf(f, "%d", &listEvent[u].eventPlayerEp);
        fscanf(f, "%d", &listEvent[u].eventPlayerExp);

        fscanf(f, "%d", &listEvent[u].eventEnemyHp);
        fscanf(f, "%d", &listEvent[u].eventEnemyAtk);
        fscanf(f, "%d\n", &listEvent[u].eventEnemyDef);

        fgets(eventLoadName, 256, f);
        if (eventLoadName[strlen(eventLoadName) - 1] == '\n')
        {
            eventLoadName[strlen(eventLoadName) - 1] = '\0';
        }

        int loopForBreak;

        for (loopForBreak = 0; loopForBreak < (strlen(eventLoadName) - 1); loopForBreak++)
        {
            if (eventLoadName[loopForBreak] == ';')
            {
                eventLoadName[loopForBreak] = '\n';
            }
        }

        listEvent[u].eventName = toString(eventLoadName);

        fgets(eventLoadText, 256, f);
        if (eventLoadText[strlen(eventLoadText) - 1] == '\n')
        {
            eventLoadText[strlen(eventLoadText) - 1] = '\0';
        }

        for (loopForBreak = 0; loopForBreak < (strlen(eventLoadText - 1)); loopForBreak++)
        {
            if (eventLoadText[loopForBreak] == ';')
            {
                eventLoadText[loopForBreak] = '\n';
            }
        }

        listEvent[u].eventText = toString(eventLoadText);

        fscanf(f, "%c\n", &listEvent[u].eventSymbol);
        fscanf(f, "%d\n", &listEvent[u].eventSymbolColor);



        u++;
        eventLoadCount++;
        fclose(f);
    } while (1);

    return 0;
}