class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result=[]
        dic={}
        for i in xrange(len(nums)):
        	if dic.has_key(nums[i]):
        		result.append(dic[nums[i]])
        		result.append(i)
        	else:
        		dic[target - nums[i]]=i
        return result