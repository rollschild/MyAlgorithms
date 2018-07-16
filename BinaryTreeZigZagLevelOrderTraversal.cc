/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> values{};
    push(values, root, 0);
    return values;
  }

  void push(vector<vector<int>>& vec, TreeNode* node, int level) {
    if (node == nullptr) return;
    if (vec.size() <= level) {
      vector<int> tmp{};
      vec.push_back(tmp);
    }
    if (level % 2 == 0)
      vec[level].push_back(node->val);
    else
      vec[level].insert(vec[level].begin(), node->val);
    push(vec, node->left, level + 1);
    push(vec, node->right, level + 1);
  }
};
