class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result=[]
        for i in range(0,len(nums)):
            nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1])
        for i in range(0,len(nums)):
        	if nums[i]>0:
        		result.append(i+1)
        return result