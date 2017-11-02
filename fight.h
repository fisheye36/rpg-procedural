#pragma once

#include "character.h"

typedef bool (*charAttack)(charSkills, charSkills);

void fight(charSkills player, charSkills monster);
bool playerAttack(charSkills player, charSkills monster);
bool monsterAttack(charSkills player, charSkills monster);

int calculateDmg(skill attack, skill defense);
int modifier(skill attack);
void displayDmg(const charSkills attacker, const charSkills defender, int dmg);
bool hurtCharacter(skill & hp, int dmg);

bool trueOrFalse();
