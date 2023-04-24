#include "cli.h"
#include "db.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void parse_input() {
    char *token = strtok(input, " ");
    switch(token) {
        case "create":
            token = strtok(NULL, " ");
            if (strcmp(token, "database") == 0) {
                token = strtok(NULL, " ");
                create_db(token);
            }
            else if (strcmp(token, "table") == 0) {
                token = strtok(NULL, " ");
                create_table(token);
            }
            else {
                fprintf(stderr, "Invalid syntax\n");
            }
            break;
    }
}

void get_input() {
    printf(">> ");
    fflush(stdout);
    fgets(input, sizeof input, stdin);
    input[strcspn(input, "\n")] = '\0';
    if (strcmp(input, "quit") == 0)
        Q_FLAG = false;
}

int main() {
    while (Q_FLAG)
        get_input();
    return 0;
}
