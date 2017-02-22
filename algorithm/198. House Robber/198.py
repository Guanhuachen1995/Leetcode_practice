class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        last, now = 0, 0
        for i in range(len(nums)):
            last,now=now,max(now,last+nums[i])
        return now
