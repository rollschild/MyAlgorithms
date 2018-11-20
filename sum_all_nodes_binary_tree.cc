#include <iostream>

using namespace std;

struct Node {
  int value_;
  Node* left;
  Node* right;

  Node(int val) : value_(val), left(nullptr), right(nullptr) {}
};

int sum(Node* root) {
  if (root == nullptr) return 0;

  return root->value_ + sum(root->left) + sum(root->right);
}

int main() {
  Node* root = new Node(2037);
  root->left = new Node(-1);
  root->right = new Node(66);
  root->left->left = new Node(8);
  root->left->right = new Node(19);
  root->right->left = new Node(1024);
  root->right->right = new Node(42);

  cout << (sum(root) == (2037 - 1 + 66 + 8 + 19 + 1024 + 42) ? "Correct"
                                                             : "Wrong!")
       << endl;

  return 0;
}
