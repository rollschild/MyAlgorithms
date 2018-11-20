#include "./binary_tree_bfs.h"

int main() {
  struct Node* root = new_node(4);
  root->left = new_node(2);
  root->right = new_node(6);
  root->left->left = new_node(1);
  root->left->right = new_node(3);
  root->right->left = new_node(5);
  root->right->right = new_node(7);
  root->right->right->right = new_node(8);

  print_level_order(root);

  return 0;
}
