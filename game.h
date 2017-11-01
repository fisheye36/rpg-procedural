#pragma once

#include <string>

#define SKILLS_COUNT 5
#define ID 0
#define NA 1
#define ND 2
#define MA 3
#define MD 4
#define HP 5

typedef int skill;
typedef skill * charSkills;

void startGame();

charSkills createCharacter(bool player = false);
charSkills createCharacter(std::string & playerName);
void deleteCharacters();

void createPlayer(charSkills player);
void displaySkills(const charSkills character);
bool changeSkill(charSkills character, int & availableSkillPoints);

std::string getPlayerName();
