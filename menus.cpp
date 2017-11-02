#include <iostream>

#include "menus.h"
#include "input.h"
#include "game.h"
#include "constants.h"

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
            newGame();
            break;
        case '2':
            displayHelp();
            break;
        case '3':
            displayAgain = !quitGame();
            break;
        default:
            gameError();
            displayAgain = false;
    }

    return displayAgain;
}

void newGame()
{
    std::cout << "It is advised to read help before starting.\n"
                 "Do you want to show the help menu? (y/n)\n";

    const char availableOptions[] = {'y', 'n'};
    char choice = readKey(availableOptions, sizeof availableOptions);
    if (choice == 'y')
        displayHelp();
    else
        startGame();
}

void displayHelp()
{
    std::cout << "---- HELP MENU ----\n\n"
                 "-- CHARACTER CREATION --\n\n"
                 "Characters have 5 basic skills:\n\n"
                 "NA (Normal Attack)\n"
                 "ND (Normal Defense)\n"
                 "MA (Magic Attack)\n"
                 "MD (Magic Defense)\n"
                 "HP (Health Points)\n\n"
                 "You start with " << STARTING_PTS_PLAYER << " Skill Points"
                 " which you can assign to any skills listed above.\n"
                 "To finish building your character you MUST use all your Skill Points\n"
                 "and you must have AT LEAST 1 Skill Point assigned to HP.\n\n"
                 "Monsters have randomly generated skills. First monster starts with\n"
                 "1 HP and then it has " << STARTING_PTS_MONSTER << " Skill Points"
                 " available.\nNext monster starts with 2 HP and has "
              << STARTING_PTS_MONSTER + 1 << " Skill Points available, and so on.\n\n"
                 "-- FIGHT --\n\n"
                 "Fighting is divided into turns. Player is first to make his move.\n"
                 "In your turn you can either make normal or magic attack.\n"
                 "Attack Damage equals your AS (Attack Skill) + Modifier.\n"
                 "The Modifier is a random number between -AS/2 and AS/2.\n"
                 "For example, if you have 10 NA, your attack does from 5 to 15 AD.\n"
                 "Finally, effective damage equals AD - OD (Opponent Defense).\n"
                 "If AD < OD then the attack deals no damage at all.\n\n"
                 "-- GAME PROGRESSION --\n\n"
                 "After a successfull kill you get " << PTS_PER_LVL << " additional"
                 " Skill Points to use.\nUse them to boost your skills or heal up!\n"
                 "And remember that next monster will be a tougher one.\n\n"
                 "-- GAME END --\n\n"
                 "The game is finished when your character dies.\n"
                 "After you are dead you will see your final stats\n"
                 "and stats of every monster you have defeated.\n"
                 "Slay as many monsters as you can!\n\n";

    readAnyKey();
}

bool quitGame()
{
    std::cout << "Are you sure you want to quit? (y/n)\n";

    const char availableOptions[] = {'y', 'n'};
    char choice = readKey(availableOptions, sizeof availableOptions);

    return choice == 'y';
}

void gameError()
{
    std::cout << "\aAn error has occurred!\n\n";
}
