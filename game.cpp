#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "game.h"
#include "character.h"
#include "fight.h"
#include "input.h"
#include "constants.h"

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
        cout << "-- You VERSUS Monster #" << monster[ID] << " --\n\n";
        srand(time(NULL));
        fight(player, monster);

        if (player[HP] > 0)
        {
            cout << "You slaughtered Monster #" << monster[ID] << "!\n"
                    "You leveled up! You gained " << PTS_PER_LVL << " new Skill Points.\n\n";
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

    cout << playerName << ", you are DEAD...\n"
            "Before you died, you have managed to kill " << g_characters.size() - 2
         << " monsters.\nBelow you can see your final stats:\n\n"
         << playerName << endl;
    displaySkills(player);

    if (g_characters.size() > 2)
    {
        cout << "And here is a complete list of every monster you have slaughtered:\n\n";
        for (unsigned i = 1u; i < g_characters.size() - 1u; i++)
        {
            readAnyKey();
            cout << "Monster #" << g_characters[i][ID] << endl;
            displaySkills(g_characters[i]);
        }
        readAnyKey();
    }
}
