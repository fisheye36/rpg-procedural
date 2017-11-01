#pragma once

#include <string>

#define SKILLS_COUNT 5
#define ID 0

typedef int skill;
typedef skill * charSkills;

void startGame();
charSkills createCharacter(bool player = false);
charSkills createCharacter(std::string & playerName);

std::string getPlayerName();
