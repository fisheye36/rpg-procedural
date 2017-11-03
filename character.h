#pragma once

#include <string>

typedef int skill;
typedef skill * charSkills;

/**
 * Allocates memory for a new character, sets character ID and calls
 * buildPlayer() or buildMonster(), depending on whether the player or the monster
 * is being created. Returns a pointer to the newly created character array
 * (aka int array).
 * @param player a boolean value telling the function to create either a player
 *        or a monster; defaults to false
 * @return a pointer to the newly created character stats array (aka int array)
 */
charSkills createCharacter(bool player = false);

/**
 * Reads player name and calls createCharacter(bool).
 * @param playerName a reference to an std::string object to store a player name in
 * @return a pointer to the newly created character stats array (aka int array)
 */
charSkills createCharacter(std::string & playerName);

/**
 * Frees allocated memory for all created characters during one gameplay.
 */
void deleteCharacters();

/**
 * Lets the user build a player character. Displays current stats and lets
 * the user assign Skill Points to a particular skill until available Skill Points
 * are depleted.
 * @param player a pointer to a player stats array (aka int array)
 * @param availableSkillPoints an integer holding available Skill Points
 */
void buildPlayer(charSkills player, int availableSkillPoints);

/**
 * Generates a monster character. Randomly modifies a particular skill until
 * available Skill Points are depleted.
 * @param monster a pointer to a monster stats array (aka int array)
 */
void buildMonster(charSkills monster);

/**
 * Displays character skills.
 * @param character a pointer to a character stats array (aka int array) to be
 *        displayed
 */
void displaySkills(const charSkills character);

/**
 * Lets the user choose a particular skill to modify and then the amount.
 * Returns a boolean value.
 * @param player a pointer to a player stats array (aka int array) to be modified
 * @param availableSkillPoints a reference to an integer holding available Skill Points
 * @return true when the user finished building a player character, false otherwise
 */
bool assignSkill(charSkills player, int & availableSkillPoints);

/**
 * Modifies a particular skill by a random amount.
 * @param skillToModify a reference to a skill (aka int) to be modified
 * @param availableSkillPoints a reference to an integer holding available Skill Points
 */
void modifySkill(skill & skilltToModify, int & availableSkillPoints);

/**
 * Prompts the user to enter a player name. Returns an std::string object.
 * @return a string containing player name
 */
std::string getPlayerName();
