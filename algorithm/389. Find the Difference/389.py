class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        res=0
        for item in s+t:
            res^=ord(item)
        return chr(res)
