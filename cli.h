#ifndef CLI_H_
#define CLI_H_
#include <stdbool.h>

#define MAX_INPUT_LENGTH 2048
#define MAX_COMMAND_NUMBER 10
#define MAX_COMMAND_LENGTH 20

char input[MAX_INPUT_LENGTH];
char commands[10][20];
bool Q_FLAG = true;

void get_input();

#endif
