#include <iostream>
#include "menus.h"

void displayMainMenu()
{
    std::cout << "---- MAIN MENU ----\n\n"
                 "1) Start new game\n"
                 "2) Show help & controls\n"
                 "3) Quit\n\n";

    char availableOptions[] = {'1', '2', '3'};
    char choice = readKey(availableOptions, sizeof availableOptions);
    switch (choice)
    {
        case '1':
            //newGame();
            break;
        case '2':
            displayHelp();
            break;
        case '3':
            //quitGame();
            break;
        default:
            //gameError();
            break;
    }
}

void displayHelp()
{
    std::cout << "---- HELP MENU ----\n\n"
                 "No help currently available.\n\n";
    readAnyKey();
}

void readAnyKey()
{
    using std::cout;

    cout << "Press ENTER to continue...\n";
    while (std::cin.get() != '\n')
        continue;
    cout << std::endl;
}

char readKey(char * availableOptions, int optionsCount)
{
    using std::cout;
    using std::cin;

    cout << "Your choice: ";
    bool wrongChoice = true;
    char choice;
    while (wrongChoice)
    {
        cin.get(choice);
        cin.clear();
        while (cin.get() != '\n')
            continue;

        for (int i = 0; i < optionsCount; i++)
            if (choice == availableOptions[i])
            {
                wrongChoice = false;
                break;
            }

        if (wrongChoice)
            cout << "Try again: ";
    }
    cout << std::endl;

    return choice;
}
