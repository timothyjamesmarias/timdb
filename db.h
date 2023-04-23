#ifndef DB_H_
#define DB_H_
#include <stdio.h>

#define MAX_LINE_LENGTH 100

/*
 * This function gets the file name from a file pointer
 * @param fp: file pointer
 * @return file name
 */
char * get_file_name(FILE * fp);

/*
 * This function checks if a string is present in a file
 * @param fp: file pointer
 * @param string: string to be searched
 * @return 1 if string is present, 0 if string is not present, -1 if error
 */
int is_present_in_file(FILE * fp, char *string);

/*
 * This function checks if a string is present in a file
 * @param fp: file pointer
 * @param string: string to be searched
 * @return 1 if string is present, 0 if string is not present, -1 if error
 */
int create_db(char *db_name);

/* 
 * This function drops a database
 * @param db_name: name of the database to be dropped
 * @return 0 if successful, -1 if error
 */
int drop_db(char *db_name);

/* 
 * This function creates a table in a database
 * @param db_name: name of the database
 * @param table_name: name of the table to be created
 * @return 0 if successful, -1 if error
 */
int create_table(char *table_name);

/* 
 * This function drops a table in a database
 * @param db_name: name of the database
 * @param table_name: name of the table to be dropped
 * @return 0 if successful, -1 if error
 */
int drop_table(char *table_name);

/* 
 * This function creates a column in a table
 * @param db_name: name of the database
 * @param table_name: name of the table
 * @param column_name: name of the column to be created
 * @param data_type: data type of the column to be created
 * @return 0 if successful, -1 if error
 */
int create_column(char *table_name, char *column_name, char * data_type);

/* 
 * This function drops a column in a table
 * @param table_name: name of the table
 * @param column_name: name of the column to be dropped
 * @return 0 if successful, -1 if error
 */
int drop_column(char *table_name, char *column_name);

/* 
 * This function inserts a row in a table
 * @param table_name: name of the table
 * @param data: string of data to be inserted
 * @return 0 if successful, -1 if error
 */
int insert_row(char *table_name, char *data);

/* 
 * This function deletes a row in a table
 * @param table_name: name of the table
 * @param number: number of the row to be deleted
 * @return 0 if successful, -1 if error
 */
int delete_row(char *table_name, char *number);

/* 
 * This function updates a row in a table
 * @param table_name: name of the table
 * @param number: number of the row to be updated
 * @param data: string of data to be updated
 * @return 0 if successful, -1 if error
 */
int update_row(char *table_name, char *number, char *data);

#endif

