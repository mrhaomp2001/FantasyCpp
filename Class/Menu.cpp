void showMap(Map map)
{
    int y, x;
    std::string mapString = "";
    // printC(map.mapName, 12);
    for (y = 0; y < map.mapH; y++)
    {
        cout << "\t";
        for (x = 0; x < map.mapW; x++)
        {
            if (x == player.getLocalX() && y == player.getLocalY())
            {
                printC(mapString, 8);
                mapString = "";
                printC("P", 9);
            }
            else if (map.mapStruct[x][y] == -1)
            {
                printC(mapString, 8);
                mapString = "";
                printC("#", 15);
            }
            else if (map.mapStruct[x][y] == -2)
            {
                mapString += "-";
            }
            else if (map.mapStruct[x][y] == -5)
            {
                mapString += " ";
            }
            else if (map.mapStruct[x][y] == -3)
            {
                printC(mapString, 8);
                mapString = "";
                printC("O", 1);
            }
            else if (map.mapStruct[x][y] == -4)
            {
                printC(mapString, 8);
                mapString = "";
                printC("X", 4);
            }
            else
            {
                if (map.mapStruct[x][y] >= 0 && map.mapStruct[x][y] < eventLoadCount)
                {
                    printC(mapString, 8);
                    mapString = "";
                    printC(listEvent[map.mapStruct[x][y]].eventSymbol, listEvent[map.mapStruct[x][y]].eventSymbolColor);
                }
                else
                {
                    printC(mapString, 8);
                    mapString = "";
                    printC("?", 14);
                }
            }

            printC(mapString, 8);
            mapString = "";
        }

        cout << "\n";
    }
    return;
}

void playerMove()
{
    char moveInput;

    moveInput = getch();

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
            printC("\n - Ban khong the di vao tuong! \n", 4);
            printC("\n > You can't go through the wall!\n", 4);

            MessageBox(0, " - Ban khong the di vao tuong! \n\n > You can't go through the wall!", "Thong bao cuc cang! (> Super cool notice!)", MB_OK);
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
            printC("\n - Ban khong the di vao tuong! \n", 4);
            printC("\n > You can't go through the wall!\n", 4);

            MessageBox(0, " - Ban khong the di vao tuong! \n\n > You can't go through the wall!", "Thong bao cuc cang! (> Super cool notice!)", MB_OK);
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

            printC("\n - Ban khong the di vao tuong! \n", 4);
            printC("\n > You can't go through the wall!\n", 4);

            MessageBox(0, " - Ban khong the di vao tuong! \n\n > You can't go through the wall!", "Thong bao cuc cang! (> Super cool notice!)", MB_OK);
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

            printC("\n - Ban khong the di vao tuong! \n", 4);
            printC("\n > You can't go through the wall!\n", 4);

            MessageBox(0, " - Ban khong the di vao tuong! \n\n > You can't go through the wall!", "Thong bao cuc cang! (> Super cool notice!)", MB_OK);
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
                    break;
                }
            }
        }
    }

    messageStart(1);
    printC("********************************", 7);

    messageBr();
    printC("*", 7);
    cout << setw(10) << " " << setw(10) << left << printC(player.getName(), 11) << setw(10) << " " << printC("*", 7);

    messageBr();
    printC("*", 7);
    cout << setw(10) << right << printC("Lv: ", 2);
    cout << setw(3) << right << printC(player.getLv(), 2);
    cout << setw(3) << right << "(" << printC("Exp: ", 10) << setw(6) << left << printC(player.getExp(), 10) << ")";
    cout << setw(3) << right << printC("*", 7);

    messageBr();
    printC("*", 7);
    cout << setw(10) << right << printC("HP: ", 4);
    cout << setw(9) << right << printC(player.getHp(), 4) << printC("/", 15);
    cout << setw(10) << left << printC(player.getHpMax(), 4) << printC("*", 7);

    messageBr();
    printC("*", 7);
    cout << setw(10) << right << printC("MP: ", 1);
    cout << setw(9) << right << printC(player.getMp(), 1) << printC("/", 15);
    cout << setw(10) << left << printC(player.getMpMax(), 1) << printC("*", 7);

    messageBr();
    printC("*", 7);
    cout << setw(10) << right << printC("Hunger: ", 5);
    cout << setw(9) << right << printC(player.getHunger(), 5) << printC("/", 15);
    cout << setw(10) << left << printC(player.getHungerMax(), 5) << printC("*", 7);

    messageBr();
    printC("*", 7);
    cout << setw(10) << right << printC("Gold: ", 6);
    cout << setw(10) << right << printC(player.getGold(), 6);
    cout << setw(10) << left << " " << printC("*", 7);

    messageBr();
    printC("********************************", 7);

    messageBr();
    printC(" - Ban la ", 7);
    printC("P", 9);
    printC("! ", 7);

    messageBr();
    printC(" - An ", 7);
    printC("W, A, S, D ", 13);
    printC("de di chuyen. ", 7);

    messageBr();
    messageBr();
    printC(" > You're ", 7);
    printC("P", 9);
    printC("!", 7);

    messageBr();
    printC(" > Press ", 7);
    printC("W, A, S, D ", 13);
    printC("to move. ", 7);

    messageEnd();

    playerMove();
}

