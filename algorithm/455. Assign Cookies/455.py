class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        if not g or not s:
            return 0
        g.sort()
        s.sort()
        i,j=0,0
        while i < len(g) and j < len(s):
            if g[i]<=s[j]:
                i+=1
            j+=1
        return i
        
