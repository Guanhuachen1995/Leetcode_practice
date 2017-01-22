class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret,curmax,currch=0,0,0
        for i in xrange(len(nums)):
            if currch < i:
                ret+=1
                currch=curmax
            curmax=max(curmax, i+nums[i])
        return ret
