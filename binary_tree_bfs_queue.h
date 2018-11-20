#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int value_;
  Node* left;
  Node* right;

  Node(int val) : value_{val}, left{nullptr}, right{nullptr} {}
};

vector<int> level_order_traversal(Node* root) {
  queue<Node*> que{};
  vector<int> nodes{};

  que.push(root);
  while (!que.empty()) {
    Node* node = que.front();
    que.pop();
    nodes.push_back(node->value_);

    if (node->left) que.push(node->left);
    if (node->right) que.push(node->right);
  }

  return nodes;
};

void print_tree(Node* root) {
  vector<int> vec = level_order_traversal(root);
  for (auto v : vec) {
    cout << v << " ";
  }
  cout << endl;

  return;
}
