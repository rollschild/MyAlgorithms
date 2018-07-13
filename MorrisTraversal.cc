#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val_;
  struct TreeNode* left_;
  struct TreeNode* right_;
  TreeNode(int val) : val_(val), left_(nullptr), right_(nullptr) {}
};

// vector<int> nodes;

vector<int> MorrisTraversal(TreeNode* node) {
  vector<int> nodes;

  if (node == nullptr) {
    return nodes;
  }

  TreeNode* pre = nullptr;
  TreeNode* curr = nullptr;

  curr = node;

  while (curr != nullptr) {
    if (curr->left_ == nullptr) {
      nodes.push_back(curr->val_);
      curr = curr->right_;
    }
    else {
      pre = curr->left_;
      while (pre->right_ != nullptr && pre->right_ != curr) {
        pre = pre->right_;
      }

      if (pre->right_ == nullptr) {
        pre->right_ = curr;
	curr = curr->left_;
      }
      else {
        pre->right_ = nullptr;
	nodes.push_back(curr->val_);
	curr = curr->right_;
      }
    }
  }

  return nodes;
}

void Print(vector<int>& vec) {
  for (auto v : vec) {
    cout << v << " ";
  }
  cout << endl;
  return;
}

int main() {
  TreeNode* root = new TreeNode(1);
  root->left_ = new TreeNode(2);
  root->right_ = new TreeNode(3);
  root->left_->left_ = new TreeNode(4);
  root->left_->right_ = new TreeNode(5);

  vector<int> results = MorrisTraversal(root);

  Print(results);

  return 0;
}
