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
    vector<vector<int>> values;
    if (root == nullptr) return values;
    deque<TreeNode*> deq;
    deq.push_back(root);
    int level = 0;
    while (!deq.empty()) {
      int size = deq.size();
      level = level ^ 1;
      vector<int> row;
      while (size--) {
        if (level) {
          // right to left
          TreeNode* node = deq.front();
          row.push_back(node->val);
          deq.pop_front();
          if (node->left) deq.push_back(node->left);
          if (node->right) deq.push_back(node->right);
        } else {
          // left to right
          TreeNode* node = deq.back();
          row.push_back(node->val);
          deq.pop_back();
          if (node->right) deq.push_front(node->right);
          if (node->left) deq.push_front(node->left);
        }
      }
      values.push_back(row);
    }
    return values;
  }
};
