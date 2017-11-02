#pragma once

#include <string>

typedef int skill;
typedef skill * charSkills;

charSkills createCharacter(bool player = false);
charSkills createCharacter(std::string & playerName);
void deleteCharacters();

void buildPlayer(charSkills player, int availableSkillPoints);
void buildMonster(charSkills monster);

void displaySkills(const charSkills character);
bool assignSkill(charSkills character, int & availableSkillPoints);
void modifySkill(skill & skilltToModify, int & availableSkillPoints);

std::string getPlayerName();
