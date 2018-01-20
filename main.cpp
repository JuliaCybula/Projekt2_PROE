#include "WydarzeniePochodna.h"
#include "Terminarz.h"
#include "Menu.h"

void clearScreen();

int main()
{
    Terminarz<WydarzeniePochodna> pt;
    bool koniec=false;
    while(!koniec)
    {
        clearScreen();
        wyswietlMenu();
        menu(koniec,pt);
    }

    return 0;
}

void clearScreen()
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system ("clear");
    #endif
}
