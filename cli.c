#include "cli.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void get_input(){
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
