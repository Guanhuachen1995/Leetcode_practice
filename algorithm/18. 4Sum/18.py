class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        size=len(nums)
        result=[]
        
        if(size<4):
            return result
        nums.sort()
        for i in xrange(size-3):
            if i>0 and nums[i]==nums[i-1]:
                continue
            for j in range(i+1,size-2):
                if j > i+1  and nums[j]==nums[j-1]:
                    continue
                k=j+1
                l=size-1
                while k<l:
                    if nums[i]+nums[j]+nums[k]+nums[l]==target:
                        result.append([nums[i], nums[j], nums[k],nums[l]])
                        k+=1
                        l-=1
                        while k < l and nums[k] == nums[k -1 ]:
                            k += 1
                        while k < l and nums[l] == nums[l + 1]:
                            l -= 1
                    elif nums[i]+nums[j]+nums[k]+nums[l]<target:
                        k += 1
                    else:
                        l -= 1
        return result
            
