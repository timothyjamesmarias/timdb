#ifndef DB_H_
#define DB_H_
#include <string.h>

/* 
 * Column struct to hold the name of the column and the data type
 * of the column. 
 */
struct column {
    char * name;
    char * data_type;
    int data_size;
};

/* 
 * Row struct to hold the data of the row and the size of the data.
 */
struct row {
    char * number;
    char * data;
    int data_size;
};

/* 
 * Table struct to hold the name of the table, the columns of the table,
 * the number of columns, the rows of the table, and the number of rows.
 */
struct table {
    char * name;
    struct column *columns;
    int num_columns;
    struct row *rows;
    int num_rows;
};

/* 
 * Database struct to hold the tables of the database and the number of tables.
 */
struct db {
  struct table *tables;
  int num_tables;
};

/* 
 * Function to create a new database.
 * @param name - the name of the database
 * @return 0 if successful, -1 if not
 */
int create_db(char *name);

/* 
 * Function to drop a database.
 * @param name - the name of the database
 * @return 0 if successful, -1 if not
 */
int drop_db(char *name);

/*
 * Function to create a new table.
 * @param name - the name of the table
 * @param columns - the columns of the table
 * @param num_columns - the number of columns
 * @return 0 if successful, -1 if not
 */
int create_column(char *name, char *data_type, int data_size);

/*
 * Function to drop a table.
 * @param name - the name of the table
 * @return 0 if successful, -1 if not
 */
int delete_column(char *name);

/*
 * Function to create a new row.
 * @param data - the data of the row
 * @param data_size - the size of the data
 * @return 0 if successful, -1 if not
 */
int create_row(char *data, int data_size);

/*
 * Function to drop a row.
 * @param data - the data of the row
 * @return 0 if successful, -1 if not
 */
int delete_row(char *data, int data_size);

/*
 * Function to drop a row.
 * @param data - the data of the row
 * @return 0 if successful, -1 if not
 */
int create_table(char *name, struct column *columns, int num_columns);

#endif
