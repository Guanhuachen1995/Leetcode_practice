# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def helper(root, map):
            if root:
                m[root.val]=m.get(root.val,0)+1
                helper(root.left,m)
                helper(root.right,m)
        m={}
        helper(root,m)
        if len(m)==0:
            return []
        k=max(m.values())
        return [i for [i,j] in m.items() if j==k]
                
