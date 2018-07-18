#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int value;
  struct Node* left;
  struct Node* right;
  Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

vector<int> LevelOrderTraversal(Node* root) {
  vector<int> nodes{};

  if (root == nullptr) return nodes;
  queue<Node*> tree_nodes;
  tree_nodes.push(root);

  while (!tree_nodes.empty()) {
    Node* node = tree_nodes.front();
    tree_nodes.pop();
    nodes.push_back(node->value);

    if (node->left) tree_nodes.push(node->left);
    if (node->right) tree_nodes.push(node->right);
  }

  return nodes;
}

void PrintVec(vector<int>& vec) {
  for (auto v : vec) {
    cout << v << " ";
  }

  cout << endl;
}

int main() {
  Node* root = new Node(12);
  root->left = new Node(3);
  root->right = new Node(6);
  root->left->left = new Node(18);
  root->left->right = new Node(2037);
  root->right->right = new Node(66);
  root->right->right->right = new Node(-12345);
  root->right->right->right->right = new Node(99);
  root->right->right->right->right->right = new Node(-1);

  vector<int> results = LevelOrderTraversal(root);
  PrintVec(results);

  return 0;
}
