#include "db.h"
#include "timdb.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void parse_input() {
}

void get_user_input() {
    printf(">> ");
    fflush(stdout);
    fgets(input, sizeof input, stdin);
    input[strcspn(input, "\n")] = '\0';
    if (strcmp(input, "quit") == 0)
        Q_FLAG = false;
}

int main() {
    printf("Welcome to timdb\n");
    while (Q_FLAG) {
        get_user_input();
    }
    return 0;
}
