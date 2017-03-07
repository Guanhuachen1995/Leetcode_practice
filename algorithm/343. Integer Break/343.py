class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n<4:
            return n-1
        result=1
        while n>4:
            result*=3
            n-=3
        result*=n
        return result
