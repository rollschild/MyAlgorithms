/*
 * Nov 23, 2018
 * Tree sort..
 */
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;
};

Node* new_node(int val) {
  Node* node = new Node();
  node->value = val;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}

Node* plant(int val, Node* node) {
  if (node == nullptr) {
    node = new_node(val);
    return node;
  } else {
    if (val < node->value)
      node->left = plant(val, node->left);
    else
      node->right = plant(val, node->right);
  }
  return node;
}

void harvest(Node* root, vector<int>& sorted) {
  if (root == nullptr) return;
  harvest(root->left, sorted);
  sorted.push_back(root->value);
  harvest(root->right, sorted);
}

vector<int> tree_sort(vector<int>& arr) {
  vector<int> leaves{};
  if (arr.size() == 0) return leaves;
  Node* seed = nullptr;
  Node* root = plant(arr[0], seed);
  for (int i = 1; i < arr.size(); ++i) {
    plant(arr[i], root);
  }

  harvest(root, leaves);
  return leaves;
}

void print_vec(vector<int>& vec) {
  for (auto v : vec) {
    cout << v << " ";
  }
  cout << endl;
  return;
}

int main() {
  vector<int> arr{2037, -1, 5, 4, 100, 4};
  print_vec(arr);
  auto sorted_arr = tree_sort(arr);
  print_vec(sorted_arr);

  return 0;
}
