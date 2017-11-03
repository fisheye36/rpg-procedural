#pragma once

#include "character.h"

// function pointer
typedef bool (*charAttack)(charSkills, charSkills);

/**
 * Controls fight mechanics. Calls either playerAttack() or monsterAttack().
 * @param player a pointer to a player stats array (aka int array)
 * @param monster a pointer to a monster stats array (aka int array)
 */
void fight(charSkills player, charSkills monster);

/**
 * Lets the user choose an attack type. Returns a boolean value.
 * @param player a pointer to a player stats array (aka int array)
 * @param monster a pointer to a monster stats array (aka int array)
 * @return true if a monster dies, false otherwise
 */
bool playerAttack(charSkills player, charSkills monster);

/**
 * Randomly chooses which attack type a monster does. Returns a boolean value.
 * @param player a pointer to a player stats array (aka int array)
 * @param monster a pointer to a monster stats array (aka int array)
 * @return true if a player dies, false otherwise
 */
bool monsterAttack(charSkills player, charSkills monster);

/**
 * Calculates effective attack damage. Returns an integer value.
 * @param attack a skill (aka int) for a particular attack type
 * @param defense a skill (aka int) for a particular defense type
 * @return an integer equal to the attack damage
 */
int calculateDmg(skill attack, skill defense);

/**
 * Calculates a modifier to an attack damage. Returns an integer value.
 * @param attack a skill (aka int) for a particular attack type
 * @return an integer equal to the calculated modifier
 */
int modifier(skill attack);

/**
 * Displays how much damage an attacker did to a defender.
 * @param attacker a pointer to an attacker stats array (aka int array) to be displayed
 * @param defender a pointer to a defender stats array (aka int array) to be displayed
 * @param dmg an integer holding effective attack damage
 */
void displayDmg(const charSkills attacker, const charSkills defender, int dmg);

/**
 * Subtracts HP by the amount of effective attack damage received. Returns a boolean
 * value.
 * @param hp a reference to a skill (aka int) to be modified
 * @param dmg an integer holding effective attack damage
 * @return true if HP falls down to 0, false otherwise
 */
bool hurtCharacter(skill & hp, int dmg);

/**
 * Randomly generates either true or false value. Returns a boolean value.
 * @return randomly generated true or false value
 */
bool trueOrFalse();
