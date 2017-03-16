class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        tem,max=0,0
        for i in range(len(nums)):
            if nums[i]==0:
                if tem>max:
                    max=tem
                tem=0
            else:
                tem+=1
        if tem>max:
            max=tem
        return max
