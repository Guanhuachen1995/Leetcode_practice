class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs)==0:
            return ""
        result = strs[0]
        for i in xrange(len(strs)):
            j = 0
            while j < len(result) and j < len(strs[i]):
                if result[j]!=strs[i][j]:
                    break
                j+=1
            result = result[0:j]
        return result
