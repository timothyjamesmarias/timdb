#ifndef TIMDB_H_
#define TIMDB_H_
#include <stdbool.h>

#define MAX_INPUT_LENGTH 2048
#define MAX_ARGS 512

const char ** cmds = ["SHOW", "CREATE", "DELETE", "UPDATE", "INSERT"];
const char ** predicates = ["INTO", "FROM", "WHERE", "VALUES", "SET", "ALL"];
const char ** objects = ["DATABASE", "TABLE", "ROW", "COLUMN"];
const char ** types = ["INT", "FLOAT", "STRING", "TEXT", "BOOL"];
const char * variable = "X";

char input[MAX_INPUT_LENGTH];
char * cmds[MAX_ARGS];
bool Q_FLAG = true;

void get_input();

void parse_cmds();

void exec_cmds();

#endif
