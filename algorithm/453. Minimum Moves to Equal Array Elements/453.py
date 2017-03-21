class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return 0
        nums.sort()
        result,min=0,nums[0]
        for i in range(len(nums)):
            result+=nums[i]-min
        return result
