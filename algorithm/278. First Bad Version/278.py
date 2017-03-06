# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        tem,start,end=0,0,n
        while end-start>1:
            tem=start+(end-start)/2
            if isBadVersion(tem):
                end=tem
            else:
                start=tem
        return end
