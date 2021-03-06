# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def helper(nums,start,end):
            if end <= start:
                return None
            mid=(start+end)/2
            root=TreeNode(nums[mid])
            root.left=helper(nums,start,mid)
            root.right=helper(nums,mid+1,end)
            return root
        return helper(nums,0,len(nums))
