class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num>0:
            while num%16==0:
                num/=16
            while num%4==0:
                num/=4
        return num==1
