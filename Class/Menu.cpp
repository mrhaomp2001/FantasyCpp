
void showMap(Map map)
{
    int y, x;
    // printC(map.mapName, 12);
    for (y = 0; y < map.mapH; y++)
    {
        cout << "";
        for (x = 0; x < map.mapW; x++)
        {
            if (x == player.getLocalX() && y == player.getLocalY())
                printC("P", 9);
            else if (map.mapStruct[x][y] == -1)
                printC("#", 15);
            else if (map.mapStruct[x][y] == -2)
                printC("-", 8);
            else if (map.mapStruct[x][y] == -3)
                printC("O", 1);
            else if (map.mapStruct[x][y] == -4)
                printC("X", 4);
            else
            {
                if (map.mapStruct[x][y] >= 0 && map.mapStruct[x][y] < eventLoadCount)
                {
                    printC(listEvent[map.mapStruct[x][y]].eventSymbol, listEvent[map.mapStruct[x][y]].eventSymbolColor);
                }
                else
                {
                    printC("?", 14);
                }
            }
        }
        cout << "\n";
    }
    return;
}

void playerMove()
{
    char moveInput;

    moveInput = getch();
    // system("cls");

    int leftCheck = mapLoad[player.getMapLocation()].mapStruct[player.getLocalX() - 1][player.getLocalY()];
    int rightCheck = mapLoad[player.getMapLocation()].mapStruct[player.getLocalX() + 1][player.getLocalY()];
    int upCheck = mapLoad[player.getMapLocation()].mapStruct[player.getLocalX()][player.getLocalY() - 1];
    int downCheck = mapLoad[player.getMapLocation()].mapStruct[player.getLocalX()][player.getLocalY() + 1];

    switch (moveInput)
    {
    case 'a':
    case 'A':
        if (leftCheck == -1)
        {
            printC("\n Khong the di vao tuong! \n", 4);
        }
        else
        {
            player.setLocalX(player.getLocalX() - 1);
        }
        break;

    case 'd':
    case 'D':
        if (rightCheck == -1)
        {
            printC("\n Khong the di vao tuong! \n", 4);
        }
        else
        {
            player.setLocalX(player.getLocalX() + 1);
        }
        break;

    case 'w':
    case 'W':
        if (upCheck == -1)
        {
            printC("\n Khong the di vao tuong! \n", 4);
        }
        else
        {
            player.setLocalY(player.getLocalY() - 1);
        }
        break;

    case 's':
    case 'S':
        if (downCheck == -1)
        {
            printC("\n Khong the di vao tuong! \n", 4);
        }
        else
        {
            player.setLocalY(player.getLocalY() + 1);
        }
        break;

    default:
        break;
    }

    int currentPos = mapLoad[player.getMapLocation()].mapStruct[player.getLocalX()][player.getLocalY()];

    if (currentPos == -3)
    {
        int i;
        for (i = 0; i < mapLoad[player.getMapLocation()].mapPortalCount; i++)
        {
            if (player.getLocalX() == mapLoad[player.getMapLocation()].mapPortalX[i] && player.getLocalY() == mapLoad[player.getMapLocation()].mapPortalY[i])
            {
                playerChangeMap(i);
                break;
            }
        }
    }
}

void travelScreen()
{
    system("cls");

    printC("\n", 15);

    showMap(mapLoad[player.getMapLocation()]);

    int currentPos = mapLoad[player.getMapLocation()].mapStruct[player.getLocalX()][player.getLocalY()];

    printC("\n Khu vuc (location): ", 15);
    printC(mapLoad[player.getMapLocation()].mapName, 9);
    printC("\n", 15);

    if (currentPos >= 0)
    {
        int eventMapId;
        eventMapId = currentPos;
        if (eventMapId < eventLoadCount)
        {
            int i;
            for (i = 0; i < eventLoadCount; i++)
            {
                if (eventMapId == listEvent[i].eventId)
                {
                    currentEvent = listEvent[i];
                    currentEvent.triggerEvent();
                    mapLoad[player.getMapLocation()].mapStruct[player.getLocalX()][player.getLocalY()] = -4;
                    // Debug
                    // cout << "---"
                    //      << "\n type: " << currentEvent.eventType
                    //      << "\n id: " << currentEvent.eventId
                    //      << "\n name: " << currentEvent.eventName
                    //      << "\n player hp: " << currentEvent.eventPlayerHp
                    //      << "\n Enemy hp: " << currentEvent.eventEnemyHp
                    //      << "\n Text: " << currentEvent.eventText
                    //      << "\n\n";

                    break;
                }
            }
        }
    }

    messageStart(1);
    printC("********************************", 7);

    messageBr();
    printC("*", 7);
    cout << setw(10) << right;
    printC("HP: ", 4);
    cout << setw(9) << right;
    printC(player.getHp(), 4);
    printC("/", 4);
    cout << setw(10) << left;
    printC(player.getHpMax(), 4);
    printC("*", 7);

    messageBr();
    printC("*", 7);
    cout << setw(10) << right;
    printC("MP: ", 1);
    cout << setw(9) << right;
    printC(player.getMp(), 1);
    printC("/", 1);
    cout << setw(10) << left;
    printC(player.getMpMax(), 1);
    printC("*", 7);

    messageBr();
    printC("*", 7);
    cout << setw(10) << right;
    printC("Gold: ", 6);
    cout << setw(10) << right;
    printC(player.getGold(), 6);
    cout << setw(10) << left << " ";
    printC("*", 7);

    messageBr();
    printC("********************************", 7);

    messageBr();
    printC(" - Ban la ", 7);
    printC("P", 9);
    printC("!", 7);

    printC("( > You're ", 7);
    printC("P", 9);
    printC("!)", 7);

    messageBr();
    printC(" - An ", 7);
    printC("W, A, S, D ", 13);
    printC("de di chuyen. ", 7);

    messageBr();
    printC(" > (Press ", 7);
    printC("W, A, S, D ", 13);
    printC("to move.) ", 7);

    messageEnd();

    playerMove();
}