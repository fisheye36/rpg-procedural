#include <iostream>
#include <string>

#include "game.h"
#include "character.h"

void startGame()
{
    using std::cout;

    std::string playerName;
    charSkills player = createCharacter(playerName);
    charSkills monster = createCharacter();

    cout << playerName << ":\n";
    displaySkills(player);
    cout << "Monster #" << monster[ID] << ":\n";
    displaySkills(monster);

    deleteCharacters();
}
