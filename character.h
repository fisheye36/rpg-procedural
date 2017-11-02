#pragma once

#include <string>

#define STARTING_PTS_PLAYER 20
#define STARTING_PTS_MONSTER 15

#define SKILLS_COUNT 5
#define ID 0
#define NA 1
#define ND 2
#define MA 3
#define MD 4
#define HP 5

typedef int skill;
typedef skill * charSkills;

charSkills createCharacter(bool player = false);
charSkills createCharacter(std::string & playerName);
void deleteCharacters();

void createPlayer(charSkills player);
void createMonster(charSkills monster);

void displaySkills(const charSkills character);
bool assignSkill(charSkills character, int & availableSkillPoints);
void modifySkill(skill & skilltToModify, int & availableSkillPoints);

std::string getPlayerName();
