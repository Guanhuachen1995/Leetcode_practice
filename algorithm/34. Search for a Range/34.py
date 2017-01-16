class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result=[]
        start,end=-1,-1
        for i in xrange(len(nums)):
            if nums[i]<target:
                continue
            if nums[i]==target:
                if start==-1:
                    start=i
                end=i
            if nums[i]<target:
                break
        result.append(start)
        result.append(end)
        return result
