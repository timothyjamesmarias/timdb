#include "cmd_tree.h"

struct CmdNode * build_tree() {
  TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
  root->cmd = "root";
}

