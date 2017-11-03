#include <iostream>
#include <string>
#include <cstdlib>

#include "fight.h"
#include "character.h"
#include "input.h"
#include "constants.h"

void fight(charSkills player, charSkills monster)
{
    bool playerTurn = trueOrFalse();
    charAttack attack = NULL;
    bool charDead;
    do
    {
        if (playerTurn)
            attack = playerAttack;
        else
            attack = monsterAttack;

        playerTurn = !playerTurn;
        charDead = attack(player, monster);
    } while (!charDead);
}

bool playerAttack(charSkills player, charSkills monster)
{
    std::cout << "Choose attack type:\n"
                 "N) Normal Attack (" << player[NA] << ")\n"
                 "M) Magic Attack (" << player[MA] << ")\n"
                 "Q) Suicide and quit\n\n";

    // we can use both letters and numbers, which is really handy
    const char availableOptions[] = {'n', 'm', 'q', '1', '2'};
    char choice = readKey(availableOptions, sizeof availableOptions);
    int damage;
    switch (choice)
    {
        case '1':
        case 'n':
            damage = calculateDmg(player[NA], monster[ND]);
            break;
        case '2':
        case 'm':
            damage = calculateDmg(player[MA], monster[MD]);
            break;
        case 'q':
            return hurtCharacter(player[HP], player[HP]);
    }
    displayDmg(player, monster, damage);

    return hurtCharacter(monster[HP], damage);
}

bool monsterAttack(charSkills player, charSkills monster)
{
    using std::cout;

    bool normalAttack = trueOrFalse();
    int damage;
    if (normalAttack)
    {
        cout << "Monster is doing Normal Attack...\n";
        damage = calculateDmg(monster[NA], player[ND]);
    }
    else
    {
        cout << "Monster is doing Magic Attack...\n";
        damage = calculateDmg(monster[MA], player[MD]);
    }
    displayDmg(monster, player, damage);

    return hurtCharacter(player[HP], damage);
}

bool trueOrFalse()
{
    return rand() % 2 == 0;
}

int calculateDmg(skill attack, skill defense)
{
    int damage = attack + modifier(attack) - defense;
    if (damage < 0)
        damage = 0;

    return damage;
}

int modifier(skill attack)
{
    double mod = double(rand()) / RAND_MAX;
    mod = mod * 2 * DMG_MODIFIER - DMG_MODIFIER;

    // no rounding - modifier value will be truncated to int
    return attack * mod;
}

void displayDmg(const charSkills attacker, const charSkills defender, int dmg)
{
    using std::cout;
    using std::string;

    string attackerName = (attacker[ID] == 0) ? "Player" : "Monster";
    string defenderName = (defender[ID] == 0) ? "Player" : "Monster";
    if (dmg)
        cout << attackerName << " did " << dmg << " damage to " << defenderName << ".\n";
    else
        cout << attackerName << " missed!\n";
}

bool hurtCharacter(skill & hp, int dmg)
{
    using std::endl;

    if (dmg > hp)
        hp = 0;
    else
        hp -= dmg;
    std::cout << "Remaining HP: " << hp << endl << endl;

    return hp == 0;
}
