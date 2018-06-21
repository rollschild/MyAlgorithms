# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.nodes = []
    
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return self.nodes
        
        self.inorderTraversal(root.left)
        self.nodes.append(root.val)
        self.inorderTraversal(root.right)
        return self.nodes

