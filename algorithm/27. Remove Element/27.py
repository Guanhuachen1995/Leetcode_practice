class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        result=0
        for i in xrange(len(nums)):
            if nums[i]!=val:
                nums[result]=nums[i]
                result+=1
        return result
