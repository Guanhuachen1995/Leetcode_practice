class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        res=num
        while res*res>num:
            res=(res+num/res)/2
        return res*res==num
