class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        index = len(nums)-1
        while index>0 and nums[index]<=nums[index-1]:
            index-=1
        if index==0:
            nums.sort()
            return
        exchange=0
        for i in range(len(nums)-1,index-1,-1):
            if nums[i]>nums[index-1]:
                exchange=i
                break
        tem=nums[index-1]
        nums[index-1]=nums[exchange]
        nums[exchange]=tem
        nums[index:] = nums[:index-1:-1]
        return 
