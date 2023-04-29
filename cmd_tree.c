#include "cmd_tree.h"
#include <stdlib.h>

struct CmdNode * new_node(char * cmd) {
    struct CmdNode * node = malloc(sizeof(struct CmdNode));
    node->cmd = cmd;
    node->children = NULL;
    return node;
}

void free_node(struct CmdNode * node) {
    free(node);
}

struct CmdNode * build_first_layer() {
  struct CmdNode *root = new_node("root");

  size_t i = 0, cmds_length = sizeof(cmds) / sizeof(cmds[0]);
  
  for (i = 0; i < cmds_length; i++) {
    struct CmdNode *node = new_node(cmds[i]);
    node->cmd = cmds[i];
    root->children[i] = node;
  }

  return root;
}

struct CmdNode * build_tree() {
  struct CmdNode *root = build_first_layer();
}

