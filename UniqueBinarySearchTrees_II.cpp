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
    vector<TreeNode*> generateSubTrees(int left, int right) {
        vector<TreeNode*> trees;
        if (left > right) trees.push_back(nullptr);
        if (left == right) trees.push_back(new TreeNode(left));
        if (left < right) {
            for(int i = left; i <= right; ++i) {
                vector<TreeNode*> left_child = generateSubTrees(left, i - 1);
                vector<TreeNode*> right_child = generateSubTrees(i + 1, right);
                for(auto& left_node : left_child) {
                    for(auto& right_node : right_child) {
                        TreeNode* current = new TreeNode(i);
                        current->left = left_node;
                        current->right = right_node;
                        trees.push_back(current);
                    }
                }
            }
        }
        return trees;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            vector<TreeNode*> zero;
            return zero;
        }
        return generateSubTrees(1, n);
    }
};
