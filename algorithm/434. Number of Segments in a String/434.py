class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        result=0
        s+=" "
        for i in range(1,len(s)):
            if s[i]==" " and s[i-1]!=" ":
                result+=1
        return result
            
