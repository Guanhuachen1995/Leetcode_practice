# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.val,self.diff=-1,2147483647
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root.left:
            self.getMinimumDifference(root.left)
        if(self.val>=0):
            self.diff=min(self.diff,root.val-self.val)
        self.val=root.val
        if root.right:
            self.getMinimumDifference(root.right)
        return self.diff
