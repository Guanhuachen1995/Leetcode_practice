class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if(len(nums)==0):
            return 0
        result=0
        for i in xrange(len(nums)):
            if nums[result]!=nums[i]:
                result+=1
                nums[result]=nums[i]
        return result+1
