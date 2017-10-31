#include <iostream>

#include "rpg_strings.h"
#include "menus.h"

int main()
{
    std::cout << "Welcome to " << GameTitle << " game!\n\n";
    while (displayMainMenu())
        continue;

    return 0;
}
