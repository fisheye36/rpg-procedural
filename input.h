#pragma once

#include <string>

void readAnyKey();
char readKey(const char * availableOptions, int optionsCount);

char readChar();
std::string readString();
void flushInput();
