class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum1 = nums[0]
        maxsum = sum1
        for i in range(1,len(nums)):
            sum1 = max(nums[i],nums[i]+sum1)
            maxsum = max(sum1, maxsum)
        return maxsum
