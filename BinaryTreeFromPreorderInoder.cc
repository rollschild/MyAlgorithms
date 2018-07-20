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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int pre_start = 0;
    int pre_end = preorder.size() - 1;
    int in_start = 0;
    int in_end = inorder.size() - 1;
    return createTree(preorder, inorder, pre_start, pre_end, in_start, in_end);
  }

  TreeNode* createTree(vector<int>& preorder, vector<int>& inorder,
                       int pre_start, int pre_end, int in_start, int in_end) {
    if (pre_start > pre_end) return nullptr;
    TreeNode* root = new TreeNode(preorder[pre_start]);

    int position = 0;
    for (int i = in_start; i <= in_end; ++i) {
      if (inorder[i] == preorder[pre_start]) {
        position = i;
        break;
      }
    }

    root->left =
        createTree(preorder, inorder, pre_start + 1,
                   pre_start + position - in_start, in_start, position - 1);
    root->right =
        createTree(preorder, inorder, pre_start + position - in_start + 1,
                   pre_end, position + 1, in_end);

    return root;
    }
};

