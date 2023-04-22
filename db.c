#inlcude "db.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int create_db(char *name){
    FILE *fp;
    fp = fopen(name, "w");
    if(fp == NULL){
        return -1;
    }
    fclose(fp);
    return 0;
}

int drop_db(char *name){
    if(remove(name) == 0){
        return 0;
    }
    return -1;
}

int create_column(char *db_name, char *name, char *column_name, char *type){
    FILE *fp;
    fp = fopen(db_name, "a");
    if(fp == NULL){
        return -1;
    }
    fprintf(fp, "%s %s %s
}
