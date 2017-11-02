#include <string>

#include "game.h"
#include "character.h"

void startGame()
{
    std::string playerName;
    charSkills player = createCharacter(playerName);
    deleteCharacters();
}
