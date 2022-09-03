
void showMap(Map map)
{
    int y, x;
    // printC(map.mapName, 12);
    cout << endl;
    for (y = 0; y < map.mapH; y++)
    {
        for (x = 0; x < map.mapW; x++)
        {
            if (x == player.getLocalX() && y == player.getLocalY())
                printC("P", 9);
            else if (map.mapStruct[x][y] == -1)
                printC("#", 7);
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
    Sleep(500);
    char moveInput;

    // Debug:
    // cout << " target x = " << player.getLocalX() - 1
    //      << "\n target y = " << player.getLocalY()
    //      << "\n target value = " << mapLoad[player.getMapLocation()].mapStruct[player.getLocalX() - 1][player.getLocalY()]
    //      << "\n player X: " << player.getLocalX()
    //      << "\n player X: " << player.getLocalY()
    //      << "\n Map Player: " << player.getMapLocation()
    //      << "\n target value base = " << mapLoad[4].mapStruct[4][2];

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
        cout << "Check" << endl;
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
}