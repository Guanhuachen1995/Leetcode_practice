class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        size = len(s)
        max1=0
        start=0
        for i in xrange(size):
            j = i-1;
            k = i+1;
            while j >=0 and k < size and s[j]==s[k]:
                j -= 1
                k += 1
            j += 1
            k -= 1
            if k - j + 1 > max1:
                max1 = k - j + 1
                start = j
        for i in xrange(size):
            j = i;
            k = i+1;
            while j >=0 and k < size and s[j]==s[k]:
                j -= 1
                k += 1
            j += 1
            k -= 1
            if k - j + 1 > max1:
                max1 = k - j + 1
                start = j
        if max > 0:
            return s[start : start + max1]
        return None
        
