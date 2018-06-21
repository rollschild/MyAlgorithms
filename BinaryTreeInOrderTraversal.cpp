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
    vector<int> nodes;
    void Traverse(TreeNode* node) {
        if (node == nullptr) return;
        Traverse(node->left);
        nodes.push_back(node->val);
        Traverse(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        Traverse(root);
        return nodes;
    }
};
