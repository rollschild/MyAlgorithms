#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* left;
  struct Node* right;
};

struct Node* NewNode(int value);
int Height(struct Node* node);
void PrintLevelOrder(struct Node* node);
void PrintGivenLevel(struct Node* node, int level);

int Height(struct Node* node) {
  if (node == NULL) return 0;
  if (node->left == NULL && node->right == NULL) {
    return 0;
  }

  int left_height = Height(node->left);
  int right_height = Height(node->right);

  if (left_height > right_height)
    return (left_height + 1);
  else
    return (right_height + 1);
}

void PrintLevelOrder(struct Node* node) {
  int height = Height(node);
  for (int i = 0; i <= height; ++i) {
    PrintGivenLevel(node, i);
  }
}

void PrintGivenLevel(struct Node* node, int level) {
  if (node == NULL) return;
  if (level == 0) {
    printf("%d ", node->value);
    return;
  }
  if (level > 0) {
    PrintGivenLevel(node->left, level - 1);
    PrintGivenLevel(node->right, level - 1);
  }
}

struct Node* NewNode(int value) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));

  node->value = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

int main() {
  struct Node* root = NewNode(12);
  root->left = NewNode(3);
  root->right = NewNode(6);
  root->left->right = NewNode(2037);
  root->left->left = NewNode(18);
  root->right->right = NewNode(66);
  root->right->right->right = NewNode(12345);
  root->right->right->right->right = NewNode(-283847757);

  PrintLevelOrder(root);

  return 0;
}
