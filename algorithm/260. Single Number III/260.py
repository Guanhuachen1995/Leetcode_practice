class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        tem=0
        for n in nums:
            tem^=n
        tem=tem&(~(tem-1))
        result=[0,0]
        for n in nums:
            if (tem&n)==0:
                result[0]^=n
            else:
                result[1]^=n
        return result
