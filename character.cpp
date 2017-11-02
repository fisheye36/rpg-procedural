#include <iostream>
#include <string>
#include <vector>

#include "character.h"
#include "input.h"

// holds characters' stats
std::vector<charSkills> g_characters;

charSkills createCharacter(bool player)
{
    charSkills newCharacter = new skill[SKILLS_COUNT + 1];
    newCharacter[ID] = g_characters.size();
    for (int i = 1; i < SKILLS_COUNT + 1; i++)
        newCharacter[i] = 0;
    g_characters.push_back(newCharacter);

    if (player)
        createPlayer(newCharacter);
    // else
        // createMonster(newCharacter);

    return newCharacter;
}

charSkills createCharacter(std::string & playerName)
{
    playerName = getPlayerName();
    return createCharacter(true);
}

void deleteCharacters()
{
    charSkills toBeDeleted;
    while (!g_characters.empty())
    {
        toBeDeleted = g_characters.back();
        g_characters.pop_back();
        delete[] toBeDeleted;
    }
}

void createPlayer(charSkills player)
{
    bool finished = false;
    int availableSkillPoints = 20;
    do
    {
        displaySkills(player);
        finished = changeSkill(player, availableSkillPoints);
    } while (!finished);
}

void displaySkills(const charSkills character)
{
    using std::endl;

    std::cout << "1) NA (Normal Attack): " << character[NA] << endl
              << "2) ND (Normal Defense): " << character[ND] << endl
              << "3) MA (Magic Attack): " << character[MA] << endl
              << "4) MD (Magic Defense): " << character[MD] << endl
              << "5) HP (Health Points): " << character[HP] << endl << endl;
}

bool changeSkill(charSkills character, int & availableSkillPoints)
{
    using std::cout;

    bool finished = false;
    if (!availableSkillPoints && character[HP] > 0)
    {
        cout << "All Skill Points have been used.\n"
                "Do you want to finish your build? (y/n)\n";

        const char availableOptions[] = {'y', 'n'};
        char choice = readKey(availableOptions, sizeof availableOptions);
        finished = choice == 'y';
    }

    if (!finished)
    {
        cout << "Available Skill Points: " << availableSkillPoints << std::endl
             << "First, choose a skill to modify.\n";
        int chosenSkill = readNum(1, SKILLS_COUNT);
        cout << "Next, enter the amount (positive or negative).\n";
        int amount = readNum(-character[chosenSkill], availableSkillPoints);

        character[chosenSkill] += amount;
        availableSkillPoints -= amount;
    }

    return finished;
}

std::string getPlayerName()
{
    using std::cout;

    cout << "Enter your character's name: ";
    std::string name = readString();
    cout << std::endl;

    return name;
}
