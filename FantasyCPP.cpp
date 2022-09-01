#include "./Class/lib.cpp"

using namespace std;


int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

int randomChoice(int option1, int option2)
{
    int temp;
    temp = random(1, 2);
    if (temp == 1)
        return option1;
    return option2;
}

void start()
{
    srand(time(NULL));
}

void update()
{
    MainMenu mainMenu = MainMenu();

    mainMenu.ShowMenu();
}

int main()
{
    start();
    update();
    return 0;
}