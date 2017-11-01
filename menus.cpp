#include <iostream>

#include "menus.h"
#include "input.h"

bool displayMainMenu()
{
    std::cout << "---- MAIN MENU ----\n\n"
                 "1) Start new game\n"
                 "2) Show help & controls\n"
                 "3) Quit\n\n";

    const char availableOptions[] = {'1', '2', '3'};
    // no need to evaluate sizeof availableOptions / sizeof (char)
    // because C++ treats sizeof (char) as 1 on every implementation
    char choice = readKey(availableOptions, sizeof availableOptions);
    bool displayAgain = true;
    switch (choice)
    {
        case '1':
            //newGame();
            break;
        case '2':
            displayHelp();
            break;
        case '3':
            displayAgain = !quitGame();
            break;
        default:
            //gameError();
            displayAgain = false;
    }

    return displayAgain;
}

void displayHelp()
{
    std::cout << "---- HELP MENU ----\n\n"
                 "No help currently available.\n\n";
    readAnyKey();
}

bool quitGame()
{
    std::cout << "Are you sure you want to quit? (y/n)\n";

    const char availableOptions[] = {'y', 'n'};
    char choice = readKey(availableOptions, sizeof availableOptions);

    return choice == 'y';
}
