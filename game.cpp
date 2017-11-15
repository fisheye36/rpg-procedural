#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>
#include <ctime>

#include "game.h"
#include "character.h"
#include "fight.h"
#include "input.h"
#include "constants.h"

// holds characters stats, defined in characters.cpp
extern std::vector<charSkills> g_characters;

void startGame()
{
    using std::cout;

    std::string playerName;
    charSkills player = createCharacter(playerName);
    charSkills monster = NULL;

    while (player[HP] > 0)
    {
        monster = createCharacter();
        cout << "-- " << playerName << " VERSUS Monster #" << monster[ID] << " --\n\n";
        // prepare seed for random number generator
        // which is used in several functions in fight.cpp
        srand(time(NULL));
        fight(player, monster);

        if (player[HP] > 0)
        {
            cout << "You slaughtered Monster #" << monster[ID] << "!\n";
            displaySkills(monster);
            readAnyKey();
            cout << "You leveled up! You gained " << PTS_PER_LVL
                 << " new Skill Points.\n\n";
            buildPlayer(player, PTS_PER_LVL);
        }
    }
    gameOver(player, playerName);
    deleteCharacters();
}

void gameOver(charSkills player, std::string playerName)
{
    using std::cout;
    using std::endl;

    const int charAmount = g_characters.size();
    cout << playerName << ", you are DEAD...\n"
            "You were killed by Monster #" << charAmount - 1 << ":\n\n";
    displaySkills(g_characters[charAmount - 1]);
    readAnyKey();

    const std::string monster = (charAmount - 2 == 1) ? "monster" : "monsters";
    cout << "Before you died, you have managed to kill " << charAmount - 2
         << " " << monster << ".\nBelow you can see your final stats:\n\n"
         << playerName << endl;
    displaySkills(player);

    if (charAmount > 2)
    {
        cout << "And here is a complete list of every monster you have slaughtered:\n\n";
        for (int i = 1; i < charAmount - 1; i++)
        {
            readAnyKey();
            cout << "Monster #" << g_characters[i][ID] << endl;
            displaySkills(g_characters[i]);
        }
        readAnyKey();
    }
}
