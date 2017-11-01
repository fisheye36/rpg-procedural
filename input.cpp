#include <iostream>
#include <cctype>

#include "input.h"

void readAnyKey()
{
    using std::cout;

    cout << "Press ENTER to continue...\n";
    // make sure we only have one blank line between user input
    // and next program output, regardless of whether the user
    // just pressed ENTER or typed in some characters before
    bool anyInput = false;
    while (std::cin.get() != '\n')
        anyInput = true;

    if (anyInput)
        cout << std::endl;
}

char readKey(const char * availableOptions, int optionsCount)
{
    using std::cout;

    cout << "Your choice: ";
    bool wrongChoice = true;
    char choice;
    while (wrongChoice)
    {
        choice = readChar();
        for (int i = 0; i < optionsCount; i++)
            if (choice == availableOptions[i])
            {
                wrongChoice = false;
                break;
            }

        if (wrongChoice)
            cout << "\aTry again: ";
    }
    cout << std::endl;

    return choice;
}

char readChar()
{
    char ch;
    while ((ch = std::cin.get()) == '\n')
        continue;
    flushInput();

    return tolower(ch);
}

std::string readString()
{
    std::string str;
    do
        std::getline(std::cin, str);
    while (str.empty());

    return str;
}

void flushInput()
{
    using std::cin;

    cin.clear();
    while (cin.get() != '\n')
        continue;
}
