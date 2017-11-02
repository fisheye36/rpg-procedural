#pragma once

#include <string>
#include "character.h"

/**
 * Starts a new game.
 */
void startGame();

/**
 * Displays final player stats as well as a full list of every monster the player
 * has defeated.
 * @param player a pointer to a player stats array (aka int array)
 * @param playerName an std::string object containing a player name
 */
void gameOver(charSkills player, std::string playerName);
