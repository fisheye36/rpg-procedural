#pragma once

#include <string>

void readAnyKey();
char readKey(const char * availableOptions, int optionsCount);
int readNum(int min, int max);

char readChar();
std::string readString();
void flushInput();
