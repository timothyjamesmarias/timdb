#ifndef CMD_TREE_H_
#define CMD_TREE_H_

const char ** cmds = ["SHOW", "CREATE", "DELETE", "UPDATE", "INSERT"];
const char ** keywords = ["INTO", "FROM", "WHERE", "VALUES", "SET", "ALL"];
const char ** objects = ["DATABASE", "TABLE", "ROW", "COLUMN"];
const char ** types = ["INT", "FLOAT", "STRING", "TEXT", "BOOL"];
const char * variable = "[VARIABLE]";

typedef struct CmdNode {
    char * cmd;
    struct CmdNode ** children;
};

struct CmdNode * cmd_tree = NULL;

struct CmdNode * new_node();
void free_node(struct CmdNode * node);
void free_tree(struct CmdNode * node);
void print_tree(struct CmdNode * node);

struct CmdNode * build_first_layer();
struct CmdNode * build_tree();

#endif

