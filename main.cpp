/**
 * A simple console rpg game intentionally written in procedural C++
 * (no user defined classes or even structs).
 * @author Kamil Warchol
 * https://github.com/fisheye36/rpg-procedural
 */

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
