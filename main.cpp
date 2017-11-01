#include <iostream>

#include "rpg_strings.h"
#include "menus.h"

int main()
{
    using std::cout;

    cout << "Welcome to " << GameTitle << " game!\n\n";
    while (displayMainMenu())
        continue;
    cout << "Goodbye!\n";

    return 0;
}
