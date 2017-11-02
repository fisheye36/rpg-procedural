#pragma once

/**
 * Displays main menu and asks for the user's choice. Returns a boolean value.
 * @return true when main menu should be displayed again, false otherwise
 */
bool displayMainMenu();

/**
 * Lets the user start a new game. Displays a prompt message about reading help
 * and asks for the user's choice.
 */
void newGame();

/**
 * Displays help menu.
 */
void displayHelp();

/**
 * Displays a prompt message and asks for the user's choice. Returns a boolean value.
 * @return true when the user wants to quit, false otherwise
 */
bool quitGame();
