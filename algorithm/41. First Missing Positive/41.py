class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return 1;
        nums.sort()
        i1=0
        for i in xrange(len(nums)):
            if nums[i]==1:
                i1=1
            if nums[i]>1:
                if i1==0:
                    return 1;
                if i > 0 and nums[i]-nums[i-1]>1:
                    return nums[i-1]+1
        result=nums[len(nums)-1]+1
        return result
