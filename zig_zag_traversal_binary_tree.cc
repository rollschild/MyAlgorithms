#include <deque>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int value_;
  Node* left;
  Node* right;

  Node(int val) : value_(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zig_zag(Node* root) {
  vector<vector<int>> nodes{};
  if (root == nullptr) return nodes;
  deque<Node*> deq{};
  deq.push_back(root);
  int level = 0;
  while (!deq.empty()) {
    level = level ^ 1;
    vector<int> row{};
    int size = deq.size();
    while (size--) {
      if (level) {
        // level = 1
        // from right to left I suppose
        Node* node = deq.back();
        row.push_back(node->value_);
        deq.pop_back();
        // size = deq.size();
        if (node->right) deq.push_back(node->right);
        if (node->left) deq.push_back(node->left);
      } else {
        Node* node = deq.front();
        deq.pop_front();
        row.push_back(node->value_);
        if (node->right) deq.push_back(node->right);
        if (node->left) deq.push_back(node->left);
      }
    }

    nodes.push_back(row);
  }

  return nodes;
}

void print_vec(vector<vector<int>>& vec) {
  for (auto outer : vec) {
    for (auto inner : outer) {
      cout << inner << " ";
    }
    cout << endl;
  }
}

int main() {
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  auto vec = zig_zag(root);
  print_vec(vec);

  return 0;
}
