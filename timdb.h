#ifndef TIMDB_H_
#define TIMDB_H_
#include <stdbool.h>

#define MAX_INPUT_LENGTH 2048
#define MAX_ARGS 512

char input[MAX_INPUT_LENGTH];
char * cmds[MAX_ARGS];
bool Q_FLAG = true;

void get_input();

void parse_cmds();

void exec_cmds();

#endif
