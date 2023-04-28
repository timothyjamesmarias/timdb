#ifndef CMD_TREE_H_
#define CMD_TREE_H_

const char ** cmds = ["SHOW", "CREATE", "DELETE", "UPDATE", "INSERT"];
const char ** keywords = ["DATABASE", "TABLE", "ROW", "COLUMN"];
const char ** types = ["INT", "FLOAT", "STRING"];

typedef struct CmdNode {
    char * cmd;
    struct CmdNode * opt1;
    struct CmdNode * opt2;
    struct CmdNode * opt3;
    struct CmdNode * opt4;
    struct CmdNode * opt5;
};

struct CmdNode * cmd_tree = NULL;

struct CmdNode * build_tree();

#endif

