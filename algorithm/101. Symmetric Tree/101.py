# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def helper( q,p):
            if not q and not p:
                return True
            elif not q or not p:
                return False
            elif(q.val !=p.val):
                return False
            return helper(q.left,p.right) and helper(q.right,p.left)
        
        if not root:
            return True
        return helper(root.left,root.right)
