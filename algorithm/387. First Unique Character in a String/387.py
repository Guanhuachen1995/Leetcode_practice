class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        map1={}
        for c in s:
            map1[c]=0
        for c in s:
            map1[c]+=1
        for i in range(len(s)):
            if map1[s[i]] ==1:
                return i
        return -1
