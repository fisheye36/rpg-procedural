#include <iostream>

#include "rpg_strings.h"
#include "menus.h"

int main()
{
    std::cout << "Welcome to " << GameTitle << " game!\n\n";
    displayMainMenu();

    return 0;
}
