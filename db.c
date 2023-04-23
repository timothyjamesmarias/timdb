#inlcude "db.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

/*
 * This function checks if a string is present in a file
 * @param fp: file pointer
 * @param string: string to be searched
 * @return 1 if string is present, 0 if string is not present, -1 if error
 */
int is_present_in_file(FILE * fp, char *string){
    if (fp == NULL){
        fprintf(stderr, "Could not open file %s\n", file_name);
        return -1;
    }
    else {
        char line[100];
        while (fgets(line, 100, fp) != NULL){
            if (strstr(line, string) != NULL){
                return 1;
            }
        }
        return 0;
    }
}

int create_db(char *db_name){
    int status = mkdir(db_name, 0777);
    if (status == 0){
        printf("Database %s created successfully\n", db_name);
        return 0;
    }
    else{
        fprintf(stderr, "Could not create database %s\n", db_name);
        return -1;
    }
}

int drop_db(char *db_name){
    int status = rmdir(db_name);
    if (status == 0){
        printf("Database %s dropped successfully\n", db_name);
        return 0;
    }
    else{
        fprintf(stderr, "Could not drop database %s\n", db_name);
        return -1;
    }
}


int create_table(char *db_name, char *table_name){
    if (access(table_name, F_OK) == 0){ // check if the table exists
        fprintf(stderr, "Table %s already exists\n", table_name);
        return -1;
    }
    else {
        FILE *fp = fopen(table_name, "w"); // create the table file
        if (fp == NULL){
            fprintf(stderr, "Could not create table %s\n", table_name);
            return -1;
        }
        else {
            printf("Table %s created successfully\n", table_name);
            fclose (table_fp);
            return 0;
        }
    }
            
}

int drop_table(char *db_name, char *table_name){
    int status = remove(table_name);
    if (status == 0){
        printf("Table %s dropped successfully\n", table_name);
        return 0;
    }
    else{
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

int drop_column(char *db_name, char *table_name, char *column_name){
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
        if(!is_present_in_file(table_fp, column_name)){
            fprintf(stderr, "Column %s does not exist\n", column_name);
            fclose (table_fp);
            return -1;
        }

    }
}

int insert_row(char *db_name, char *table_name, char *data){

}

int delete_row(char *db_name, char *table_name, char *number);
int update_row(char *db_name, char *table_name, char *number, char *data);




