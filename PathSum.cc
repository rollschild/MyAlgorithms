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
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> results;
    vector<int> tmp;
    traversal(root, sum, results, tmp);
    return results;
  }

  void traversal(TreeNode* root, int sum, vector<vector<int>>& results,
                 vector<int>& tmp) {
    if (root == nullptr) return;

    tmp.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr) {
      if (accumulate(tmp.begin(), tmp.end(), 0) == sum) results.push_back(tmp);
    }

    traversal(root->left, sum, results, tmp);
    traversal(root->right, sum, results, tmp);
    tmp.pop_back();
  }
};
