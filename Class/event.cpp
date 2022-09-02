struct Event
{
    int eventType;
    int eventId;

    // type 0 = Text Event
    std::string eventText;
    int eventPlayerHp;
    int eventPlayerMp;
    int eventPlayerGold;
    int eventPlayerEp;
    int eventPlayerExp;

    // type 1 = Enemy
    std::string eventEnemyName;
    int eventEnemyHp;
    int eventEnemyAtk;
    int eventEnemyDef;


    Event(){}

    // constructor type 0
    Event(int eventTypeT, int eventIdT, std::string eventTextT, int eventPlayerHpT, int eventPlayerMpT, int eventPlayerGoldT, int eventPlayerEpT, int eventPlayerExpT)
    {
        eventType = eventTypeT;
        eventId = eventIdT;
        eventText = eventTextT;
        eventPlayerHp = eventPlayerHpT;
        eventPlayerMp = eventPlayerMpT;
        eventPlayerGold = eventPlayerGoldT;
        eventPlayerEp = eventPlayerEpT;
        eventPlayerExp = eventPlayerExpT;
    }

    // Constructor type 1
    Event(int eventTypeT, int eventIdT, std::string eventEnemyNameT, int eventEnemyHpT, int eventEnemyAtkT, int eventEnemyDefT)
    {
        eventType = eventTypeT;
        eventId = eventIdT;
        eventEnemyName = eventEnemyNameT;
        eventEnemyHp = eventEnemyHpT;
        eventEnemyAtk = eventEnemyAtkT;
        eventEnemyDef = eventEnemyDefT;
    }

    ~Event() {}

    void triggerEvent()
    {
        if (eventId == 0)
        {
            printC("Event Text \n", 14);
            cout << "type: " << eventType << endl;
            cout << "Text: " << eventText << endl;

        }
        else if (eventId == 1)
        {
            printC("Event Enemy \n", 14);
            cout << "type: " << eventType << endl;
            cout << "name: " << eventEnemyName<< endl;

        }
        else 
        {
            printC("Loi Event\n", 14);
            
        }
    }

    int getEventId()
    {
        return eventId;
    }
};

int eventCount = 2;
Event currentEvent = Event();
Event listEvent[16];
