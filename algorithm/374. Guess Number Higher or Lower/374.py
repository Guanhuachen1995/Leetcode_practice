# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        low,high=1,n
        while True:
            tem=(high-low)/2+low
            k=guess(tem)
            if k==0:
                return tem
            elif k==1:
                low =tem+1
            else:
                high=tem-1
        
