#include "cli.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void parse_input() {
    switch(input) {
        case "create":
            printf("create\n");
            break;
        case "drop":
            printf("drop\n");
            break;
        case "use":
            printf("use\n");
            break;
        case "show":
            printf("show\n");
            break;
        case "quit":
            printf("quit\n");
            break;
        default:
            printf("Invalid command\n");
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
