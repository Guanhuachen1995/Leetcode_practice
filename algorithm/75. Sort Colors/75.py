class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        start=0
        end=len(nums)-1
        i=0
        while i<=end:
            while nums[i]==2 and i<end:
                nums[i],nums[end]=nums[end],nums[i]
                end-=1
            while nums[i]==0 and i>start:
                nums[i],nums[start]=nums[start],nums[i]
                start+=1
            i+=1
