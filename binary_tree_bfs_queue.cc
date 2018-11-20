#include "./binary_tree_bfs_queue.h"

int main() {
  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(6);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->left = new Node(5);
  root->right->right = new Node(7);
  root->right->right->right = new Node(8);

  print_tree(root);

  return 0;
}