void battleScreen()
{
    system("cls");
    char choice;

    cout << "\n\t"
         << "[" << printC(currentEvent.eventName, 11) << "]\n";

    cout << currentEvent.eventText << "\n\n";
}

void battleScreenShowStatus(char *choice)
{
    if (*choice == '1')
    {
        if ((player.getAtk() - currentEvent.eventEnemyDef) > 0)
        {
            cout << printC(" - Ban tan cong, ke dich nhan ", 15) << player.getAtk() - currentEvent.eventEnemyDef << printC(" sat thuong! \n", 15) << endl;

            currentEvent.eventEnemyHp -= (player.getAtk() - currentEvent.eventEnemyDef);
        }
        else
        {
            cout << printC(" - Ban qua yeu! Khong tao ra sat thuong! \n", 15);
        }

        if ((currentEvent.eventEnemyAtk - player.getDef()) > 0)
        {
            cout << printC(" - Ke dich tan cong, ban nhan ", 15) << currentEvent.eventEnemyAtk - player.getDef() << printC(" sat thuong! \n", 15) << endl;

            player.setHp((player.getHp() - (currentEvent.eventEnemyAtk - player.getDef())));
        }
        else
        {
            cout << printC(" Doi phuong qua yeu! Khong tao ra sat thuong! \n", 15) << endl;
        }
    }
}

void battleScreenShowMenu(char *choice)
{
    cout << "\t" << setw(50) << left << printC("***************************************************", 7) << endl;
    cout << "\t" << setw(50) << left << printC("* 1. Tan cong (> Attack). ", 15) << "*" << endl;
    cout << "\t" << setw(50) << left << printC("* 2. Phong thu va hoi mau (> Defense and heal). ", 15) << "*" << endl;
    cout << "\t" << setw(50) << left << printC("* 3. Ma thuat (> Magic). ", 15) << "*" << endl;
    cout << "\t" << setw(50) << left << printC("* 4. Dung vat pham (> Use item). ", 15) << "*" << endl;
    cout << "\t" << setw(50) << left << printC("* 5. Chay! (> Run!). ", 15) << "*" << endl;
    cout << "\t" << setw(50) << left << printC("***************************************************\n", 7) << endl;

#pragma region
    // New Message
    messageStart(1);
    printC("********************************", 7);

    messageBr();
    cout << printC("*", 7) << setw(10) << " " << setw(10) << left << printC(currentEvent.eventName, 11) << setw(10) << " " << printC("*", 7);

    messageBr();
    cout << printC("*", 7) << setw(10) << right << printC("HP: ", 4) << setw(10) << right << printC(currentEvent.eventEnemyHp, 4) << setw(10) << left << " " << printC("*", 7);

    messageBr();
    printC("********************************", 7);

    messageBr();
    messageBr();

    printC("********************************", 7);

    messageBr();
    printC("*", 7);
    cout << setw(10) << " " << setw(10) << left << printC(player.getName(), 11) << setw(10) << " " << printC("*", 7);

    messageBr();
    printC("*", 7);
    cout << setw(10) << right << printC("Lv: ", 2);
    cout << setw(3) << right << printC(player.getLv(), 2);
    cout << setw(3) << right << "(" << printC("Exp: ", 10) << setw(6) << left << printC(player.getExp(), 10) << ")";
    cout << setw(3) << right << printC("*", 7);

    messageBr();
    printC("*", 7);
    cout << setw(10) << right << printC("HP: ", 4);
    cout << setw(9) << right << printC(player.getHp(), 4) << printC("/", 15);
    cout << setw(10) << left << printC(player.getHpMax(), 4) << printC("*", 7);

    messageBr();
    printC("*", 7);
    cout << setw(10) << right << printC("MP: ", 1);
    cout << setw(9) << right << printC(player.getMp(), 1) << printC("/", 15);
    cout << setw(10) << left << printC(player.getMpMax(), 1) << printC("*", 7);

    messageBr();
    printC("********************************", 7);

    messageBr();
    printC(" - Ban la ", 7);
    printC("P", 9);
    printC("! ", 7);

    messageBr();
    printC(" - An ", 7);
    printC("W, A, S, D ", 13);
    printC("de di chuyen. ", 7);

    messageBr();
    messageBr();
    printC(" > You're ", 7);
    printC("P", 9);
    printC("!", 7);

    messageBr();
    printC(" > Press ", 7);
    printC("W, A, S, D ", 13);
    printC("to move. ", 7);

    messageEnd();
#pragma endregion

    if (currentEvent.eventEnemyHp <= 0)
    {
        screenStage = 1;
        cout << printC(" -> Chien thang! \n\n", 15) << endl;
        cout << printC(" --=> [ An phim bat ky de tiep tuc ] <=-- \n", 15) << endl;

        getch();
        return;
    }
    *choice = getch();
}