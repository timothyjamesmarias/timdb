#ifndef DB_H_
#define DB_H_

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

int create_db(char *db_name);
int drop_db(char *db_name);

int create_table(char *db_name, char *table_name, char *columns);
int drop_table(char *db_name, char *table_name);

int create_column(char *db_name, char *table_name, char *column_name, char *data_type);
int drop_column(char *db_name, char *table_name, char *column_name);

int insert_row(char *db_name, char *table_name, char *data);
int delete_row(char *db_name, char *table_name, char *number);
int update_row(char *db_name, char *table_name, char *number, char *data);

#endif

