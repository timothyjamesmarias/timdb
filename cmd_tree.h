#ifndef CMD_TREE_H_
#define CMD_TREE_H_

const char ** cmds = ["SHOW", "CREATE", "DELETE", "UPDATE", "INSERT"];
const char ** keywords = ["DATABASE", "TABLE", "ROW", "COLUMN", "INTO"];
const char ** types = ["INT", "FLOAT", "STRING", "TEXT", "BOOL"];

typedef struct CmdNode {
    char * cmd;
    struct CmdNode ** children;
};

struct CmdNode * cmd_tree = NULL;

struct CmdNode * new_node();
void free_node(struct CmdNode * node);

struct CmdNode * build_first_layer();
struct CmdNode * build_tree();


#endif

