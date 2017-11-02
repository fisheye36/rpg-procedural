#include <iostream>
#include "menus.h"

int main()
{
    using std::cout;

    cout << "Welcome to RPG-Procedural game!\n\n";
    while (displayMainMenu())
        continue;
    cout << "Goodbye!\n";

    return 0;
}
