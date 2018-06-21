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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values{};
        stack<TreeNode*> nodes{};
        TreeNode* current = root;
        while(current != nullptr || !nodes.empty()) {
            while(current != nullptr) {
                nodes.push(current);
                current = current->left;
            }
            current = nodes.top();
            nodes.pop();
            values.push_back(current->val);
            current = current->right;
        }
        return values;
    }
};
