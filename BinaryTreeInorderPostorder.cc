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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int post_left = 0;
        int post_right = postorder.size() - 1;
        int in_left = 0;
        int in_right = inorder.size() - 1;
        return createTree(inorder, postorder, in_left, in_right, post_left, post_right);
    }
    
    TreeNode* createTree(
        vector<int>& inorder, vector<int>& postorder, int in_left, int in_right, int post_left, int post_right) {
        if (post_left < 0 || post_left > post_right) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[post_right]);
        
        int position = 0;
        for(int i = 0; i <= in_right; ++i) {
            if (inorder[i] == postorder[post_right]) {
                position = i;
                break;
            }
        }
        
        root->right = createTree(
            inorder, postorder, position+1, in_right, post_right-(in_right-position), post_right-1);
        root->left = createTree(inorder, postorder, in_left, position-1, post_left, post_right-(in_right-position)-1);
        return root;
    }
};
