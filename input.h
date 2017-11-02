#pragma once

#include <string>

/**
 * Prompts the user to press ENTER, clears input stream.
 */
void readAnyKey();

/**
 * Prompts the user to choose only on of the available options.
 * Clears input stream afterwards and returns user's choice as a char variable.
 * @param availableOptions a pointer to a char array containing available menu options
 * @optionsCount an integer containing the size of the char array
 * @return user's choice (equal to one of the elements of the array pointed by
 *         availableOptions)
 */
char readKey(const char * availableOptions, int optionsCount);

/**
 * Prompts the user to enter an integer number between min and max (both inclusive).
 * Clears input stream afterwards and returns user's choice as an integer variable.
 * @min minimum integer number the user is allowed to enter
 * @max maximum integer number the user is allowed to enter
 * @return an integer number entered by the user (between min and max, both inclusive)
 */
int readNum(int min, int max);



/**
 * Reads a single character from standard input (excluding newline). Clears input stream
 * afterwards and returns read character converted to lowercase as a char variable.
 * @return a single, lowercase character
 */
char readChar();

/**
 * Reads a non-empty string from standard input (which can contain several words). Returns
 * read string as an std::string object.
 * @return a non-empty string
 */
std::string readString();

/**
 * Clears input stream so the next input operation won't fail.
 */
void flushInput();
