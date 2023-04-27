#include "db.h"
#include "timdb.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void parse_cmds() {
    int i = 0;
    cmds[0] = strtok(input, " ");
    while(cmds[i] != NULL){
        i++;
        cmds[i] = strtok(NULL, " ");
    }

    i = 0;
    while(cmds[i] != NULL){

    }
}

void get_input() {
    printf(">> ");
    fflush(stdout);
    fgets(input, sizeof input, stdin);
    input[strcspn(input, "\n")] = '\0';
    if (strncmp(input, "quit", 4) == 0)
        Q_FLAG = false;
    else
        parse_cmds();
}

int main(int argc, char *argv[]) {
    if (argc == 0) {
        printf("Welcome to timdb\n");
        while (Q_FLAG) {
            get_input();
        }
    }
    else if (argc == 1) {
        printf("Usage: %s <db_name>\n", argv[0]);
        return -1;
    }
    else {
        for (int i = 0; i < argc; i++) {
            argv[i][strcspn(argv[i], "\n")] = '\0';
            strcat(input, argv[i]);
            strtcat(input, " ");
        }
        parse_cmds();
    }
    return 0;
}
