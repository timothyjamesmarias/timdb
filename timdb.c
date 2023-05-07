#include "timdb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>

char * get_file_name(FILE * fp) {
    int fd = fileno(fp); // get the file descriptor
    char path[255]; // path to the file
    char *filename = malloc(255); // filename
    sprintf(path, "/proc/self/fd/%d", fd); // get the path to the file
    ssize_t len = readlink(path, filename, 255); // read the link
    if (len < 0) // check if the link was read successfully
        return NULL;
    filename[len] = '\0'; // add the null terminator
    return filename; // return the filename
} 

int is_present_in_file(FILE * fp, char *string) {
    if (fp == NULL) {
        fprintf(stderr, "Could not open file");
        return -1;
    }
    else {
        char line[100];
        while (fgets(line, 100, fp) != NULL) {
            if (strstr(line, string) != NULL) {
                return 1;
            }
        }
        return 0;
    }
}

int create_db(char *db_name) {
    int status = mkdir(db_name, 0777);
    if (status == 0) {
        printf("Database %s created successfully\n", db_name);
        return 0;
    }
    else {
        fprintf(stderr, "Could not create database %s\n", db_name);
        return -1;
    }
}

int drop_db(char *db_name) {
    int status = rmdir(db_name);
    if (status == 0) {
        printf("Database %s dropped successfully\n", db_name);
        return 0;
    }
    else {
        fprintf(stderr, "Could not drop database %s\n", db_name);
        return -1;
    }
}

int create_table(char *table_name) {
    if (access(table_name, F_OK) == 0){ // check if the table exists
        fprintf(stderr, "Table %s already exists\n", table_name);
        return -1;
    }
    else {
        FILE *table_fp = fopen(table_name, "w"); // create the table file
        if (table_fp == NULL) {
            fprintf(stderr, "Could not create table %s\n", table_name);
            fclose(table_fp);
            return -1;
        }
        else {
            printf("Table %s created successfully\n", table_name);
            fclose(table_fp);
            return 0;
        }
    }
            
}

int drop_table(char *table_name){
    int status = remove(table_name);
    if (status == 0) {
        printf("Table %s dropped successfully\n", table_name);
        return 0;
    }
    else {
        fprintf(stderr, "Could not drop table %s\n", table_name);
        return -1;
    }
}

int create_column(char *table_name, char *column_name, char *data_type){
    if (access(table_name, F_OK) != 0){ // check if the table exists
        fprintf(stderr, "Table %s does not exist", table_name);
        return -1;
    }

    FILE * table_fp = fopen(table_name, "rw");
    if (table_fp == NULL){
        fprintf(stderr, "Could not open table %s\n", table_name);
        return -1;
    }
    else {
        if(is_present_in_file(table_fp, column_name) == 1){
            fprintf(stderr, "Column %s already exists\n", column_name);
            fclose (table_fp);
            return -1;
        }
        fprintf(table_fp, "%s %s\n", column_name, data_type);
        printf("Column %s created successfully\n", column_name);
        fclose (table_fp);
        return 0;
    }
}

int drop_column(char *table_name, char *column_name) {

    if (access(table_name, F_OK) != 0){ // check if the table exists
        fprintf(stderr, "Table %s does not exist", table_name);
        return -1;
    }

    char * temp_name = malloc(strlen(table_name) + 6); // 6 is the length of "_temp"
    strcpy(temp_name, table_name); // copy table_name to temp_name
    strcat(temp_name, "_temp"); // append "_temp" to temp_name
    FILE * table_fp = fopen(table_name, "r"); // open the table file
    FILE * temp_fp = fopen(temp_name, "w"); // open the temp file
    bool keep_reading = true; // flag to keep reading the table file
    char line[MAX_LINE_LENGTH]; // line to be read from the table file
    int curr_line = 1; // current line number
    int delete_line = 0; // line number to be deleted

    if (table_fp == NULL || temp_fp == NULL) {
        fprintf(stderr, "Could not open table %s\n", table_name);
        free(temp_name);
        return -1;
    }
    else {
        if(!is_present_in_file(table_fp, column_name)) { // check if the column exists
            fprintf(stderr, "Column %s does not exist\n", column_name);
            fclose (table_fp);
            fclose (temp_fp);
            free(temp_name);
            return -1;
        }
        else {
            do {
                fgets(line, MAX_LINE_LENGTH, table_fp);
                if (feof(table_fp)){
                    keep_reading = false;
                }
                else if (curr_line != delete_line) { // if the current line is not the line to be deleted
                    fprintf(temp_fp, "%s", line); // write the line to the temp file
                }
                curr_line++;
            } while (keep_reading);

            fclose (table_fp);
            fclose (temp_fp);

            remove(table_name); // delete the table file
            rename(temp_name, table_name); // rename the temp file to the table file
            free(temp_name);

            return 0;
        }
    }
}

void load_cmds() {
    int i = 0;
    cmds[0] = strtok(input, " ");
    while(cmds[i] != NULL){
        i++;
        cmds[i] = strtok(NULL, " ");
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
        load_cmds();
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
