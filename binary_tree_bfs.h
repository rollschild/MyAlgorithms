#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value_;
  struct Node* left;
  struct Node* right;
};

struct Node* new_node(int val) {
  // Notice the grammar here
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->value_ = val;
  node->left = NULL;
  node->right = NULL;

  return node;
};

int height(struct Node* node) {
  if (node == NULL) return -1;

  if (node->left == NULL && node->right == NULL) return 0;

  int left_child_height = height(node->left);
  int right_child_height = height(node->right);

  if (left_child_height >= right_child_height)
    return left_child_height + 1;
  else
    return right_child_height + 1;
};

void print_given_level(struct Node* node, int level) {
  if (node == NULL) return;
  if (level == 0) {
    printf("%d ", node->value_);
  } else {
    print_given_level(node->left, level - 1);
    print_given_level(node->right, level - 1);
  }
};

void print_level_order(struct Node* node) {
  int node_height = height(node);

  for (int i = 0; i <= node_height; ++i) {
    print_given_level(node, i);
  }

  return;
}
