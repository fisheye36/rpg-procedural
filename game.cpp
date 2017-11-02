#include <iostream>
#include <string>
#include <cstdlib>

#include "game.h"
#include "character.h"
#include "fight.h"
#include "constants.h"

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
    //gameOver();
    deleteCharacters();
}
