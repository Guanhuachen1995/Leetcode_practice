class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        sss = [""]*numRows
        i=0
        gap = numRows - 2
        while i < len(s):
            for j in xrange(numRows):
                if i >= len(s):
                    break
                sss[j]+=s[i]
                i+=1
            for j in range(gap, 0,-1  ):
                if i >= len(s):
                    break
                sss[j]+=s[i]
                i+=1
        s=""
        for j in xrange(numRows):
            s+=sss[j]
        return s
