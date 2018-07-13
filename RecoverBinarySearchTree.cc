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
    TreeNode* first_node = nullptr;
    TreeNode* second_node = nullptr;
    TreeNode* prev_node = new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        traversal(root);
        int tmp = first_node->val;
        first_node->val = second_node->val;
        second_node->val = tmp;
    }
    
    void traversal(TreeNode* node) {
        if(node == nullptr) {
            return;
        }
        
        traversal(node->left);
        
        if(first_node == nullptr && prev_node->val >= node->val) {
            first_node = prev_node;
        }
        if(first_node != nullptr && prev_node->val >= node->val) {
            second_node = node;
        }
        prev_node = node;
        
        traversal(node->right);
    }
};
